#pragma once

#include <cstring>

class mem_pool
{
  public:
    mem_pool(std::size_t element_size, std::size_t reserve_count);
    void* get_next_allocated_mem();

  private:
    void* mem_pool_ = nullptr;
    std::size_t element_size_ = 0;
    std::size_t elements_count_ = 0;
    std::size_t reserved_count_ = 0;
};
