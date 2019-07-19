//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7b2
//
// <auto-generated>
//
// Generated from file `Process.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Ice_Process_h__
#define __Ice_Process_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/ValueF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Comparable.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/GCObject.h>
#include <Ice/Value.h>
#include <Ice/Incoming.h>
#include <Ice/FactoryTableInit.h>
#include <IceUtil/ScopedArray.h>
#include <Ice/Optional.h>
#include <IceUtil/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION  != 30762
#       error Ice version mismatch: an exact match is required for beta generated code
#   endif
#endif

#ifndef ICE_API
#   if defined(ICE_STATIC_LIBS)
#       define ICE_API /**/
#   elif defined(ICE_API_EXPORTS)
#       define ICE_API ICE_DECLSPEC_EXPORT
#   else
#       define ICE_API ICE_DECLSPEC_IMPORT
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace Ice
{

class Process;
class ProcessPrx;

}

namespace Ice
{

/**
 * An administrative interface for process management. Managed servers must
 * implement this interface.
 *
 * <p class="Note">A servant implementing this interface is a potential target
 * for denial-of-service attacks, therefore proper security precautions
 * should be taken. For example, the servant can use a UUID to make its
 * identity harder to guess, and be registered in an object adapter with
 * a secured endpoint.
 * \headerfile Ice/Ice.h
 */
class ICE_API Process : public virtual Object
{
public:

    using ProxyType = ProcessPrx;

    /**
     * Determines whether this object supports an interface with the given Slice type ID.
     * @param id The fully-scoped Slice type ID.
     * @param current The Current object for the invocation.
     * @return True if this object supports the interface, false, otherwise.
     */
    virtual bool ice_isA(::std::string id, const Current& current) const override;

    /**
     * Obtains a list of the Slice type IDs representing the interfaces supported by this object.
     * @param current The Current object for the invocation.
     * @return A list of fully-scoped type IDs.
     */
    virtual ::std::vector<::std::string> ice_ids(const Current& current) const override;

    /**
     * Obtains a Slice type ID representing the most-derived interface supported by this object.
     * @param current The Current object for the invocation.
     * @return A fully-scoped type ID.
     */
    virtual ::std::string ice_id(const Current& current) const override;

    /**
     * Obtains the Slice type ID corresponding to this class.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

    /**
     * Initiate a graceful shut-down.
     * @param current The Current object for the invocation.
     * @see Communicator#shutdown
     */
    virtual void shutdown(const Current& current) = 0;
    /// \cond INTERNAL
    bool _iceD_shutdown(::IceInternal::Incoming&, const Current&);
    /// \endcond

    /**
     * Write a message on the process' stdout or stderr.
     * @param message The message.
     * @param fd 1 for stdout, 2 for stderr.
     * @param current The Current object for the invocation.
     */
    virtual void writeMessage(::std::string message, int fd, const Current& current) = 0;
    /// \cond INTERNAL
    bool _iceD_writeMessage(::IceInternal::Incoming&, const Current&);
    /// \endcond

    /// \cond INTERNAL
    virtual bool _iceDispatch(::IceInternal::Incoming&, const Current&) override;
    /// \endcond
};

}

namespace Ice
{

/**
 * An administrative interface for process management. Managed servers must
 * implement this interface.
 *
 * <p class="Note">A servant implementing this interface is a potential target
 * for denial-of-service attacks, therefore proper security precautions
 * should be taken. For example, the servant can use a UUID to make its
 * identity harder to guess, and be registered in an object adapter with
 * a secured endpoint.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ProcessPrx : public virtual Proxy<ProcessPrx, ObjectPrx>
{
public:

    /**
     * Initiate a graceful shut-down.
     * @param context The Context map to send with the invocation.
     * @see Communicator#shutdown
     */
    void shutdown(const Context& context = noExplicitContext)
    {
        _makePromiseOutgoing<void>(true, this, &ProcessPrx::_iceI_shutdown, context).get();
    }

    /**
     * Initiate a graceful shut-down.
     * @param context The Context map to send with the invocation.
     * @return The future object for the invocation.
     * @see Communicator#shutdown
     */
    template<template<typename> class P = ::std::promise>
    auto shutdownAsync(const Context& context = noExplicitContext)
        -> decltype(::std::declval<P<void>>().get_future())
    {
        return _makePromiseOutgoing<void, P>(false, this, &ProcessPrx::_iceI_shutdown, context);
    }

