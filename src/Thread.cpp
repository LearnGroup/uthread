#include "Context.hpp"
#include "Thread.hpp"
#include "IoObject.hpp"

#include <iostream>

#include <Windows.h>

using namespace std;

namespace uthread
{
VOID WINAPI thread_routine(LPVOID params)
{
    UThread* pThread = (UThread*) params;
    pThread->run();
    pThread->exit();
}

UThread::UThread(Context* ctx, ThreadFunction* pFunc, int argc, uargv_t argv)
    : ctx_(ctx), pFunc_(pFunc), argc_(argc), argv_(argv)
{
    fiber_ = CreateFiber(0, &thread_routine, this);
    IoObject* pObj = new IoObject();
    memset(pObj, 0, sizeof(IoObject));
    pObj->hFiber = fiber_;
    PostQueuedCompletionStatus(ctx_->iocp_, 0, 0, pObj);
}

UThread::~UThread()
{
}

void UThread::run()
{
    pFunc_(argc_, argv_);
}

void UThread::exit()
{
    cout << "exit" << endl;
    SwitchToFiber(ctx_->mainFiber_);
}
}