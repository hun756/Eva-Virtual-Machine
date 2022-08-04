#ifndef EVA_VIRTUAL_MACHINE_HPP_51ympc
#define EVA_VIRTUAL_MACHINE_HPP_51ympc

#include <string>
#include <vector>

#include "../bytecode/opcode.hpp"
#include "../logger/logger.hpp"

/**
 * @brief
 *  Reads the current byte in the bytecode
 *  and advances the ip pointer.
 */
#define READ_BYTE() *ip++;

namespace Eva
{
    /**
     * @brief
     * @class
     *  Base class for Eva Virtual Machine.
     */
    class EvaVM
    {
    public:
        EvaVM() {}

        /**
         * @brief
         *  Executes a program.
         */
        void exec(const std::string &program)
        {
            // Step 1. Parse the program.
            // auto ast = parser->parse(program)

            // Step 2. Compile the program to Eva ByteCode
            // code = compiler->compile(ast)

            code = {OP_HALT};

            // Set instruction pointer to the beginning.
            ip = &code[0];
            return eval();
        }

        /**
         * @brief
         *  Main eval loop.
         */
        void eval()
        {
            while (true)
            {
                auto opcode = READ_BYTE();
                switch (opcode)
                {
                case OP_HALT:
                    return;
                default:
                    DIE << "Unknown opcode: " << std::hex << opcode;
                }
            }
        }

        /**
         * @brief
         *  Instruction pointer (aka program counter)
         */
        uint8_t *ip;

        /**
         * @brief
         *  Bytecode collection.
         */
        std::vector<uint8_t> code;
    };
}

#endif /* end of include guard : EVA_VIRTUAL_MACHINE_HPP_51ympc */