// Copyright (c) 2020 Wayan Saka
// Copyright (c) 2020 The Nestcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef NESTCOIN_SUPPORT_CLEANSE_H
#define NESTCOIN_SUPPORT_CLEANSE_H

#include <stdlib.h>

// Attempt to overwrite data in the specified memory span.
void memory_cleanse(void *ptr, size_t len);

#endif // NESTCOIN_SUPPORT_CLEANSE_H
