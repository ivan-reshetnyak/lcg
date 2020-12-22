#include <cstdlib>

#include <vector>

#include <CppUnitTest.h>

#include "lcg.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test {

TEST_CLASS(test_lcg) {
  TEST_METHOD(TestConstructor) {
    try {
      lcg Generator(1221324ll, 21512521ll, 1242142ll, 65764543ll);
    } catch (std::exception) {
      Assert::Fail();
    }
  }

  TEST_METHOD(TestCompareSTDLIB) {
    unsigned Seed = 12412421ll;
    lcg Generator(Seed, 1ll << 32, 214013, 2531011);
    srand(Seed);
    std::vector<long long> Gen1, Gen2;
    for (int i = 0, Size = 50; i < Size; ++i) {
      Gen1.push_back(rand());
      Gen2.push_back((Generator.Next() >> 16) & 0x7FFF);
    }
    Assert::IsTrue(Gen1 == Gen2);
  }
};

} // End of 'test' namespace
