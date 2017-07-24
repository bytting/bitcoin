// Copyright (c) 2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "rpc.h"
#include <string>

namespace
{

struct ErrorCategoryRpc : std::error_category
{
    const char* name() const noexcept override;
    std::string message(int err) const override;
};

const char* ErrorCategoryRpc::name() const noexcept
{
    return "rpc";
}

std::string ErrorCategoryRpc::message(int err) const
{
    switch(static_cast<ErrorRpc>(err))
    {
        case ErrorRpc::None:
            return "no error";
        default:
            return "(unknown error)";
    }
}

const ErrorCategoryRpc g_error_category_rpc {};

} // namespace

std::error_code make_error_code(ErrorRpc e)
{
    return { static_cast<int>(e), g_error_category_rpc };
}

