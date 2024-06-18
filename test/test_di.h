#pragma once

#include <io_di.h>
#include <stdint.h>

#define TEST_VALUE 0xEA

class ITest {
public:
  virtual uint8_t getValue() = 0;
};

class TestClass : public ITest {
public:
  uint8_t getValue() {
    return TEST_VALUE;
  }
};

IO_PROVIDE(ITest, TestClass);
