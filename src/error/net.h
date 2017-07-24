
#include <system_error>

enum class ErrorNet
{
    None = 0
};

namespace std
{
template<>
    struct is_error_code_enum<ErrorNet> : true_type {};
}

std::error_code make_error_code(ErrorNet);
