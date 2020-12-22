#include <cstdlib>

#include <CppUnitTest.h>

#include "lcg.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test {

TEST_CLASS(test_lcg) {
  TEST_METHOD(TestConstructor) {
    try {
      lcg Generator(1221324ll, 21512521ll, 1242142ll);
    } catch (std::exception) {
      Assert::Fail();
    }
  }
};

} // End of 'test' namespace
