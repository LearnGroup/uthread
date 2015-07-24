#include "../include/uthread.h"
#include "IoHandle.hpp"
#include "Helpers.hpp"

namespace uthread
{

IoHandle::IoHandle(const char* addr, int mode)
{
    WCHAR buf[256];
    c2w(addr, strlen(addr), buf, sizeof(buf) / sizeof(buf[0]));
    if (mode & UTHREAD_OPEN_WRITE) {
        hFile = CreateFile(
            buf, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 
            FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);
    } else {
        // TODO
    }
}


}