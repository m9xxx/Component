#include "Server.h"

#include <iostream>
using namespace std;

int a;
int b;

HRESULT_ Server::AddRef()
{
    refCount++;
    return refCount;
}

HRESULT_ Server::Release()
{
    refCount--;
    if (refCount == 0)
    {
        delete this;
    }
    
    return refCount;
}


Server::Server() 
{
  cout << "Server::Constructor, enter num, pow" << endl;
  pownum = 0;
  num = 0;
  result = 1;
}

Server::~Server() 
{
  cout << "Server::Destructor" << endl;  
}

HRESULT_ __stdcall Server::QueryInterface(const IID_& iid, void** object)
{
   cout << "Server QueryInterface:" << iid << endl;

   if (iid==IID_IUnknown)
   {
     *object = (IUnknown*)(IPower*) this;
   }
   else if (iid==IID_IPower)
   {
     *object = static_cast<IPower*>(this);
   }
   else
   {
     *object = NULL;
     return E_NOINTERFACE_;
   }
   return S_OK_;
}


HRESULT_ __stdcall Server::set_num() 
{	 	    		
  cout << "Set num func, enter num" << endl;
  cin >> this->num;
  cout << "Num entered succesfully, num = " << this->num << endl;  
  return S_OK_;
}

HRESULT_ __stdcall Server::pow_num() 
{
  cout << "Set pow func, enter pow" << endl;
  cin >> this->pownum;
  cout << "Pow entered succesfully, pow = " << this->pownum << endl;  
  return S_OK_;
}

HRESULT_ __stdcall Server::res()
{	 	    		
  a = this->num;
  b = this->pownum;
  for (int i = 0; i < b; i++){
    this->result *= a;
  }
  cout << "result = " << this->result << endl;
  return S_OK_;
}