    /**
     * Initiate a graceful shut-down.
     * @param response The response callback.
     * @param ex The exception callback.
     * @param sent The sent callback.
     * @param context The Context map to send with the invocation.
     * @return A function that can be called to cancel the invocation locally.
     * @see Communicator#shutdown
     */
    ::std::function<void()>
    shutdownAsync(::std::function<void()> response,
                  ::std::function<void(::std::exception_ptr)> ex = nullptr,
                  ::std::function<void(bool)> sent = nullptr,
                  const Context& context = noExplicitContext)
    {
        return _makeLamdaOutgoing<void>(response, ex, sent, this, &Ice::ProcessPrx::_iceI_shutdown, context);
    }

    /// \cond INTERNAL
    ICE_MEMBER(ICE_API) void _iceI_shutdown(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>&, const Context&);
    /// \endcond

    /**
     * Write a message on the process' stdout or stderr.
     * @param message The message.
     * @param fd 1 for stdout, 2 for stderr.
     * @param context The Context map to send with the invocation.
     */
    void writeMessage(const ::std::string& message, int fd, const Context& context = noExplicitContext)
    {
        _makePromiseOutgoing<void>(true, this, &ProcessPrx::_iceI_writeMessage, message, fd, context).get();
    }

    /**
     * Write a message on the process' stdout or stderr.
     * @param message The message.
     * @param fd 1 for stdout, 2 for stderr.
     * @param context The Context map to send with the invocation.
     * @return The future object for the invocation.
     */
    template<template<typename> class P = ::std::promise>
    auto writeMessageAsync(const ::std::string& message, int fd, const Context& context = noExplicitContext)
        -> decltype(::std::declval<P<void>>().get_future())
    {
        return _makePromiseOutgoing<void, P>(false, this, &ProcessPrx::_iceI_writeMessage, message, fd, context);
    }

    /**
     * Write a message on the process' stdout or stderr.
     * @param message The message.
     * @param fd 1 for stdout, 2 for stderr.
     * @param response The response callback.
     * @param ex The exception callback.
     * @param sent The sent callback.
     * @param context The Context map to send with the invocation.
     * @return A function that can be called to cancel the invocation locally.
     */
    ::std::function<void()>
    writeMessageAsync(const ::std::string& message, int fd,
                      ::std::function<void()> response,
                      ::std::function<void(::std::exception_ptr)> ex = nullptr,
                      ::std::function<void(bool)> sent = nullptr,
                      const Context& context = noExplicitContext)
    {
        return _makeLamdaOutgoing<void>(response, ex, sent, this, &Ice::ProcessPrx::_iceI_writeMessage, message, fd, context);
    }

    /// \cond INTERNAL
    ICE_MEMBER(ICE_API) void _iceI_writeMessage(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>&, const ::std::string&, int, const Context&);
    /// \endcond

    /**
     * Obtains the Slice type ID of this interface.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();

protected:

    /// \cond INTERNAL
    ProcessPrx() = default;
    friend ::std::shared_ptr<ProcessPrx> IceInternal::createProxy<ProcessPrx>();

    ICE_MEMBER(ICE_API) virtual ::std::shared_ptr<ObjectPrx> _newInstance() const override;
    /// \endcond
};

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

/// \cond INTERNAL
namespace Ice
{

using ProcessPtr = ::std::shared_ptr<Process>;
using ProcessPrxPtr = ::std::shared_ptr<ProcessPrx>;

}
/// \endcond

#else // C++98 mapping

namespace IceProxy
{

namespace Ice
{

class Process;
/// \cond INTERNAL
ICE_API void _readProxy(::Ice::InputStream*, ::IceInternal::ProxyHandle< Process>&);
ICE_API ::IceProxy::Ice::Object* upCast(Process*);
/// \endcond

}

}

namespace Ice
{

class Process;
/// \cond INTERNAL
ICE_API Object* upCast(Process*);
/// \endcond
typedef ::IceInternal::Handle< Process> ProcessPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Ice::Process> ProcessPrx;
typedef ProcessPrx ProcessPrxPtr;
/// \cond INTERNAL
ICE_API void _icePatchObjectPtr(ProcessPtr&, const ObjectPtr&);
/// \endcond

}

namespace Ice
{

/**
 * Base class for asynchronous callback wrapper classes used for calls to
 * IceProxy::Ice::Process::begin_shutdown.
 * Create a wrapper instance by calling ::Ice::newCallback_Process_shutdown.
 */
class Callback_Process_shutdown_Base : public virtual ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_Process_shutdown_Base> Callback_Process_shutdownPtr;

/**
 * Base class for asynchronous callback wrapper classes used for calls to
 * IceProxy::Ice::Process::begin_writeMessage.
 * Create a wrapper instance by calling ::Ice::newCallback_Process_writeMessage.
 */
class Callback_Process_writeMessage_Base : public virtual ::IceInternal::CallbackBase { };
typedef ::IceUtil::Handle< Callback_Process_writeMessage_Base> Callback_Process_writeMessagePtr;

}

