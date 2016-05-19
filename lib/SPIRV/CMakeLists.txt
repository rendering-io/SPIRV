set(INSTRUCTIONS ${CMAKE_CURRENT_BINARY_DIR}/Instructions.c++)
set(INSTRUCTION_JSON spirv.core.grammar.json)
add_custom_command(OUTPUT ${INSTRUCTIONS}
                   COMMAND ./GenInstructions.py 
                   ARGS ${INSTRUCTION_JSON} > ${INSTRUCTIONS}
                   DEPENDS GenInstructions.py ${INSTRUCTION_JSON}
                   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                   COMMENT "Generating instruction definitions")

set(SOURCES Function.c++
            Instruction.c++
            Module.c++
            ${INSTRUCTIONS})
add_library(SPIRV ${SOURCES})
target_include_directories(SPIRV PUBLIC ${CMAKE_SOURCE_DIR}/include 
                                 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})