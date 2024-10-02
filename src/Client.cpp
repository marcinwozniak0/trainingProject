#include "Client.hpp"

namespace {
constexpr auto NUM_OF_THREADS = 4u;
} // namespace

Client::Client(ISender& sender) : sender_{sender}
{}

void Client::run()
{
  while (senderThreads_.size() < NUM_OF_THREADS)
  {
    std::thread t{[&sender = sender_](){
      for (int i = 0; i < 10000; ++i)
      {

        sender.send(i);
      }
    }};

    t.detach();

    senderThreads_.push_back(std::move(t));
  }
}