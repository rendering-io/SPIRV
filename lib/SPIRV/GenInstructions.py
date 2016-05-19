#!/usr/bin/python3
import json
import sys

def emitConstructor(className, opTypeList, opCode, capabilities):
  # Build a comma separated list of capabilities.
  caps = ""
  if capabilities != None:
    capabilities = ['Capability::' + c for c in capabilities]
    caps = ", ".join(capabilities)

  # Emit the constructor declaration.
  print('  ' + className + '()')

  # Emit the call to the base instruction constructor.
  print('  : InstructionImpl<' + opTypeList + '>{' + str(opCode) + ', "' + className + '", {'+caps+'}} {}')
  pass

def emitInstruction(inst):
  className = inst['opname']
  opCode = inst['opcode']

  # Build a type list
  opTypeList = []
  if ('operands' in inst.keys()):
    opTypeList = [op['kind'] for op in inst['operands']]
  opTypeListStr = ", ".join(opTypeList)

  print('class ' + className + ' : public InstructionImpl<' + opTypeListStr +'> {')
  print('public:')

  caps = None
  if 'capabilities' in inst.keys():
    caps = inst['capabilities']
  emitConstructor(className, opTypeListStr, opCode, caps)
  print('};')
  print('')
  pass

fo = open(sys.argv[1], 'r')
js_str = fo.read()
parsed_json = json.loads(js_str)

insts = parsed_json['instructions']

print('#include <SPIRV/SPIRV.h>')
print('#include <Instruction.h>')
print('')
print('namespace spirv {')
[emitInstruction(i) for i in parsed_json['instructions']]
print('}')