#include <iostream>

#include "IPower.h"
#include "Server.h"

HRESULT_ __stdcall CreateInstance(const CLSID_& clsid, const IID_& iid, void** object)
{
    IUnknown* s = NULL;

    if (clsid == CLSID_Server)
    {
        s = (IUnknown*) (IPower*) new Server();
    }
    else
    {
        *object = NULL;
        return E_NOCOMPONENT_;
    }

    s->AddRef();
    HRESULT_ res = s->QueryInterface(iid, object);
    s->Release();
    
    return res;
}
