#pragma once

#include <string>
#include <vector>

using HRESULT_ = int;
using IID_ = int;
using CLSID_ = int;
using ULONG_ = int;

const int IID_IUnknown_ = 1;
const int IID_IDefaultMatrix = 2;
const int IID_IProMatrix = 3;

const int S_OK_ = 0;
const int E_NOINTERFACE_ = 1;
const int E_NOCOMPONENT_ = 2;

const int CLSID_Server = 1;

class IUnknown_
{
    public:
        virtual HRESULT_ __stdcall QueryInterface(const IID_& iid, void** object) = 0;
        virtual ULONG_ __stdcall AddRef() = 0;
        virtual ULONG_ __stdcall Release() = 0;
};