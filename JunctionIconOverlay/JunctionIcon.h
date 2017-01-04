// JunctionIcon.h : Declaration of the CJunctionIcon

#pragma once
#include "resource.h"       // main symbols
#include "JunctionIconOverlay.h"



// CJunctionIcon

class ATL_NO_VTABLE CJunctionIcon :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CJunctionIcon, &CLSID_JunctionIcon>,
	public IDispatchImpl<IJunctionIcon, &IID_IJunctionIcon, &LIBID_JunctionIconOverlayLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
  public IShellIconOverlayIdentifier
{
public:
	CJunctionIcon()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_JUNCTIONICON)


BEGIN_COM_MAP(CJunctionIcon)
	COM_INTERFACE_ENTRY(IJunctionIcon)
	COM_INTERFACE_ENTRY(IDispatch)
  COM_INTERFACE_ENTRY(IShellIconOverlayIdentifier)
END_COM_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

  // IShellIconOverlayIdentifier Methods
  STDMETHOD(GetOverlayInfo)(LPWSTR pwszIconFile,int cchMax,int *pIndex,DWORD* pdwFlags);
  STDMETHOD(GetPriority)(int* pPriority);
  STDMETHOD(IsMemberOf)(LPCWSTR pwszPath,DWORD dwAttrib);

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

};

OBJECT_ENTRY_AUTO(__uuidof(JunctionIcon), CJunctionIcon)
