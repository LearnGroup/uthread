#ifndef __UTHREAD_HELPERS_HPP_INCLUDED__
#define __UTHREAD_HELPERS_HPP_INCLUDED__

#include <Windows.h>

#define c2w(c, s1, w, s2) MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, c, s1, w, s2)

#endif // !__UTHREAD_HELPERS_HPP_INCLUDED__
