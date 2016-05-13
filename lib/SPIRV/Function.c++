#include <SPIRV/SPIRV.h>

using namespace spirv;

struct Function::Impl {
  std::string Name;
  Module* Parent;
};

std::unique_ptr<Function> Function::Create(const char* Name, Module* M) {
  return std::unique_ptr<Function>{new Function{Name, M}};
}

Function::Function(const char* Name, Module* M)
: PImpl{new Impl}
{
  PImpl->Name = Name ? Name : "";
  PImpl->Parent = M;
}

Function::~Function() {

}

const char* Function::getName() const {
  return PImpl->Name.c_str();
}
