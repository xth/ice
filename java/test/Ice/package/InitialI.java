// **********************************************************************
//
// Copyright (c) 2003-2004 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

public final class InitialI extends _InitialDisp
{
    public Test1GlobalClass
    getTest1GlobalClass(Ice.Current __current)
    {
        return new Test1GlobalClass();
    }

    public void
    throwTest1GlobalException(Ice.Current __current)
        throws Test1GlobalException
    {
        throw new Test1GlobalException();
    }

    public Ice.Object
    getTest1C2AsObject(Ice.Current __current)
    {
        return new Test1.C2();
    }

    public Test1.C1
    getTest1C2AsC1(Ice.Current __current)
    {
        return new Test1.C2();
    }

    public Test1.C2
    getTest1C2AsC2(Ice.Current __current)
    {
        return new Test1.C2();
    }

    public void
    throwTest1E2AsE1(Ice.Current __current)
        throws Test1.E1
    {
        throw new Test1.E2();
    }

    public void
    throwTest1E2AsE2(Ice.Current __current)
        throws Test1.E2
    {
        throw new Test1.E2();
    }

    public void
    throwTest1Notify(Ice.Current __current)
        throws Test1._notify
    {
        throw new Test1._notify();
    }

    public testpkg.Test2GlobalClass
    getTest2GlobalClass(Ice.Current __current)
    {
        return new testpkg.Test2GlobalClass();
    }

    public void
    throwTest2GlobalException(Ice.Current __current)
        throws testpkg.Test2GlobalException
    {
        throw new testpkg.Test2GlobalException();
    }

    public Ice.Object
    getTest2C2AsObject(Ice.Current __current)
    {
        return new testpkg.Test2.C2();
    }

    public testpkg.Test2.C1
    getTest2C2AsC1(Ice.Current __current)
    {
        return new testpkg.Test2.C2();
    }

    public testpkg.Test2.C2
    getTest2C2AsC2(Ice.Current __current)
    {
        return new testpkg.Test2.C2();
    }

    public void
    throwTest2E2AsE1(Ice.Current __current)
        throws testpkg.Test2.E1
    {
        throw new testpkg.Test2.E2();
    }

    public void
    throwTest2E2AsE2(Ice.Current __current)
        throws testpkg.Test2.E2
    {
        throw new testpkg.Test2.E2();
    }

    public Ice.Object
    getTest3C2AsObject(Ice.Current __current)
    {
        return new testpkg.Test3.C2();
    }

    public testpkg.Test3.C1
    getTest3C2AsC1(Ice.Current __current)
    {
        return new testpkg.Test3.C2();
    }

    public testpkg.Test3.C2
    getTest3C2AsC2(Ice.Current __current)
    {
        return new testpkg.Test3.C2();
    }

    public void
    throwTest3E2AsE1(Ice.Current __current)
        throws testpkg.Test3.E1
    {
        throw new testpkg.Test3.E2();
    }

    public void
    throwTest3E2AsE2(Ice.Current __current)
        throws testpkg.Test3.E2
    {
        throw new testpkg.Test3.E2();
    }

    public void
    shutdown(Ice.Current __current)
    {
        __current.adapter.getCommunicator().shutdown();
    }
}
