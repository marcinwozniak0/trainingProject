#include "Sender.hpp"

Sender::Sender(ThreadSafeQueue<int>& queue) : queue_{queue}
{}

void Sender::send(const int number)
{
  queue_.push(number);
}
