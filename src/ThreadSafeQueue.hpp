#pragma once

#include <optional>
#include <queue>

//TODO prepare thread safe implementation
template <typename T>
class ThreadSafeQueue {
public:
  T get()
  {
    if (not queue_.empty())
    {
      const T val = queue_.front();
      queue_.pop();

      return val;
    }

    return std::nullopt;
  }

  void push(const T& elem)
  {
    queue_.push(elem);
  }

  size_t size()
  {
    return queue_.size();
  }

private:
  std::queue<T> queue_{};
};