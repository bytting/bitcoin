// Copyright (c) 2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "validation.h"
#include <string>

namespace
{

struct ErrorCategoryValidation : std::error_category
{
    const char* name() const noexcept override;
    std::string message(int err) const override;
};

const char* ErrorCategoryValidation::name() const noexcept
{
    return "validation";
}

std::string ErrorCategoryValidation::message(int err) const
{
    switch(static_cast<ErrorValidation>(err))
    {
        case ErrorValidation::None:
            return "no error";
        default:
            return "(unknown error)";
    }
}

const ErrorCategoryValidation g_error_category_validation {};

} // namespace

std::error_code make_error_code(ErrorValidation e)
{
    return { static_cast<int>(e), g_error_category_validation };
}

