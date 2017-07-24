
#include "storage.h"
#include <string>

namespace
{

struct ErrorCategoryStorage : std::error_category
{
    const char* name() const noexcept override;
    std::string message(int err) const override;
};

const char* ErrorCategoryStorage::name() const noexcept
{
    return "storage";
}

std::string ErrorCategoryStorage::message(int err) const
{
    switch(static_cast<ErrorStorage>(err))
    {
        case ErrorStorage::None:
            return "no error";
        default:
            return "(unknown error)";
    }
}

const ErrorCategoryStorage g_error_category_storage {};

} // namespace

std::error_code make_error_code(ErrorStorage e)
{
    return { static_cast<int>(e), g_error_category_storage };
}

