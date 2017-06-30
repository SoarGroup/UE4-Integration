/* Soar_Agent.h
 *
 * Author : Mitchell Keith Bloch, Soar Group at U-M
 * Date   : June/July 2008
 *
 * Simple RAII-pattern 'sml::Agent *' wrapper
 */

#ifndef SOAR_AGENT_H
#define SOAR_AGENT_H

#include "Soar_Kernel.h"

#include <string>

/** This class can be used transparently as a sml::Agent object,
  * with the added benefit that it will self destruct when it 
  * goes out of scope.
  */
class Soar_Agent {
  /// Disabled (No Implementation)
  Soar_Agent(const Soar_Agent &);
  Soar_Agent & operator=(const Soar_Agent &);

  Soar_Agent(const Soar_Kernel::Pointer &kernel,
             const std::string &name)
    // Create an arbitrarily named Soar agent
    : m_kernel_ptr(kernel),
    m_agent_ptr((*kernel)->CreateAgent(name.c_str()))
  {
    // Check that nothing went wrong
    // NOTE: No agent gets created if there's a problem, so we have to check for
    // errors through the kernel object.
    if(!m_agent_ptr || (*kernel)->HadError()) {
      std::cerr << (*kernel)->GetLastErrorDescription() << std::endl;
      abort();
    }
  }

public:
  typedef std::shared_ptr<Soar_Agent> Pointer;
  typedef std::shared_ptr<const Soar_Agent> Pointer_C;
  typedef std::weak_ptr<Soar_Agent> Pointer_W;
  typedef std::weak_ptr<const Soar_Agent> Pointer_WC;

  static Pointer Create(const Soar_Kernel::Pointer &kernel,
                        const std::string &name)
  {
    return Pointer(new Soar_Agent(kernel, name));
  }

  ~Soar_Agent() {
    (*m_kernel_ptr)->DestroyAgent(m_agent_ptr);
  }

  const sml::Agent & operator*() const  {return *m_agent_ptr;}
  sml::Agent & operator*()              {return *m_agent_ptr;}
  const sml::Agent * operator->() const {return  m_agent_ptr;}
  sml::Agent * operator->()             {return  m_agent_ptr;}

  operator const sml::Agent & () const {return *m_agent_ptr;}
  operator sml::Agent & ()             {return *m_agent_ptr;}
  operator const sml::Agent * () const {return  m_agent_ptr;}
  operator sml::Agent * const & ()     {return  m_agent_ptr;}

  Soar_Kernel::Pointer_C get_kernel() const {return m_kernel_ptr;}
  Soar_Kernel::Pointer const & get_kernel() {return m_kernel_ptr;}
  
  void LoadProductions(const std::string &productions) {
    // Load the TOH productions
    if(!m_agent_ptr->LoadProductions(productions.c_str())) {
      std::cerr << "Soar_Agent::LoadProductions(" << productions << ")->Failed" << std::endl;
      abort();
    }
    if(m_agent_ptr->HadError()) {
      std::cerr << "Soar_Agent::LoadProductions->HadError" << std::endl
        << m_agent_ptr->GetLastErrorDescription() << std::endl;
      abort();
    }
  }

private:
  const Soar_Kernel::Pointer m_kernel_ptr;
  sml::Agent * const m_agent_ptr;
};

#endif
