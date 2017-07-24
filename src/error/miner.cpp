
#include "miner.h"
#include <string>

namespace
{

struct ErrorCategoryMiner : std::error_category
{
    const char* name() const noexcept override;
    std::string message(int err) const override;
};

const char* ErrorCategoryMiner::name() const noexcept
{
    return "miner";
}

std::string ErrorCategoryMiner::message(int err) const
{
    switch(static_cast<ErrorMiner>(err))
    {
        case ErrorMiner::None:
            return "no error";
        default:
            return "(unknown error)";
    }
}

const ErrorCategoryMiner g_error_category_miner {};

} // namespace

std::error_code make_error_code(ErrorMiner e)
{
    return { static_cast<int>(e), g_error_category_miner };
}

