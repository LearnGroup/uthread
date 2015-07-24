#include "Buffer.hpp"

#include <memory>

using namespace std;

namespace uthread
{
Buffer::Buffer(size_t len)
    : len_(len)
{
    data_ = (void*) new char[len];
}

Buffer::Buffer(void* data, size_t len)
    : Buffer(len)
{
    memcpy(data_, data, len);
}

void* Buffer::data()
{
    return data_;
}

size_t Buffer::size() const
{
    return len_;
}

}