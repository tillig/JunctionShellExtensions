// JunctionTooltipShlExt.cpp : Implementation of CJunctionTooltipShlExt

#include "stdafx.h"
#include "JunctionTooltipShlExt.h"


// CJunctionTooltipShlExt

HRESULT CJunctionTooltipShlExt::Load ( LPCOLESTR wszFilename, DWORD dwMode )
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());    // init MFC

	// Let CString convert the filename to ANSI if necessary.
	m_sFilename = wszFilename;

	return S_OK;
}

HRESULT CJunctionTooltipShlExt::GetInfoTip ( DWORD dwFlags, LPWSTR* ppwszTip )
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());    // init MFC

	LPMALLOC   pMalloc;
	CString    sTooltip;

	UNREFERENCED_PARAMETER(dwFlags);
	USES_CONVERSION;

	// Get an IMalloc interface from the shell.
	if ( FAILED( SHGetMalloc ( &pMalloc )))
		return E_FAIL;

	sTooltip.Format ( _T("CUSTOM: %s"), m_sFilename );

	// Allocate a buffer for Explorer.  Note that the must pass the string 
	// back as a Unicode string, so the string length is multiplied by the 
	// size of a Unicode character.
	*ppwszTip = (LPWSTR) pMalloc->Alloc ( (1 + lstrlen(sTooltip)) * sizeof(wchar_t) );

	// Release the IMalloc interface now that we're done using it.
	pMalloc->Release();

	if ( NULL == *ppwszTip )
	{
		return E_OUTOFMEMORY;
	}

	// Use the Unicode string copy function to put the tooltip text in the buffer.
	wcscpy ( *ppwszTip, T2COLE((LPCTSTR) sTooltip) );

	return S_OK;
}