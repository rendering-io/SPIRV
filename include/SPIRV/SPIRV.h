#ifndef SPIRV_H
#define SPIRV_H

#include <cstddef>
#include <memory>
#include "internal/spirv.hpp11"

namespace spirv {
class Instruction;
class BasicBlock;
class Function;
class Module;

class BasicBlock {
public:
  BasicBlock* Create(const char *Name, Function *Parent);
};

class Function {
private:
  Function(const char* Name, Module* M);
public:
  ~Function();

  static std::unique_ptr<Function> Create(const char*, Module *M = nullptr);

  const char* getName() const;
private:
  struct Impl;
  std::unique_ptr<Impl> PImpl;  
};

class Module {
private:
  Module(const char* Name);
public:
  ~Module();

  static std::unique_ptr<Module> Create(const char* Name = nullptr);

  Function* getOrAddFunction(const char*);
  Instruction *getTypeVoid();
  Instruction *getTypeBool();
  Instruction *getTypeInt(size_t Width, bool IsSigned);
  Instruction *getTypeFloat(size_t Width);
  Instruction *getTypeVector(Instruction *ComponentType, size_t Count);
  Instruction *getTypeMatrix(Instruction *ColumnType, size_t ColumnCount);
  Instruction *getTypeImage();
  Instruction *getTypeSampler();
  Instruction *getTypeSampledImage();
  Instruction *getTypeArray();
  Instruction *getTypeRuntimeArray();
  Instruction *getTypeStruct();
  Instruction *getTypeOpaque();
  Instruction *getTypePointer();
  Instruction *getTypeFunction();
  Instruction *getTypeEvent();
  Instruction *getTypeDeviceEvent();
  Instruction *getTypeReserveId();
  Instruction *getTypeQueue();
  Instruction *getTypePipe();
  Instruction *getTypeForwardPointer();
private:
  struct Impl;
  std::unique_ptr<Impl> PImpl;
};
}

#endif // SPIRV_H
