#ifndef __UTHREAD_CONTEXT_HPP_INCLUDED__
#define __UTHREAD_CONTEXT_HPP_INCLUDED__

#include <thread>

#include <Windows.h>

namespace uthread 
{
class UThread;

class Context
{
public:
    friend UThread;
    friend VOID WINAPI main_routine(LPVOID params);

    Context();
    ~Context();

    void run();
    
private:
    LPVOID mainFiber_;
    HANDLE iocp_;
    std::thread* pWorkThread_;
};

} // namespace uthread

#endif // !__UTHREAD_CONTEXT_HPP_INCLUDED__
