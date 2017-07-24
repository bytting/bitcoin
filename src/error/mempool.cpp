
#include "mempool.h"
#include <string>

namespace
{

struct ErrorCategoryMempool : std::error_category
{
    const char* name() const noexcept override;
    std::string message(int err) const override;
};

const char* ErrorCategoryMempool::name() const noexcept
{
    return "mempool";
}

std::string ErrorCategoryMempool::message(int err) const
{
    switch(static_cast<ErrorMempool>(err))
    {
        case ErrorMempool::None:
            return "no error";
        default:
            return "(unknown error)";
    }
}

const ErrorCategoryMempool g_error_category_mempool {};

} // namespace

std::error_code make_error_code(ErrorMempool e)
{
    return { static_cast<int>(e), g_error_category_mempool };
}

