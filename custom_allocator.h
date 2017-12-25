#pragma once

#include <iostream>
#include "mem_pool.h"

template <typename T>
class custom_allocator
{
  public:
    using value_type = T ;

    custom_allocator()
      : mem_pool_(sizeof(T), 10)
    {
    }

    T* allocate(std::size_t n)
    {
      //std::cout << "allocate " << n << std::endl;
      //auto p = std::malloc(n * sizeof(T));
      auto p = mem_pool_.get_next_allocated_mem();
      if(!p)
        throw std::bad_alloc();
      return reinterpret_cast<T *>(p);
    }

    void deallocate(T* p, std::size_t n)
    {
      //std::cout << "deallocate " << n << std::endl;
//      if(p != nullptr)
//      {
//      }
    }

    template<typename U, typename ...Args>
    void construct(U* p, Args&& ...args)
    {
      //std::cout << "construct" << std::endl;
      ::new((void *)p) U(std::forward<Args>(args)...);
    }

    template<typename U>
    void destroy(U* p)
    {
      //std::cout << "destroy" << std::endl;
      p->~U();
    }

  private:
    mem_pool mem_pool_;
};
