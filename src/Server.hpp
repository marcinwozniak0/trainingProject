#pragma once

#include "ThreadSafeQueue.hpp"

class Server {
public:
  Server(ThreadSafeQueue<int>& queue);
  ~Server();

private:
  ThreadSafeQueue<int>& queue_;
};
