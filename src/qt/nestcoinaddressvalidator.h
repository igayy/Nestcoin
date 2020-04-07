// Copyright (c) 2011-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef NESTCOIN_QT_NESTCOINADDRESSVALIDATOR_H
#define NESTCOIN_QT_NESTCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class NestcoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit NestcoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Nestcoin address widget validator, checks for a valid nestcoin address.
 */
class NestcoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit NestcoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // NESTCOIN_QT_NESTCOINADDRESSVALIDATOR_H
