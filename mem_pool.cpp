#include "mem_pool.h"
#include <cstdlib>
#include <iostream>
#include <memory>

mem_pool::mem_pool(std::size_t element_size, std::size_t reserve_count)
{
  cur_free_memory_ = mem_pool_.allocate_new_block(element_size * reserve_count);
  if(cur_free_memory_ != nullptr)
  {
    reserved_count_ = reserve_count;
    element_size_ = element_size;
  }
}

void* mem_pool::get_next_allocated_mem()
{
  if(elements_count_ < reserved_count_)
  {
    return reinterpret_cast<void*>(reinterpret_cast<std::uint8_t*>(cur_free_memory_) + (elements_count_++ * element_size_));
  }
  else
  {
    auto ptr = mem_pool_.allocate_new_block(element_size_ * reserved_count_);
    if(ptr != nullptr)
    {
      elements_count_ = 0;
      cur_free_memory_ = ptr;
      return reinterpret_cast<void*>(reinterpret_cast<std::uint8_t*>(cur_free_memory_) + (elements_count_++ * element_size_));
    }
  }
}
