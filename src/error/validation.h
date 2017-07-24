
#include <system_error>

enum class ErrorValidation
{
    None = 0;
};

namespace std
{
template<>
    struct is_error_code_enum<ErrorValidation> : true_type {};
}

std::error_code make_error_code(ErrorValidation);
