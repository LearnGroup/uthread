#ifndef __UTHREAD_IO_HANDLE_HPP_INCLUDED__
#define __UTHREAD_IO_HANDLE_HPP_INCLUDED__

#include <Windows.h>

namespace uthread
{

/************************************************************************/
/* IoHandle is abstract for a handle of an io, used by IoObject         */
/************************************************************************/
class IoHandle
{
public:
    IoHandle(const char* addr, int mode);
    ~IoHandle();

private:
    HANDLE hFile;
};

}

#endif // !__UTHREAD_IO_HANDLE_HPP_INCLUDED__
