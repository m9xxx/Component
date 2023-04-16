#pragma once

#include "ICF.h"
#include "Server.h"
#include "IPF.h"

#include <iostream>

class PowerClassFactory : public ICF, public IPowerFactory{
    private:
        int refCount;
    public:
        PowerClassFactory();

        virtual HRESULT_ __stdcall (QueryInterface(const IID_& iid, void** object));
        virtual HRESULT_ __stdcall AddRef();
        virtual HRESULT_ __stdcall Release();

        virtual HRESULT_ __stdcall CreateInstance(const IID_& iid, void** object);

        virtual HRESULT_ __stdcall CreateInstance(const IID_& iid, void** object, int license[]);

        ~PowerClassFactory();
};