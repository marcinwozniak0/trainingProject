#pragma once

#include "ISender.hpp"

#include "ThreadSafeQueue.hpp"

class Sender  : public ISender {
public:
  Sender(ThreadSafeQueue<int>& queue);
  void send(const int number);

private:
  ThreadSafeQueue<int>& queue_;
};
