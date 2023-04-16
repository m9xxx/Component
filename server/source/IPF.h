#pragma once
#include "iunknown_.h"

class IPowerFactory : public IUnknown_{
    public:
        virtual HRESULT_ __stdcall CreateInstance(const IID_& iid, void** object, int license[]) = 0;
};