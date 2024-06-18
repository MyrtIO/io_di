#include <unity.h>
#include "test_di.h"

IO_PROVIDE_INSTANCE(ITest, TestClass);

void test_Inject(void) {
  ITest* test = IO_INJECT(ITest);
  TEST_ASSERT_EQUAL(TEST_VALUE, test->getValue());
}

int runUnityTests(void) {
  UNITY_BEGIN();
  RUN_TEST(test_Inject);
  return UNITY_END();
}

int main() {
  runUnityTests();
  return 0;
}

