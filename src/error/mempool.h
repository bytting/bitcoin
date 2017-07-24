// Copyright (c) 2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_ERROR_MEMPOOL_H
#define BITCOIN_ERROR_MEMPOOL_H

#include <system_error>

enum class ErrorMempool
{
    None = 0
};

namespace std
{
template<>
    struct is_error_code_enum<ErrorMempool> : true_type {};
}

std::error_code make_error_code(ErrorMempool);

#endif
