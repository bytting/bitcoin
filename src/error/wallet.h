
#include <system_error>

enum class ErrorWallet
{
    None = 0
};

namespace std
{
template<>
    struct is_error_code_enum<ErrorWallet> : true_type {};
}

std::error_code make_error_code(ErrorWallet);
