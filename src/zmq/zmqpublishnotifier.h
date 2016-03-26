// Copyright (c) 2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_ZMQ_ZMQPUBLISHNOTIFIER_H
#define BITCOIN_ZMQ_ZMQPUBLISHNOTIFIER_H

#include "zmqabstractnotifier.h"
#include "txmempool.h"

class CBlockIndex;

class CZMQAbstractPublishNotifier : public CZMQAbstractNotifier
{
public:
    bool Initialize(void *pcontext);
    void Shutdown();
};

class CZMQPublishHashBlockNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyBlock(const CBlockIndex *pindex);
};

class CZMQPublishHashTransactionNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyTransaction(const CTransaction &transaction);
};

class CZMQPublishRawBlockNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyBlock(const CBlockIndex *pindex);
};

class CZMQPublishRawTransactionNotifier : public CZMQAbstractPublishNotifier
{
public:
    bool NotifyTransaction(const CTransaction &transaction);
};

class CZMQPublishMempoolNotifier : public CZMQAbstractPublishNotifier
{
public:
    CZMQPublishMempoolNotifier(CTxMemPool *mempoolIn);
    ~CZMQPublishMempoolNotifier();

    void NotifyEntryAdded(const CTxMemPoolEntry &entry);
    void NotifyEntryRemoved(const CTxMemPoolEntry &entry, MemPoolRemovalReason reason);

private:
    CTxMemPool *mempool;
};

#endif // BITCOIN_ZMQ_ZMQPUBLISHNOTIFIER_H
