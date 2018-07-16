#include <iostream>

namespace art {
    template<class T>
    class allocator {
    public:
        typedef T value_type;
        typedef T *pointer;
        typedef const T *const_pointer;
        typedef T &reference;
        typedef const T &const_reference;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;

        struct rebind {
            typedef allocator<T> other;
        };

        allocator() noexcept {};

        allocator(const allocator &) noexcept {};

        template<class U>
        allocator(const allocator<U> &other) {};

        ~allocator() {}

        pointer address(reference x) const noexcept;

        const_pointer address(const_reference x) const noexcept;

        pointer allocate(size_type n);

        void deallocate(pointer p, size_type n);

        size_type max_size() const noexcept;

        template<class U, class... Args>
        void construct(U *p, Args &&... args);

        void destroy(T *p);
    };

    template< class T1, class T2 >
    bool operator==(const allocator<T1>& lhs, const allocator<T2>& rhs ) {
        return true;
    };

    template <class T1, class OtherAllocator>
    bool operator==(const allocator<T1>& lhs, const OtherAllocator& rhs) {
        return false;
    };

    template <class T1, class T2>
    bool operator!=(const allocator<T1>& lhs, const allocator<T2>& rhs) {
        return !(lhs == rhs);
    };
}