#include "lib/IUnknown.h"
#include "lib/IPower.h"
#include "lib/ICF.h"

#include <iostream>

using namespace std;

int main() {
	try
	{   		
	cout << "Client main start" << endl;	

	ICF* PCF = NULL;
	HRESULT_ res = GetClassObject(1, 100, (void**)&PCF);
	
	return 0;
	 }
 catch (...) 
 {
	cout << "Client::Main::Unknown error while application running"  << endl;			
	return 0;
 }
}