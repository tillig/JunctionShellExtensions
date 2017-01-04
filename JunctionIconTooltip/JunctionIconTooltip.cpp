// JunctionIconTooltip.cpp : Implementation of DLL Exports.

#include "stdafx.h"
#include "resource.h"
#include "JunctionIconTooltip.h"

class CJunctionIconTooltipModule : public CAtlDllModuleT< CJunctionIconTooltipModule >
{
public :
	DECLARE_LIBID(LIBID_JunctionIconTooltipLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_JUNCTIONICONTOOLTIP, "{3992D869-B01C-4380-BE7F-A201790B3AB3}")
};

CJunctionIconTooltipModule _AtlModule;

class CJunctionIconTooltipApp : public CWinApp
{
public:

// Overrides
    virtual BOOL InitInstance();
    virtual int ExitInstance();

    DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CJunctionIconTooltipApp, CWinApp)
END_MESSAGE_MAP()

CJunctionIconTooltipApp theApp;

BOOL CJunctionIconTooltipApp::InitInstance()
{
    return CWinApp::InitInstance();
}

int CJunctionIconTooltipApp::ExitInstance()
{
    return CWinApp::ExitInstance();
}


// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    return (AfxDllCanUnloadNow()==S_OK && _AtlModule.GetLockCount()==0) ? S_OK : S_FALSE;
}


// Returns a class factory to create an object of the requested type
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
    // On NT, add ourself to the list of approved shell extensions.
    if ( 0 == (GetVersion() & 0x80000000) ){
		CRegKey reg;
		LONG    lRet;

		lRet = reg.Open ( HKEY_LOCAL_MACHINE, 
							_T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Approved"),
							KEY_SET_VALUE );

		if ( ERROR_SUCCESS != lRet )
			return E_ACCESSDENIED;

		lRet = reg.SetValue ( _T("CJunctionIconTooltipShlExt extension"),
								_T("{088C74CA-76D2-4C1F-A411-D13736875597}") );

		if ( lRet != ERROR_SUCCESS )
			return E_ACCESSDENIED;
	}

	// registers object, typelib and all interfaces in typelib
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
	if ( 0 == (GetVersion() & 0x80000000) ){
		CRegKey reg;
		LONG    lRet;

		lRet = reg.Open ( HKEY_LOCAL_MACHINE, 
							_T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Approved"),
							KEY_SET_VALUE );

		if ( ERROR_SUCCESS == lRet ){
			reg.DeleteValue ( _T("{088C74CA-76D2-4C1F-A411-D13736875597}") );
		}
	}
	HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr;
}
