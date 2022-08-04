#include <memory>
#include "src/vm/eva_vm.hpp"

/**
 * @brief
 *  Eva VM main executable
 */
int main(int argc, char const *argv[])
{
    std::unique_ptr<Eva::EvaVM> vm { std::make_unique<Eva::EvaVM>() };

    vm->exec(R"(
        42
    )");

    return 0;
}
