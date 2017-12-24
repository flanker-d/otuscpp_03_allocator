#pragma once

#include <iostream>

template <class T>
class custom_allocator
{
public:
  using value_type = T ;

  T* allocate(std::size_t n)
  {
    std::cout << "allocate " << n << std::endl;
    auto p = std::malloc(n * sizeof(T));
    if(!p)
      throw std::bad_alloc();
    return reinterpret_cast<T *>(p);
  }

  void deallocate(T* p, std::size_t n)
  {
    std::cout << "deallocate " << n << std::endl;
    std::free(p);
  }

  template<typename U, typename ...Args>
  void construct(U* p, Args&& ...args)
  {
    std::cout << "construct" << std::endl;
    ::new((void *)p) U(std::forward<Args>(args)...);
  }

  template<typename U>
  void destroy(U* p)
  {
    std::cout << "destroy" << std::endl;
    p->~U();
  }
};
