// Copyright (c) 2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "net.h"
#include <string>

namespace
{

struct ErrorCategoryNet : std::error_category
{
    const char* name() const noexcept override;
    std::string message(int err) const override;
};

const char* ErrorCategoryNet::name() const noexcept
{
    return "net";
}

std::string ErrorCategoryNet::message(int err) const
{
    switch(static_cast<ErrorNet>(err))
    {
        case ErrorNet::None:
            return "no error";
        default:
            return "(unknown error)";
    }
}

const ErrorCategoryNet g_error_category_net {};

} // namespace

std::error_code make_error_code(ErrorNet e)
{
    return { static_cast<int>(e), g_error_category_net };
}

