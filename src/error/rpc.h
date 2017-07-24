
#include <system_error>

enum class ErrorRpc
{
    None = 0;
};

namespace std
{
template<>
    struct is_error_code_enum<ErrorRpc> : true_type {};
}

std::error_code make_error_code(ErrorRpc);