namespace IceProxy
{

namespace Ice
{

class ICE_CLASS(ICE_API) Process : public virtual ::Ice::Proxy<Process, ::IceProxy::Ice::Object>
{
public:

    /**
     * Initiate a graceful shut-down.
     * @param context The Context map to send with the invocation.
     * @see Communicator#shutdown
     */
    ICE_MEMBER(ICE_API) void shutdown(const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        end_shutdown(_iceI_begin_shutdown(context, ::IceInternal::dummyCallback, 0, true));
    }

    /**
     * Initiate a graceful shut-down.
     * @param context The Context map to send with the invocation.
     * @return The asynchronous result object for the invocation.
     * @see Communicator#shutdown
     */
    ::Ice::AsyncResultPtr begin_shutdown(const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _iceI_begin_shutdown(context, ::IceInternal::dummyCallback, 0);
    }

    /**
     * Initiate a graceful shut-down.
     * @param cb Asynchronous callback object.
     * @param cookie User-defined data to associate with the invocation.
     * @return The asynchronous result object for the invocation.
     * @see Communicator#shutdown
     */
    ::Ice::AsyncResultPtr begin_shutdown(const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_shutdown(::Ice::noExplicitContext, cb, cookie);
    }

    /**
     * Initiate a graceful shut-down.
     * @param context The Context map to send with the invocation.
     * @param cb Asynchronous callback object.
     * @param cookie User-defined data to associate with the invocation.
     * @return The asynchronous result object for the invocation.
     * @see Communicator#shutdown
     */
    ::Ice::AsyncResultPtr begin_shutdown(const ::Ice::Context& context, const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_shutdown(context, cb, cookie);
    }

    /**
     * Initiate a graceful shut-down.
     * @param cb Asynchronous callback object.
     * @param cookie User-defined data to associate with the invocation.
     * @return The asynchronous result object for the invocation.
     * @see Communicator#shutdown
     */
    ::Ice::AsyncResultPtr begin_shutdown(const ::Ice::Callback_Process_shutdownPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_shutdown(::Ice::noExplicitContext, cb, cookie);
    }

    /**
     * Initiate a graceful shut-down.
     * @param context The Context map to send with the invocation.
     * @param cb Asynchronous callback object.
     * @param cookie User-defined data to associate with the invocation.
     * @return The asynchronous result object for the invocation.
     * @see Communicator#shutdown
     */
    ::Ice::AsyncResultPtr begin_shutdown(const ::Ice::Context& context, const ::Ice::Callback_Process_shutdownPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_shutdown(context, cb, cookie);
    }

    /**
     * Completes an invocation of begin_shutdown.
     * @param result The asynchronous result object for the invocation.
     */
    ICE_MEMBER(ICE_API) void end_shutdown(const ::Ice::AsyncResultPtr& result);

private:

    ICE_MEMBER(ICE_API) ::Ice::AsyncResultPtr _iceI_begin_shutdown(const ::Ice::Context&, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& cookie = 0, bool sync = false);

public:

    /**
     * Write a message on the process' stdout or stderr.
     * @param message The message.
     * @param fd 1 for stdout, 2 for stderr.
     * @param context The Context map to send with the invocation.
     */
    ICE_MEMBER(ICE_API) void writeMessage(const ::std::string& message, ::Ice::Int fd, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        end_writeMessage(_iceI_begin_writeMessage(message, fd, context, ::IceInternal::dummyCallback, 0, true));
    }

