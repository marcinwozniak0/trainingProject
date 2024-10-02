#pragma once

class ISender
{
public:
  virtual void send(const int number) = 0;

  virtual ~ISender() = default;
};