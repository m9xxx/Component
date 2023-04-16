#pragma once

#include "IUnknown.h"

class ICF : public IUnknown
{
    public:
        virtual HRESULT __stdcall CreateInstance(
        const IID& iid,
        void** ppv) = 0;
};