    /**
     * Write a message on the process' stdout or stderr.
     * @param message The message.
     * @param fd 1 for stdout, 2 for stderr.
     * @param context The Context map to send with the invocation.
     * @return The asynchronous result object for the invocation.
     */
    ::Ice::AsyncResultPtr begin_writeMessage(const ::std::string& message, ::Ice::Int fd, const ::Ice::Context& context = ::Ice::noExplicitContext)
    {
        return _iceI_begin_writeMessage(message, fd, context, ::IceInternal::dummyCallback, 0);
    }

    /**
     * Write a message on the process' stdout or stderr.
     * @param message The message.
     * @param fd 1 for stdout, 2 for stderr.
     * @param cb Asynchronous callback object.
     * @param cookie User-defined data to associate with the invocation.
     * @return The asynchronous result object for the invocation.
     */
    ::Ice::AsyncResultPtr begin_writeMessage(const ::std::string& message, ::Ice::Int fd, const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_writeMessage(message, fd, ::Ice::noExplicitContext, cb, cookie);
    }

    /**
     * Write a message on the process' stdout or stderr.
     * @param message The message.
     * @param fd 1 for stdout, 2 for stderr.
     * @param context The Context map to send with the invocation.
     * @param cb Asynchronous callback object.
     * @param cookie User-defined data to associate with the invocation.
     * @return The asynchronous result object for the invocation.
     */
    ::Ice::AsyncResultPtr begin_writeMessage(const ::std::string& message, ::Ice::Int fd, const ::Ice::Context& context, const ::Ice::CallbackPtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_writeMessage(message, fd, context, cb, cookie);
    }

    /**
     * Write a message on the process' stdout or stderr.
     * @param message The message.
     * @param fd 1 for stdout, 2 for stderr.
     * @param cb Asynchronous callback object.
     * @param cookie User-defined data to associate with the invocation.
     * @return The asynchronous result object for the invocation.
     */
    ::Ice::AsyncResultPtr begin_writeMessage(const ::std::string& message, ::Ice::Int fd, const ::Ice::Callback_Process_writeMessagePtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_writeMessage(message, fd, ::Ice::noExplicitContext, cb, cookie);
    }

    /**
     * Write a message on the process' stdout or stderr.
     * @param message The message.
     * @param fd 1 for stdout, 2 for stderr.
     * @param context The Context map to send with the invocation.
     * @param cb Asynchronous callback object.
     * @param cookie User-defined data to associate with the invocation.
     * @return The asynchronous result object for the invocation.
     */
    ::Ice::AsyncResultPtr begin_writeMessage(const ::std::string& message, ::Ice::Int fd, const ::Ice::Context& context, const ::Ice::Callback_Process_writeMessagePtr& cb, const ::Ice::LocalObjectPtr& cookie = 0)
    {
        return _iceI_begin_writeMessage(message, fd, context, cb, cookie);
    }

    /**
     * Completes an invocation of begin_writeMessage.
     * @param result The asynchronous result object for the invocation.
     */
    ICE_MEMBER(ICE_API) void end_writeMessage(const ::Ice::AsyncResultPtr& result);

private:

    ICE_MEMBER(ICE_API) ::Ice::AsyncResultPtr _iceI_begin_writeMessage(const ::std::string&, ::Ice::Int, const ::Ice::Context&, const ::IceInternal::CallbackBasePtr&, const ::Ice::LocalObjectPtr& cookie = 0, bool sync = false);

public:

    /**
     * Obtains the Slice type ID corresponding to this interface.
     * @return A fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();

protected:
    /// \cond INTERNAL

    ICE_MEMBER(ICE_API) virtual ::IceProxy::Ice::Object* _newInstance() const;
    /// \endcond
};

}

}

namespace Ice
{

/**
 * An administrative interface for process management. Managed servers must
 * implement this interface.
 *
 * <p class="Note">A servant implementing this interface is a potential target
 * for denial-of-service attacks, therefore proper security precautions
 * should be taken. For example, the servant can use a UUID to make its
 * identity harder to guess, and be registered in an object adapter with
 * a secured endpoint.
 * \headerfile Ice/Ice.h
 */
class ICE_API Process : public virtual Object
{
public:

    typedef ProcessPrx ProxyType;
    typedef ProcessPtr PointerType;

    virtual ~Process();

    /**
     * Determines whether this object supports an interface with the given Slice type ID.
     * @param id The fully-scoped Slice type ID.
     * @param current The Current object for the invocation.
     * @return True if this object supports the interface, false, otherwise.
     */
    virtual bool ice_isA(const ::std::string& id, const Current& current = emptyCurrent) const;

