#pragma once

#include <vector>
#include <thread>

#include "ISender.hpp"

class Client {
public:
  Client(ISender& sender);

  void run();

private:
  ISender& sender_;
  std::vector<std::thread> senderThreads_{};
};
