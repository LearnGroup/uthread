#include "Context.hpp"
#include "IoObject.hpp"

#include <iostream>
#include <thread>

using namespace std;

namespace uthread
{

VOID WINAPI main_routine(LPVOID params)
{
    Context* pCtx = (Context*) params;
    DWORD numOfBytes;
    ULONG_PTR completionKey;
    IoObject* pObj;
    while (true)
    {
        GetQueuedCompletionStatus(pCtx->iocp_, &numOfBytes, &completionKey, (LPOVERLAPPED*) &pObj, INFINITE);
        cout << "go to fiber" << endl;
        SwitchToFiber(pObj->hFiber);
        cout << "go back" << endl;
    }
}

Context::Context()
{
    mainFiber_ = CreateFiber(0, &main_routine, this);
    iocp_ = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 1);
}

Context::~Context()
{
    CloseHandle(iocp_);
}

void Context::run()
{
    pWorkThread_ = new std::thread([this]()
    {
        ConvertThreadToFiber(NULL);
        SwitchToFiber(mainFiber_);
    });
    pWorkThread_->join();
}
}