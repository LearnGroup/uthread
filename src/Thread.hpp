#ifndef __UTHREAD_THREAD_HPP_INCLUDED__
#define __UTHREAD_THREAD_HPP_INCLUDED__

#include "../include/uthread.h"

namespace uthread
{
class Context;
typedef thread_fn ThreadFunction;

class UThread
{
public:
    UThread(Context* ctx, ThreadFunction* pFunc, int argc, uargv_t argv);
    ~UThread();

    void run();
    void exit();

private:
    Context* ctx_;
    ThreadFunction* pFunc_;
    int argc_;
    uargv_t argv_;

    HANDLE fiber_;
};
}


#endif // !__UTHREAD_THREAD_HPP_INCLUDED__
