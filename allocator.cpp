#include "allocator.h"
#include <limits>

namespace art{
    template<class T>
    T* allocator<T>::address(reference x) const noexcept{
        return &x;
    }

    template<class T>
    const T* allocator<T>::address(const_reference x) const noexcept{
        return &x;
    }

    template<class T>
    T* allocator<T>::allocate( size_type n){
        return (pointer)(::operator new(n * sizeof(T)));
    }

    template<class T>
    void allocator<T>::deallocate(pointer p, size_type n){
        ::operator delete((void *) p);
    }

    template<class T>
    std::size_t allocator<T>::max_size() const noexcept{
        return std::numeric_limits<std::size_t>::max() / sizeof(T);
    }

    template< class T >
    void allocator<T>::destroy( T* p ){
        p->~T();
    }

    template< class T >
    template< class U, class... Args >
    void allocator<T>::construct(U *p, Args &&... args) {
        ::new((void *)p) U(std::forward<Args>(args)...);
    };

}