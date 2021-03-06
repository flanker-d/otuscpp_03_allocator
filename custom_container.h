#pragma once

#include <iostream>

template <typename T>
struct element
{
  public:
    T data;
    element *next = nullptr;
};

template <typename T, typename A = std::allocator<element<T>>>
class custom_container
{
  using iterator = element<T>*;

  public:
    ~custom_container()
    {
      element<T>* ptr = head_;
      while(ptr != nullptr)
      {
        element<T>* ptr_to_del = ptr;
        ptr = ptr->next;
        allocator_.deallocate(ptr_to_del, 1);
      }
    }

    void push_back(const T& data)
    {
      auto p = allocator_.allocate(1);
      if(p != nullptr)
      {
        allocator_.construct(p);
        if(count_ > 0)
        {
          tail_->next = p;
          tail_ = p;
          p->data = data;
          count_++;
        }
        else
        {
          head_ = p;
          tail_ = p;
          p->next = nullptr;
          p->data = data;
          count_++;
        }
      }
    }

    iterator begin()
    {
      return head_;
    }

    iterator end()
    {
      return head_ + count_;
    }

  private:
    A allocator_;
    std::size_t count_ = 0;
    element<T>* head_ = nullptr;
    element<T>* tail_ = nullptr;
};
