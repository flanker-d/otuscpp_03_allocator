#pragma once

#include <cstring>
#include <list>
#include <memory>

struct mem_block
{
  std::unique_ptr<std::uint8_t[]> data;
  mem_block *next = nullptr;
};

class mem_block_list
{
  public:
    ~mem_block_list()
    {
      mem_block* ptr = tail_;
      while(ptr != nullptr)
      {
        mem_block* ptr_to_del = ptr;
        ptr = ptr->next;
        ptr_to_del->data.reset(nullptr);
        delete ptr_to_del;
      }
    }

    void* allocate_new_block(std::size_t size)
    {
      mem_block* p = (mem_block*) std::malloc(sizeof(mem_block));
      if(p != nullptr)
      {
        if(count_ > 0)
        {
          head_->next = p;
          head_ = p;
          p->data = std::make_unique<std::uint8_t[]>(size);
          count_++;
          return (void*) p->data.get();
        }
        else
        {
          tail_ = p;
          head_ = p;
          p->next = nullptr;
          p->data = std::make_unique<std::uint8_t[]>(size);
          count_++;
          return (void*) p->data.get();
        }
      }
    }

    std::size_t blocks_count() const
    {
      return count_;
    }

  private:
    std::size_t count_ = 0;
    mem_block* tail_ = nullptr;
    mem_block* head_ = nullptr;
};

class mem_pool
{
  public:
    mem_pool(std::size_t element_size, std::size_t reserve_count);
    void* get_next_allocated_mem();

  private:
    mem_block_list mem_pool_;
    void* cur_free_memory_ = nullptr;
    std::size_t element_size_ = 0;
    std::size_t elements_count_ = 0;
    std::size_t reserved_count_ = 0;
};
