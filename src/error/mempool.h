
#include <system_error>

enum class ErrorMempool
{
    None = 0;
};

namespace std
{
template<>
    struct is_error_code_enum<ErrorMempool> : true_type {};
}

std::error_code make_error_code(ErrorMempool);
