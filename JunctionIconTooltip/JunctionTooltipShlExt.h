// JunctionTooltipShlExt.h : Declaration of the CJunctionTooltipShlExt

#pragma once
#include "resource.h"       // main symbols

#include "JunctionIconTooltip.h"


// CJunctionTooltipShlExt

class ATL_NO_VTABLE CJunctionTooltipShlExt : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CJunctionTooltipShlExt, &CLSID_JunctionTooltipShlExt>,
	public IDispatchImpl<IJunctionTooltipShlExt, &IID_IJunctionTooltipShlExt, &LIBID_JunctionIconTooltipLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IPersistFile,
	public IQueryInfo
{
public:
	CJunctionTooltipShlExt()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_JUNCTIONTOOLTIPSHLEXT)


BEGIN_COM_MAP(CJunctionTooltipShlExt)
	COM_INTERFACE_ENTRY(IJunctionTooltipShlExt)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IPersistFile)
	COM_INTERFACE_ENTRY(IQueryInfo)
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
	CString m_sFilename;

public:
	// IPersistFile
	STDMETHOD(GetClassID)(LPCLSID)		{ return E_NOTIMPL; }
	STDMETHOD(IsDirty)()				{ return E_NOTIMPL; }
	STDMETHOD(Load)(LPCOLESTR, DWORD);
	STDMETHOD(Save)(LPCOLESTR, BOOL)	{ return E_NOTIMPL; }
	STDMETHOD(SaveCompleted)(LPCOLESTR)	{ return E_NOTIMPL; }
	STDMETHOD(GetCurFile)(LPOLESTR*)	{ return E_NOTIMPL; }

	// IQueryInfo
	STDMETHOD(GetInfoFlags)(DWORD*)		{ return E_NOTIMPL; }
	STDMETHOD(GetInfoTip)(DWORD, LPWSTR*);
};

OBJECT_ENTRY_AUTO(__uuidof(JunctionTooltipShlExt), CJunctionTooltipShlExt)
