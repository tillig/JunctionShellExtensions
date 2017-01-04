// JunctionPropertySheet.cpp : Implementation of DLL Exports.

#include "stdafx.h"
#include "resource.h"
#include "JunctionPropertySheet.h"

class CJunctionPropertySheetModule : public CAtlDllModuleT< CJunctionPropertySheetModule >
{
public :
	DECLARE_LIBID(LIBID_JunctionPropertySheetLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_JUNCTIONPROPERTYSHEET, "{6CACA432-80FB-45EB-9B61-43162829FB84}")
};

CJunctionPropertySheetModule _AtlModule;


// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
    return _AtlModule.DllMain(dwReason, lpReserved); 
}


// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
    return _AtlModule.DllCanUnloadNow();
}


// Returns a class factory to create an object of the requested type
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
	// registers object, typelib and all interfaces in typelib
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr;
}
