#include "mem_pool.h"
#include <cstdlib>

mem_pool::mem_pool(std::size_t element_size, std::size_t reserve_count)
{
  mem_pool_ = std::malloc(element_size * reserve_count);
  if(mem_pool_ != nullptr)
  {
    reserved_count_ = reserve_count;
    element_size_ = element_size;
  }
}

void*mem_pool::get_next_allocated_mem()
{
  if(elements_count_ < reserved_count_)
  {
    return mem_pool_ + (elements_count_++ * element_size_);
  }
  else
  {
    void *ptr = std::malloc(element_size_ * reserved_count_ * 2);
    if(ptr != nullptr)
    {
      std::memmove(ptr, mem_pool_, element_size_ * reserved_count_);
      reserved_count_ *= 2;
      //std::free(mem_pool_);
      mem_pool_ = ptr;
      return mem_pool_ + (elements_count_++ * element_size_);
    }
  }
}
