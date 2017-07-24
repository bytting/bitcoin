// Copyright (c) 2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_ERROR_MINER_H
#define BITCOIN_ERROR_MINER_H

#include <system_error>

enum class ErrorMiner
{
    None = 0
};

namespace std
{
template<>
    struct is_error_code_enum<ErrorMiner> : true_type {};
}

std::error_code make_error_code(ErrorMiner);

#endif
