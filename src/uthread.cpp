#include "../include/uthread.h"

#include "Buffer.hpp"
#include "Context.hpp"
#include "Helpers.hpp"
#include "IoHandle.hpp"
#include "Thread.hpp"

using namespace uthread;

void *uthread_ctx_new(void)
{
    return new Context();
}

int uthread_ctx_destroy(void* ctx)
{
    return 0;
}

void uthread_ctx_run(void* ctx)
{
    ((Context*) ctx)->run();
}

void *uthread_open(void *ctx, const char* addr, int mode)
{
    return new IoHandle(addr, mode);
}

int uthread_read(void *file, void* buf)
{
    return 0;
}

int uthread_write(void *file, void* buf)
{
    return 0;
}

int uthread_close(void *file)
{
    return 0;
}

uthread_t uthread_fork(ucontext_t ctx, thread_fn *fn, int argc, uargv_t argv)
{
    UThread* pThread = new UThread((Context*) ctx, fn, argc, argv);
    return pThread;
}

int uthread_kill(void** p_uthread)
{
    *p_uthread = nullptr;
    return 0;
}

int uthread_buf_init(void** p_buf)
{
    return 0;
}

int uthread_buf_init_size(void **p_buf, size_t len)
{
    return 0;
}

int uthread_buf_init_data(void **p_buf, void *data, size_t len)
{
    *p_buf = new Buffer(data, len);
    return UTHREAD_SUCCESS;
}

int uthread_buf_free(void** p_buf)
{
    return 0;
}
