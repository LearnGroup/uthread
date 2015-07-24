#ifndef __UTHREAD_BUFFER_HPP_INCLUDED__
#define __UTHREAD_BUFFER_HPP_INCLUDED__

namespace uthread
{
class Buffer
{
public:
    Buffer(size_t len);
    Buffer(void* data, size_t len);

    void* data();
    size_t size() const;

private:
    void* data_;
    size_t len_;
};
}

#endif // !__UTHREAD_BUFFER_HPP_INCLUDED__
