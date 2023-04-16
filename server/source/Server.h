#pragma once

#include <iostream>

#include "IPower.h"

class Server : public IPower
{
    private:
        int refCount;
        int num;
        int pownum;
        int result;
    public:
        Server();
        
        virtual HRESULT_ __stdcall QueryInterface(const IID_& iid, void** object);
        virtual HRESULT_ __stdcall AddRef();
        virtual HRESULT_ __stdcall Release();

        virtual HRESULT_ __stdcall set_num();
        virtual HRESULT_ __stdcall pow_num();
        virtual HRESULT_ __stdcall res();
        
        ~Server();
};
