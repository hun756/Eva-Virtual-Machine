#ifndef EVA_VM_LOGGER_HPP_po2stz
#define EVA_VM_LOGGER_HPP_po2stz

#include <sstream>

namespace Eva
{
    class ErrorMessage: public std::basic_ostringstream<char>
    {
    public:
        ~ErrorMessage() {
            (void)fprintf(stderr, "%s%s\n", "Fatal Error: ", str().c_str());
            std::exit(EXIT_FAILURE);
        }
    };
}

#define DIE ErrorMessage()

#define log(value) (std::cout << #value << " = " << (value) << '\n')

#endif /* end of include guard : EVA_VM_LOGGER_HPP_po2stz */