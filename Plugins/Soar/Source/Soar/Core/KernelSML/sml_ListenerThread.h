/////////////////////////////////////////////////////////////////
// ListenerThread class
//
// Author: Douglas Pearson, www.threepenny.net
// Date  : October 2004
//
// Listens for incoming remote connections and creates
// a new connection object for each one.
//
/////////////////////////////////////////////////////////////////

#ifndef LISTENER_THREAD_H
#define LISTENER_THREAD_H

#include "thread_Thread.h"
#include "sock_DataSender.h"
#include "sock_ListenerSocket.h"
#include "sock_SocketLib.h"
#include "sml_Connection.h"

#ifdef ENABLE_NAMED_PIPES
#include "sock_ListenerNamedPipe.h"
#endif

#include <list>

namespace sml
{

// Forward declarations
    class ConnectionManager ;
    class KernelSML ;
    
// A listener socket wrapped in a thread
    class ListenerThread : public soar_thread::Thread
    {
        protected:
            int                         m_Port ;
            ConnectionManager*          m_Parent ;
            sock::ListenerSocket        m_ListenerSocket ;
            sock::ListenerSocket        m_LocalListenerSocket;
#ifdef ENABLE_NAMED_PIPES
            sock::ListenerNamedPipe     m_ListenerNamedPipe ;
#endif
            
            sml::KernelSML*             m_pKernel;
            
            void Run() ;
            
            void CreateConnection(sock::DataSender* pSender);
            
        public:
            ListenerThread(ConnectionManager* parent, int port, KernelSML* pKernel)
            {
                m_Parent = parent ;
                m_Port = port ;
                m_pKernel = pKernel;
            }
            
            int GetPort()
            {
                return m_Port;
            }
    } ;
    
    
} // Namespace

#endif  // LISTENER_THREAD_H
