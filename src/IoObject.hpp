#ifndef __UTHREAD_IO_OBJECT_HPP_INCLUDED__
#define __UTHREAD_IO_OBJECT_HPP_INCLUDED__

#include <Windows.h>

namespace uthread
{

class IoHandle;

/************************************************************************/
/* IoObject is a overlapped object for Windows Platform                 */
/************************************************************************/
struct IoObject
    : public OVERLAPPED
{
    HANDLE hFiber;
};

} // namespace uthread

#endif // !__UTHREAD_IO_OBJECT_HPP_INCLUDED__
