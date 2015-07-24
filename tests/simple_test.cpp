#include <iostream>
#include <string>

#include <boost/lexical_cast.hpp>

#include <uthread.h>

using namespace std;

void *ctx = uthread_ctx_new();

void thread_func(int argc, uargv_t argv)
{
    if (argc != 1) {
        return;
    }

    //int i = 10;
    //void *buf;
    //void *file = uthread_open(ctx, (char*) argv[0], UTHREAD_OPEN_WRITE);
    //while (i--) {
    //    string s = boost::lexical_cast<string>(i);
    //    uthread_buf_init_data(&buf, (void*) s.data(), s.length());
    //    uthread_write(file, buf);
    //}
    //uthread_close(file);

    cout << "in func" << endl;
}

int main(int argc, char** argv)
{
    void* ctx = uthread_ctx_new();

    char path[] = "test.txt";

    uthread_fork(ctx, &thread_func, 1, (void**)&path);

    uthread_ctx_run(ctx);
}