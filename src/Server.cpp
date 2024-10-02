#include "Server.hpp"

#include <iostream>

Server::Server(ThreadSafeQueue<int>& queue) : queue_{queue}
{}

Server::~Server()
{
  std::cout << "queue size = " << queue_.size() << std::endl;
}