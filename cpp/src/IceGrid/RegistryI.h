// **********************************************************************
//
// Copyright (c) 2003-2006 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

#ifndef ICE_GRID_REGISTRYI_H
#define ICE_GRID_REGISTRYI_H

#include <IceGrid/Registry.h>
#include <IceGrid/Query.h>
#include <IceGrid/Internal.h>
#include <IceGrid/ReplicaSessionManager.h>
#include <Glacier2/PermissionsVerifierF.h>
#include <IceStorm/Service.h>

namespace IceGrid
{

class Database;
typedef IceUtil::Handle<Database> DatabasePtr;

class TraceLevels;
typedef IceUtil::Handle<TraceLevels> TraceLevelsPtr;

class ReapThread;
typedef IceUtil::Handle<ReapThread> ReapThreadPtr;    

class WaitQueue;
typedef IceUtil::Handle<WaitQueue> WaitQueuePtr;    

class SessionServantLocatorI;
typedef IceUtil::Handle<SessionServantLocatorI> SessionServantLocatorIPtr;    

class ClientSessionFactory;
typedef IceUtil::Handle<ClientSessionFactory> ClientSessionFactoryPtr;    

class AdminSessionFactory;
typedef IceUtil::Handle<AdminSessionFactory> AdminSessionFactoryPtr;    

class RegistryI : public Registry
{
public:

    RegistryI(const Ice::CommunicatorPtr&);
    ~RegistryI();

    bool start(bool);
    void stop();

    virtual SessionPrx createSession(const std::string&, const std::string&, const Ice::Current&);
    virtual AdminSessionPrx createAdminSession(const std::string&, const std::string&, const Ice::Current&);

    virtual SessionPrx createSessionFromSecureConnection(const Ice::Current&);
    virtual AdminSessionPrx createAdminSessionFromSecureConnection(const Ice::Current&);

    virtual int getSessionTimeout(const Ice::Current& = Ice::Current()) const;

    virtual void shutdown();
    
private:

    Ice::LocatorPrx setupLocator(const Ice::ObjectAdapterPtr&, const Ice::ObjectAdapterPtr&, 
				 const Ice::ObjectAdapterPtr&); 
    void setupQuery(const Ice::ObjectAdapterPtr&);
    void setupRegistry(const Ice::ObjectAdapterPtr&);
    InternalRegistryPrx setupInternalRegistry(const Ice::ObjectAdapterPtr&, const std::string&);
    void setupNullPermissionsVerifier(const Ice::ObjectAdapterPtr&);
    bool setupUserAccountMapper(const Ice::ObjectAdapterPtr&);
    void setupClientSessionFactory(const Ice::ObjectAdapterPtr&, const Ice::ObjectAdapterPtr&, const Ice::LocatorPrx&,
				   bool);
    void setupAdminSessionFactory(const Ice::ObjectAdapterPtr&, const Ice::ObjectAdapterPtr&, const Ice::LocatorPrx&,
				  bool);

    void addWellKnownObject(const Ice::ObjectPrx&, const std::string&);
    void setupThreadPool(const Ice::PropertiesPtr&, const std::string&, int, int = 0);
    Glacier2::PermissionsVerifierPrx getPermissionsVerifier(const Ice::ObjectAdapterPtr&, const Ice::LocatorPrx&,
							    const std::string&, const std::string&, bool);

    Glacier2::SSLPermissionsVerifierPrx getSSLPermissionsVerifier(const Ice::LocatorPrx&, const std::string&, bool);
    Glacier2::SSLInfo getSSLInfo(const Ice::ConnectionPtr&, std::string&);

    NodePrxSeq registerReplicas(const InternalRegistryPrx&);
    void registerNodes(const InternalRegistryPrx&, const NodePrxSeq&);
    
    const Ice::CommunicatorPtr _communicator;

    DatabasePtr _database;
    TraceLevelsPtr _traceLevels;
    std::string _instanceName;
    ReapThreadPtr _reaper;
    WaitQueuePtr _waitQueue;
    SessionServantLocatorIPtr _sessionServantLocator;
    int _sessionTimeout;
    ReplicaSessionManager _session;

    ClientSessionFactoryPtr _clientSessionFactory;
    Glacier2::PermissionsVerifierPrx _clientVerifier;
    Glacier2::SSLPermissionsVerifierPrx _sslClientVerifier;

    AdminSessionFactoryPtr _adminSessionFactory;
    Glacier2::PermissionsVerifierPrx _adminVerifier;
    Glacier2::SSLPermissionsVerifierPrx _sslAdminVerifier;

    IceStorm::ServicePtr _iceStorm;
};
typedef IceUtil::Handle<RegistryI> RegistryIPtr;

}

#endif