    /**
     * Obtains a list of the Slice type IDs representing the interfaces supported by this object.
     * @param current The Current object for the invocation.
     * @return A list of fully-scoped type IDs.
     */
    virtual ::std::vector< ::std::string> ice_ids(const Current& current = emptyCurrent) const;

    /**
     * Obtains a Slice type ID representing the most-derived interface supported by this object.
     * @param current The Current object for the invocation.
     * @return A fully-scoped type ID.
     */
    virtual const ::std::string& ice_id(const Current& current = emptyCurrent) const;

    /**
     * Obtains the Slice type ID corresponding to this class.
     * @return A fully-scoped type ID.
     */
    static const ::std::string& ice_staticId();

    /**
     * Initiate a graceful shut-down.
     * @param current The Current object for the invocation.
     * @see Communicator#shutdown
     */
    virtual void shutdown(const Current& current = emptyCurrent) = 0;
    /// \cond INTERNAL
    bool _iceD_shutdown(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

    /**
     * Write a message on the process' stdout or stderr.
     * @param message The message.
     * @param fd 1 for stdout, 2 for stderr.
     * @param current The Current object for the invocation.
     */
    virtual void writeMessage(const ::std::string& message, Int fd, const Current& current = emptyCurrent) = 0;
    /// \cond INTERNAL
    bool _iceD_writeMessage(::IceInternal::Incoming&, const ::Ice::Current&);
    /// \endcond

    /// \cond INTERNAL
    virtual bool _iceDispatch(::IceInternal::Incoming&, const Current&);
    /// \endcond

protected:

    /// \cond STREAM
    virtual void _iceWriteImpl(OutputStream*) const;
    virtual void _iceReadImpl(InputStream*);
    /// \endcond
};

/// \cond INTERNAL
inline bool operator==(const Process& lhs, const Process& rhs)
{
    return static_cast<const Object&>(lhs) == static_cast<const Object&>(rhs);
}

inline bool operator<(const Process& lhs, const Process& rhs)
{
    return static_cast<const Object&>(lhs) < static_cast<const Object&>(rhs);
}
/// \endcond

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

namespace Ice
{

/**
 * Type-safe asynchronous callback wrapper class used for calls to
 * IceProxy::Ice::Process::begin_shutdown.
 * Create a wrapper instance by calling ::Ice::newCallback_Process_shutdown.
 */
template<class T>
class CallbackNC_Process_shutdown : public Callback_Process_shutdown_Base, public ::IceInternal::OnewayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)();

