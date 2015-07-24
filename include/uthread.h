#ifndef __UTHREAD_INCLUDED__
#define __UTHREAD_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef UTHREAD_STATIC
#   define UTHREAD_EXPORT
#elif defined UTHREAD_DLL_EXPORT
#   define UTHREAD_EXPORT __declspec(dllexport)
#else
#   define UTHREAD_EXPORT __declspec(dllimport)
#endif

/************************************************************************/
/* Global Options                                                       */
/************************************************************************/
#define UTHREAD_BACKEND_THREADS 1

/************************************************************************/
/* Error Codes                                                          */
/************************************************************************/
#define UTHREAD_SUCCESS 0

/************************************************************************/
/* uthread options                                                      */
/************************************************************************/
#define UTHREAD_OPEN_READ 0x1
#define UTHREAD_OPEN_WRITE 0x2

typedef void (thread_fn) (int argc, void** argv);
typedef void* ucontext_t;
typedef void* ufile_t;
typedef void* ubuffer_t;
typedef void* uthread_t;
typedef void** uargv_t;

UTHREAD_EXPORT ucontext_t uthread_ctx_new();
UTHREAD_EXPORT int uthread_ctx_destroy(ucontext_t ctx);
UTHREAD_EXPORT void uthread_ctx_run(ucontext_t ctx);

UTHREAD_EXPORT void *uthread_open(ucontext_t ctx, const char* addr, int mode = UTHREAD_OPEN_READ);
UTHREAD_EXPORT int uthread_close(void *file);

UTHREAD_EXPORT int uthread_read(ufile_t file, ubuffer_t buf);
UTHREAD_EXPORT int uthread_write(ufile_t file, ubuffer_t buf);

UTHREAD_EXPORT uthread_t uthread_fork(ucontext_t ctx, thread_fn *fn, int argc, uargv_t argv);
UTHREAD_EXPORT int uthread_kill(uthread_t* p_uthread);

UTHREAD_EXPORT int uthread_buf_init(ubuffer_t* p_buf);
UTHREAD_EXPORT int uthread_buf_init_size(ubuffer_t* p_buf, size_t len);
UTHREAD_EXPORT int uthread_buf_init_data(ubuffer_t* p_buf, void *data, size_t len);
UTHREAD_EXPORT int uthread_buf_free(ubuffer_t p_buf);

/************************************************************************/
/* Error Code                                                           */
/************************************************************************/
#define UTHREAD_SUCCESS 0

#ifdef __cplusplus
}
#endif

#endif // !__UTHREAD_INCLUDED__
