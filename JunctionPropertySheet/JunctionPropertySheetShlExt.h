// JunctionPropertySheetShlExt.h : Declaration of the CJunctionPropertySheetShlExt

#pragma once
#include "resource.h"       // main symbols

#include "JunctionPropertySheet.h"


// CJunctionPropertySheetShlExt

class ATL_NO_VTABLE CJunctionPropertySheetShlExt : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CJunctionPropertySheetShlExt, &CLSID_JunctionPropertySheetShlExt>,
	public IDispatchImpl<IJunctionPropertySheetShlExt, &IID_IJunctionPropertySheetShlExt, &LIBID_JunctionPropertySheetLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IShellExtInit,
	public IShellPropSheetExt
{
public:
	CJunctionPropertySheetShlExt()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_JUNCTIONPROPERTYSHEETSHLEXT)


BEGIN_COM_MAP(CJunctionPropertySheetShlExt)
	COM_INTERFACE_ENTRY(IJunctionPropertySheetShlExt)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IShellExtInit)
	COM_INTERFACE_ENTRY(IShellPropSheetExt)
END_COM_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

protected:
	TCHAR m_filename [MAX_PATH];

public:
	// IShellExtInit
	STDMETHOD(Initialize)(LPCITEMIDLIST, LPDATAOBJECT, HKEY);

	// IShellPropSheetExt
	STDMETHOD(AddPages)(LPFNADDPROPSHEETPAGE, LPARAM);
	STDMETHOD(ReplacePage)(UINT, LPFNADDPROPSHEETPAGE, LPARAM) { return E_NOTIMPL; }
};

OBJECT_ENTRY_AUTO(__uuidof(JunctionPropertySheetShlExt), CJunctionPropertySheetShlExt)
