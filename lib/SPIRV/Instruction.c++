#include <SPIRV/SPIRV.h>
#include <vector>

using namespace spirv;

struct Instruction::Impl {
  std::vector<Capability> Capabilities;
};

Instruction::~Instruction() {

}
