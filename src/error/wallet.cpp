
#include "wallet.h"
#include <string>

namespace
{

struct ErrorCategoryWallet : std::error_category
{
    const char* name() const noexcept override;
    std::string message(int err) const override;
};

const char* ErrorCategoryWallet::name() const noexcept
{
    return "wallet";
}

std::string ErrorCategoryWallet::message(int err) const
{
    switch(static_cast<ErrorWallet>(err))
    {
        case ErrorWallet::None:
            return "no error";
        default:
            return "(unknown error)";
    }
}

const ErrorCategoryWallet g_error_category_wallet {};

} // namespace

std::error_code make_error_code(ErrorWallet e)
{
    return { static_cast<int>(e), g_error_category_wallet };
}

