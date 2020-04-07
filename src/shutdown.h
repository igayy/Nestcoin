// Copyright (c) 2020 Wayan Saka
// Copyright (c) 2020 The Nestcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef NESTCOIN_SHUTDOWN_H
#define NESTCOIN_SHUTDOWN_H

void StartShutdown();
void AbortShutdown();
bool ShutdownRequested();

#endif
