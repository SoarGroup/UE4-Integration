/* Soar_Kernel.h
 *
 * Author : Mitchell Keith Bloch, Soar Group at U-M
 * Date   : June/July 2008
 *
 * Simple RAII-pattern 'sml::Kernel *' wrapper
 */

#ifndef SOAR_KERNEL_H
#define SOAR_KERNEL_H

// Generally only need this one header file
#include "sml_Client.h"

#include <iostream>
#include <memory>

/** This class can be used transparently as a sml::Kernel object,
  * with the added benefit that it will self destruct when it 
  * goes out of scope.
  */
class Soar_Kernel {
  /// Disabled (No Implementation)
  Soar_Kernel(const Soar_Kernel &);
  Soar_Kernel & operator=(const Soar_Kernel &);

  /// Create a kernel; sml::Kernel::CreateRemoteConnection() can be useful for debugging
  Soar_Kernel(sml::Kernel * const &new_kernel)
    : m_kernel_ptr(new_kernel)
  {
    if(!m_kernel_ptr)
      abort();

    // Check that nothing went wrong. We will always get back a kernel object
    // even if something went wrong and we have to abort.
    if(m_kernel_ptr->HadError()) {
      std::cerr << m_kernel_ptr->GetLastErrorDescription() << std::endl;
      abort();
    }

    m_kernel_ptr->SetAutoCommit(false);
  }

public:
  typedef std::shared_ptr<Soar_Kernel> Pointer;
  typedef std::shared_ptr<const Soar_Kernel> Pointer_C;
  typedef std::weak_ptr<Soar_Kernel> Pointer_W;
  typedef std::weak_ptr<const Soar_Kernel> Pointer_WC;

  static Pointer Create(sml::Kernel * const &new_kernel = sml::Kernel::CreateKernelInNewThread(true)) {
    return Pointer(new Soar_Kernel(new_kernel));
  }

  ~Soar_Kernel() {
    // Shutdown and clean up
    m_kernel_ptr->Shutdown(); // Deletes all agents (unless using a remote connection)
    delete m_kernel_ptr; // Deletes the kernel itself
  }

  const sml::Kernel & operator*() const  {return *m_kernel_ptr;}
  sml::Kernel & operator*()              {return *m_kernel_ptr;}
  const sml::Kernel * operator->() const {return  m_kernel_ptr;}
  sml::Kernel * operator->()             {return  m_kernel_ptr;}

  operator const sml::Kernel & () const {return *m_kernel_ptr;}
  operator sml::Kernel & ()             {return *m_kernel_ptr;}
  operator const sml::Kernel * () const {return  m_kernel_ptr;}
  operator sml::Kernel * const & ()     {return  m_kernel_ptr;}

private:
  sml::Kernel * const m_kernel_ptr;
};

#endif
