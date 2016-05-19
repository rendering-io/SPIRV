#ifndef SPIRV_INSTRUCTION_H
#define SPIRV_INSTRUCTION_H

#include <SPIRV/SPIRV.h>

namespace spirv {
using AccessQualifier = spv::AccessQualifier;
using AddressingModel = int;
using Decoration = int;
using Dim = int;
using ExecutionMode = int;
using ExecutionModel = int;
using FunctionControl = int;
using GroupOperation = int;
using IdMemorySemantics = int;
using IdRef = int;
using IdResultType = int;
using IdResult = int;
using IdScope = int;
using ImageFormat = int;
using ImageOperands = int;
using LiteralContextDependentNumber = int;
using LiteralExtInstInteger = int;
using LiteralInteger = int;
using LiteralSpecConstantOpInteger = int;
using LiteralString = const char*;
using LoopControl = int;
using MemoryAccess = int;
using MemoryModel = int;
using PairIdRefIdRef = int;
using PairIdRefLiteralInteger = int;
using PairLiteralIntegerIdRef = int;
using SamplerAddressingMode = int;
using SamplerFilterMode = int;
using SelectionControl = int;
using SourceLanguage = spv::SourceLanguage;
using StorageClass = spv::StorageClass;

template<typename... Operands>
class InstructionImpl : public Instruction {
  using Instruction::Instruction;
};
}

#endif // SPIRV_INSTRUCTION_H
