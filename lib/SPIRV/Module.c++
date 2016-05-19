#include <SPIRV/SPIRV.h>
#include <cassert>
#include <cstring>
#include <list>

using namespace spirv;

namespace {
const char* ValidSymbolChars = "abcdefghijklmnopqrstuvwxyz"
                               "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

bool isValidFunctionName(const char* Name) {
  if (nullptr == Name || 0 == std::strlen(Name))
    return false;

  std::string NameStr{Name};
  std::size_t found = NameStr.find_first_not_of(ValidSymbolChars);
  if (found != std::string::npos)
    return false;
  
  return true;
}
}

class InstructionRange {
public:
  using Iterator = std::list<std::unique_ptr<Instruction>>::iterator;
  Iterator begin();
  Iterator end();
};

struct Module::Impl {
  std::list<std::unique_ptr<Function>> Functions;
  std::string Name;
  std::list<std::unique_ptr<Instruction>> Instructions;
};

std::unique_ptr<Module> Module::Create(const char* Name) {
  return std::unique_ptr<Module>{new Module(Name)};
}

Module::Module(const char* Name)
: PImpl{new Impl}
{
  PImpl->Name = Name ? Name : "";
}

Module::~Module() {

}

Function* Module::getOrAddFunction(const char* Name) {
  if (!isValidFunctionName(Name))
    return nullptr;

  // Search for an existing function with the same name.
  for (auto& F : PImpl->Functions) {
    if (0 == std::strcmp(F->getName(), Name))
      return F.get();
  }

  // The name is valid, but we didn't find a matching function, so we need to 
  // create one.
  auto F = Function::Create(Name, this);
  auto* Res = F.get();
  PImpl->Functions.push_back(std::move(F));
  return Res;
}

  Instruction *Module::getTypeVoid(){ assert(false); return nullptr; }
  Instruction *Module::getTypeBool(){ assert(false); return nullptr; }
  Instruction *Module::getTypeInt(size_t Width, bool IsSigned){ assert(false); return nullptr; }
  Instruction *Module::getTypeFloat(size_t Width){ assert(false); return nullptr; }
  Instruction *Module::getTypeVector(Instruction *ComponentType, size_t Count){ assert(false); return nullptr; }
  Instruction *Module::getTypeMatrix(Instruction *ColumnType, size_t ColumnCount){ assert(false); return nullptr; }
  Instruction *Module::getTypeImage(){ assert(false); return nullptr; }
  Instruction *Module::getTypeSampler(){ assert(false); return nullptr; }
  Instruction *Module::getTypeSampledImage(){ assert(false); return nullptr; }
  Instruction *Module::getTypeArray(){ assert(false); return nullptr; }
  Instruction *Module::getTypeRuntimeArray(){ assert(false); return nullptr; }
  Instruction *Module::getTypeStruct(){ assert(false); return nullptr; }
  Instruction *Module::getTypeOpaque(){ assert(false); return nullptr; }
  Instruction *Module::getTypePointer(){ assert(false); return nullptr; }
  Instruction *Module::getTypeFunction(){ assert(false); return nullptr; }
  Instruction *Module::getTypeEvent(){ assert(false); return nullptr; }
  Instruction *Module::getTypeDeviceEvent(){ assert(false); return nullptr; }
  Instruction *Module::getTypeReserveId(){ assert(false); return nullptr; }
  Instruction *Module::getTypeQueue(){ assert(false); return nullptr; }
  Instruction *Module::getTypePipe(){ assert(false); return nullptr; }
  Instruction *Module::getTypeForwardPointer() { assert(false); return nullptr; }