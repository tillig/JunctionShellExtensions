// JunctionIcon.cpp : Implementation of CJunctionIcon

#include "stdafx.h"
#include "JunctionIcon.h"


// CJunctionIcon

// IShellIconOverlayIdentifier Method Implementation
// IShellIconOverlayIdentifier::GetOverlayInfo
// returns The Overlay Icon Location to the system
STDMETHODIMP CJunctionIcon::GetOverlayInfo(
  LPWSTR pwszIconFile,
  int cchMax,int* pIndex,
  DWORD* pdwFlags)
{
  GetModuleFileNameW(_AtlBaseModule.GetModuleInstance(), pwszIconFile, cchMax);

  *pIndex = 0;
  *pdwFlags = ISIOI_ICONFILE | ISIOI_ICONINDEX;

  return S_OK;
}

// IShellIconOverlayIdentifier Method Implementation

// returns the priority of this overlay 0 being the highest.
// this overlay is always selected do to its high priority
STDMETHODIMP CJunctionIcon::GetPriority(int* pPriority)
{
  // highest priority
  *pPriority=0;
  return S_OK;
}

// IShellIconOverlayIdentifier Method Implementation
// IShellIconOverlayIdentifier::IsMemberOf
// Returns Whether the object should have this overlay or not
STDMETHODIMP CJunctionIcon::IsMemberOf(LPCWSTR pwszPath, DWORD dwAttrib)
{
	// By default, assume this isn't a reparse point
	HRESULT r = S_FALSE;

	// If the attributes are valid and this is a reparse point, return OK
	if((dwAttrib != INVALID_FILE_ATTRIBUTES) && (dwAttrib & FILE_ATTRIBUTE_REPARSE_POINT)){
		r = S_OK;
	}

	return r;
}
