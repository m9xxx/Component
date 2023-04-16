#pragma once

#include "IUnknown.h"

class IPower : public IUnknown
{
    public:
        virtual HRESULT_ __stdcall set_num() = 0;
        virtual HRESULT_ __stdcall pow_num() = 0;
        virtual HRESULT_ __stdcall res() = 0;
};

HRESULT_ __stdcall CreateInstance(const CLSID_& clsid, const IID_& iid, void** object);