    CallbackNC_Process_shutdown(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallbackNC<T>(obj, cb, excb, sentcb)
    {
    }
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Ice::Process::begin_shutdown.
 */
template<class T> Callback_Process_shutdownPtr
newCallback_Process_shutdown(const IceUtil::Handle<T>& instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Process_shutdown<T>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Ice::Process::begin_shutdown.
 */
template<class T> Callback_Process_shutdownPtr
newCallback_Process_shutdown(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Process_shutdown<T>(instance, 0, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Ice::Process::begin_shutdown.
 */
template<class T> Callback_Process_shutdownPtr
newCallback_Process_shutdown(T* instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Process_shutdown<T>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Ice::Process::begin_shutdown.
 */
template<class T> Callback_Process_shutdownPtr
newCallback_Process_shutdown(T* instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Process_shutdown<T>(instance, 0, excb, sentcb);
}

/**
 * Type-safe asynchronous callback wrapper class with cookie support used for calls to
 * IceProxy::Ice::Process::begin_shutdown.
 * Create a wrapper instance by calling ::Ice::newCallback_Process_shutdown.
 */
template<class T, typename CT>
class Callback_Process_shutdown : public Callback_Process_shutdown_Base, public ::IceInternal::OnewayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const CT&);

    Callback_Process_shutdown(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallback<T, CT>(obj, cb, excb, sentcb)
    {
    }
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Ice::Process::begin_shutdown.
 */
template<class T, typename CT> Callback_Process_shutdownPtr
newCallback_Process_shutdown(const IceUtil::Handle<T>& instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Process_shutdown<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Ice::Process::begin_shutdown.
 */
template<class T, typename CT> Callback_Process_shutdownPtr
newCallback_Process_shutdown(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Process_shutdown<T, CT>(instance, 0, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Ice::Process::begin_shutdown.
 */
template<class T, typename CT> Callback_Process_shutdownPtr
newCallback_Process_shutdown(T* instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Process_shutdown<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Ice::Process::begin_shutdown.
 */
template<class T, typename CT> Callback_Process_shutdownPtr
newCallback_Process_shutdown(T* instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Process_shutdown<T, CT>(instance, 0, excb, sentcb);
}

/**
 * Type-safe asynchronous callback wrapper class used for calls to
 * IceProxy::Ice::Process::begin_writeMessage.
 * Create a wrapper instance by calling ::Ice::newCallback_Process_writeMessage.
 */
template<class T>
class CallbackNC_Process_writeMessage : public Callback_Process_writeMessage_Base, public ::IceInternal::OnewayCallbackNC<T>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception&);
    typedef void (T::*Sent)(bool);
    typedef void (T::*Response)();

    CallbackNC_Process_writeMessage(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallbackNC<T>(obj, cb, excb, sentcb)
    {
    }
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Ice::Process::begin_writeMessage.
 */
template<class T> Callback_Process_writeMessagePtr
newCallback_Process_writeMessage(const IceUtil::Handle<T>& instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Process_writeMessage<T>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Ice::Process::begin_writeMessage.
 */
template<class T> Callback_Process_writeMessagePtr
newCallback_Process_writeMessage(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Process_writeMessage<T>(instance, 0, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Ice::Process::begin_writeMessage.
 */
template<class T> Callback_Process_writeMessagePtr
newCallback_Process_writeMessage(T* instance, void (T::*cb)(), void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Process_writeMessage<T>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Ice::Process::begin_writeMessage.
 */
template<class T> Callback_Process_writeMessagePtr
newCallback_Process_writeMessage(T* instance, void (T::*excb)(const ::Ice::Exception&), void (T::*sentcb)(bool) = 0)
{
    return new CallbackNC_Process_writeMessage<T>(instance, 0, excb, sentcb);
}

/**
 * Type-safe asynchronous callback wrapper class with cookie support used for calls to
 * IceProxy::Ice::Process::begin_writeMessage.
 * Create a wrapper instance by calling ::Ice::newCallback_Process_writeMessage.
 */
template<class T, typename CT>
class Callback_Process_writeMessage : public Callback_Process_writeMessage_Base, public ::IceInternal::OnewayCallback<T, CT>
{
public:

    typedef IceUtil::Handle<T> TPtr;

    typedef void (T::*Exception)(const ::Ice::Exception& , const CT&);
    typedef void (T::*Sent)(bool , const CT&);
    typedef void (T::*Response)(const CT&);

    Callback_Process_writeMessage(const TPtr& obj, Response cb, Exception excb, Sent sentcb)
        : ::IceInternal::OnewayCallback<T, CT>(obj, cb, excb, sentcb)
    {
    }
};

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Ice::Process::begin_writeMessage.
 */
template<class T, typename CT> Callback_Process_writeMessagePtr
newCallback_Process_writeMessage(const IceUtil::Handle<T>& instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Process_writeMessage<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Ice::Process::begin_writeMessage.
 */
template<class T, typename CT> Callback_Process_writeMessagePtr
newCallback_Process_writeMessage(const IceUtil::Handle<T>& instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Process_writeMessage<T, CT>(instance, 0, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param cb The success method of the callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Ice::Process::begin_writeMessage.
 */
template<class T, typename CT> Callback_Process_writeMessagePtr
newCallback_Process_writeMessage(T* instance, void (T::*cb)(const CT&), void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Process_writeMessage<T, CT>(instance, cb, excb, sentcb);
}

/**
 * Creates a callback wrapper instance that delegates to your object.
 * Use this overload when your callback methods receive a cookie value.
 * @param instance The callback object.
 * @param excb The exception method of the callback object.
 * @param sentcb The sent method of the callback object.
 * @return An object that can be passed to an asynchronous invocation of IceProxy::Ice::Process::begin_writeMessage.
 */
template<class T, typename CT> Callback_Process_writeMessagePtr
newCallback_Process_writeMessage(T* instance, void (T::*excb)(const ::Ice::Exception&, const CT&), void (T::*sentcb)(bool, const CT&) = 0)
{
    return new Callback_Process_writeMessage<T, CT>(instance, 0, excb, sentcb);
}

}

#endif

#include <IceUtil/PopDisableWarnings.h>
#endif
