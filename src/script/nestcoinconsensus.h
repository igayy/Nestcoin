// Copyright (c) 2020 Wayan Saka
// Copyright (c) 2020 The Nestcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef NESTCOIN_SCRIPT_NESTCOINCONSENSUS_H
#define NESTCOIN_SCRIPT_NESTCOINCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_NESTCOIN_INTERNAL) && defined(HAVE_CONFIG_H)
#include <config/nestcoin-config.h>
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBNESTCOINCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define NESTCOINCONSENSUS_API_VER 1

typedef enum nestcoinconsensus_error_t
{
    nestcoinconsensus_ERR_OK = 0,
    nestcoinconsensus_ERR_TX_INDEX,
    nestcoinconsensus_ERR_TX_SIZE_MISMATCH,
    nestcoinconsensus_ERR_TX_DESERIALIZE,
    nestcoinconsensus_ERR_AMOUNT_REQUIRED,
    nestcoinconsensus_ERR_INVALID_FLAGS,
} nestcoinconsensus_error;

/** Script verification flags */
enum
{
    nestcoinconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    nestcoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    nestcoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    nestcoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    nestcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    nestcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    nestcoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    nestcoinconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = nestcoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH | nestcoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               nestcoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | nestcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               nestcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | nestcoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int nestcoinconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, nestcoinconsensus_error* err);

EXPORT_SYMBOL int nestcoinconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, nestcoinconsensus_error* err);

EXPORT_SYMBOL unsigned int nestcoinconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // NESTCOIN_SCRIPT_NESTCOINCONSENSUS_H
