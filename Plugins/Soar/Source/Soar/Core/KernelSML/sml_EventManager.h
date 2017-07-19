/////////////////////////////////////////////////////////////////
// EventManager class file.
//
// Author: Douglas Pearson, www.threepenny.net
// Date  : October 2004
//
// This class manages a list of connections which are interested
// in being notified when a particular event occurs in the kernel.
//
/////////////////////////////////////////////////////////////////

#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "sml_Events.h" // smlEVENT_LAST
#include "sml_Connection.h"
#include "ElementXML.h"
#include "sml_KernelCallback.h"

#include <list>
#include <map>

#include <assert.h>

namespace sml
{

    class KernelSML ;
    
// The list of connections interested in an event
    typedef std::list< Connection* >        ConnectionList ;
    typedef ConnectionList::iterator    ConnectionListIter ;
    
// This avoids having to use AgentSML in this file, which is a necessary hack because including
// sml_AgentSML.h currently breaks things.
    void flushPrintOnAgent(AgentSML* pFlushPrintOnThisAgent);
    
    template<typename EventType> class EventManager : public KernelCallback
    {
        protected:
            ConnectionList* GetListeners(EventType eventID)
            {
                EventMapIter mapIter = m_EventMap.find(eventID) ;
                
                if (mapIter == m_EventMap.end())
                {
                    return NULL ;
                }
                
                return mapIter->second ;
            }
            
        public:
            // Mapping from the event to the list of connections listening to that event
            typedef std::map< EventType, ConnectionList* >      EventMap ;
            typedef typename EventMap::iterator                 EventMapIter ;
            
            typedef std::map< EventType, KernelCallback* >      KernelEventMap ;
            typedef typename KernelEventMap::iterator           KernelEventMapIter ;
            
        protected:
            // Map from event id to list of connections listening to that event
            EventMap        m_EventMap ;
            
        public:
            virtual ~EventManager()
            {
                // This is interesting.  We can't call clear in the destructor for the event manager because it
                // calls virtual methods, which is apparently illegal (I get a "pure virtual method" error from Visual Studio).
                // So we'll need to either move this to the derived classes destructors or call it explicitly before we destroy the manager.
                // Clear() ;
            }
            
            // Clear the map and release all listeners
            virtual void Clear()
            {
                for (EventMapIter mapIter = m_EventMap.begin() ; mapIter != m_EventMap.end() ; mapIter++)
                {
                    EventType eventID = mapIter->first ;
                    ConnectionList* pList = mapIter->second ;
                    
                    // Can't walk through with a normal iterator because we're deleting
                    // the items from the list as we go.  We do all this so that ultimately
                    // the listener into the kernel will be removed (if RemoveListener for the specific
                    // event class wishes to do so).
                    while (pList->size() > 0)
                    {
                        Connection* pConnection = pList->front() ;
                        RemoveListener(eventID, pConnection) ;
                    }
                    
                    delete pList ;
                }
                
                m_EventMap.clear() ;
            }
            
            // Returns true if this is the first connection listening for this event
            virtual bool BaseAddListener(EventType eventID, Connection* pConnection)
            {
                EventMapIter mapIter = m_EventMap.find(eventID) ;
                
                ConnectionList* pList = NULL ;
                
                // Either create a new list or retrieve the existing list of listeners
                if (mapIter == m_EventMap.end())
                {
                    pList = new ConnectionList() ;
                    m_EventMap[eventID] = pList ;
                }
                else
                {
                    pList = mapIter->second ;
                }
                
                pList->push_back(pConnection) ;
                
                // Return true if this is the first listener for this event
                return (pList->size() == 1) ;
            }
            
            // Returns true if this is the first connection listening for this event
            virtual bool BaseAddKernelListener(EventType eventID, KernelCallback* pKernelCallback)
            {
                pKernelCallback->RegisterWithKernel(eventID) ;
                return true ;
            }
            
            // Returns true if this is the first connection listening for this event
            // (Generally calls BaseAddListener and then registers with the kernel for this event)
            virtual bool AddListener(EventType eventID, Connection* pConnection) = 0 ;
            
            // Returns true if just removed the last listener
            virtual bool BaseRemoveListener(EventType eventID, Connection* pConnection)
            {
                ConnectionList* pList = GetListeners(eventID) ;
                
                // We have no record of anyone listening for this event
                // That's not an error -- it's OK to call this for all events in turn
                // to make sure a connection is removed completely.
                if (pList == NULL || pList->size() == 0)
                {
                    return false ;
                }
                
                pList->remove(pConnection) ;
                
                // Return true if the list is now empty
                return pList->empty() ;
            }
            
            // Returns true if just removed the last listener
            // (Generally calls BaseRemoveListener and then unregisters with the kernel for this event)
            virtual bool RemoveListener(EventType eventID, Connection* pConnection) = 0 ;
            
            // Remove all listeners that this connection has
            virtual void RemoveAllListeners(Connection* pConnection)
            {
                // Remove any listeners for this connection
                // We do this for all possible events even though only some will
                // be valid for this particular event manager.
                // We could make this more efficient by defining the set for each handler
                // but the cost of removing all should be minimal as this is a rare event.
                for (int i = 1 ; i < smlEVENT_LAST ; i++)
                {
                    EventType id = (EventType)i ;
                    RemoveListener(id, pConnection) ;
                }
            }
            
            virtual bool HasEvents(EventType eventID)
            {
                return GetListeners(eventID) ? true : false;
            }
            
            virtual bool GetBegin(EventType eventID, ConnectionListIter* pBegin)
            {
                ConnectionList* pList = GetListeners(eventID) ;
                
                // If nobody is listening return false.
                if (!pList || pList->size() == 0)
                {
                    return false ;
                }
                
                *pBegin = pList->begin() ;
                return true ;
            }
            
            virtual ConnectionListIter  GetEnd(EventType eventID)
            {
                ConnectionList* pList = GetListeners(eventID) ;
                
                // Should call GetBegin() first to check that there is a list and
                // only then call GetEnd().  This is a bit clumsy.
                assert(pList && pList->size() != 0) ;
                
                return pList->end() ;
            }
            
            // pCallbackAgent == 0 means that the event calling this does not want the print event to be flushed
            virtual void SendEvent(AgentSML* pFlushPrintOnThisAgent, Connection* pConnection, soarxml::ElementXML* pMsg, AnalyzeXML* pResponse, ConnectionListIter begin, ConnectionListIter end)
            {
#ifdef _DEBUG
                // Generate a text form of the XML so we can look at it in the debugger.
                char* pStr = pMsg->GenerateXMLString(true) ;
#endif
                
                // unless we ARE the print event:
                // must flush all print callbacks before pasing control to client in case
                // handlers are expecting their text to be up to date (See bug 1100)
                // this avoids using AgentSML in this file
                flushPrintOnAgent(pFlushPrintOnThisAgent);
                
                ConnectionListIter connectionIter = begin ;
                
                while (connectionIter != end)
                {
                    pConnection = *connectionIter ;
                    connectionIter++ ;
                    
                    // It would be faster to just send a message here without waiting for a response
                    // but that could produce incorrect behavior if the client expects to act *during*
                    // the event that we're notifying them about (e.g. notification that we're in the input phase).
                    pConnection->SendMessageGetResponse(pResponse, pMsg) ;
                }
                
#ifdef _DEBUG
                // Clean up the string form of the message.
                pMsg->DeleteString(pStr) ;
#endif
            }
    } ;
    
} // End of namespace

#endif  // End of header ifdef
