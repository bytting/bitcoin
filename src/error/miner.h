
#include <system_error>

enum class ErrorMiner
{
    None = 0
};

namespace std
{
template<>
    struct is_error_code_enum<ErrorMiner> : true_type {};
}

std::error_code make_error_code(ErrorMiner);
