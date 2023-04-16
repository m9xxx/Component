#include "PF.h"

using namespace std;

PowerClassFactory::PowerClassFactory(){
    cout<<"PowerClassFactory::PowerClassFactory"<<endl;
    this->refCount = 0;
}

PowerClassFactory::~PowerClassFactory(){
    cout<<"PowerClassFactory::~PowerClassFactory"<<endl;
}


HRESULT_ PowerClassFactory::QueryInterface(const IID_& iid, void** object){
    cout<<"PowerClassFactory::QueryInterface"<<endl;
        if (iid == IID_IClassFactory_){
            *object = (IUnknown*) (ICF*) this;
        }
        else if (iid == IID_IPowerClassFactory){
            *object = (IUnknown*) (IPowerFactory*) this;
        }
        else{
            *object = NULL;
            return E_NOINTERFACE_;
        }

        this->AddRef();
        return refCount;
}

HRESULT_ PowerClassFactory::AddRef(){
    refCount++;
    return refCount;
}

HRESULT_ PowerClassFactory::Release(){
    refCount--;
    if (refCount == 0){
        delete this;
    }
    return refCount;
}

HRESULT_ PowerClassFactory::CreateInstance(const IID_& iid, void** object){
    cout<<"PowerClassFactory::CreateInstance"<<endl;
    IUnknown* s = (IUnknown*)(IPower*) new Server();

    s->AddRef();
    HRESULT_ res = s->QueryInterface(iid, object);
    s->Release();

    return res;
}

HRESULT_ PowerClassFactory::CreateInstance(const IID_& iid, void** object, int license[]){
    cout<<"PowerClassFactory::CreateInstance with license"<<endl;
    HRESULT_ res = E_NOCOMPONENT_;

    if (license != NULL){
        IUnknown*s = (IUnknown*)(IPower*) new Server();

        s->AddRef();
        res = s->QueryInterface(iid, object);
        s->Release();
    }
    return res;
}
//global
HRESULT_ __stdcall CreateInstance(const CLSID_& clsid, const IID_& iid, void** object){
    cout<<"CreateIsntance"<<endl;

    ICF* s = NULL;
    HRESULT_ res = GetClassObject(clsid, IID_IClassFactory_, (void**) &s);

    if (res == S_OK_){
            IPower* p = NULL;
            res = s->CreateInstance(iid, (void**) &p);
            *object = (IUnknown*)(IPower*) p;
        
    }else{
        cout<<"CreateIsntance ERROR"<<endl;
    }

    return res;
}

HRESULT_ __stdcall GetClassObject(const CLSID_& clsid, const IID_& iid, void** object){
    cout<<"GetClassObject"<<endl;
    IUnknown* s = NULL;
    if (clsid == CLSID_PowerClassFactory){
        s = (IUnknown*)(ICF*) new PowerClassFactory();
    }else{
        *object = NULL;
        return E_NOCOMPONENT_;
    }
    s->AddRef();
    HRESULT_ res = s->QueryInterface(iid, object);
    s->Release();

    return S_OK_;
}