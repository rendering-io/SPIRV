#include <gtest/gtest.h>
#include <SPIRV/SPIRV.h>

using namespace spirv;

TEST(Module, Create) {
  auto M = Module::Create();
  ASSERT_TRUE(M != nullptr);
}

TEST(Module, getOrAddFunction_ValidName_ReturnsNewFunction) {
  auto M = Module::Create();
  auto* F = M->getOrAddFunction("f");
  ASSERT_TRUE(F != nullptr);
}

TEST(Module, getOrAddFunction_NullName_ReturnsNull) {
  auto M = Module::Create();
  auto* F = M->getOrAddFunction(nullptr);
  ASSERT_TRUE(F == nullptr);
}

TEST(Module, getOrAddFunction_EmptyName_ReturnsNull) {
  auto M = Module::Create();
  auto* F = M->getOrAddFunction("");
  ASSERT_TRUE(F == nullptr);
}

TEST(Module, getOrAddFunction_WhitespaceName_ReturnsNull) {
  auto M = Module::Create();
  auto* F = M->getOrAddFunction(" ");
  ASSERT_TRUE(F == nullptr);
}
