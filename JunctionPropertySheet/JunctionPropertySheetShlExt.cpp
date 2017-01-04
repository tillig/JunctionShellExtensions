// JunctionPropertySheetShlExt.cpp : Implementation of CJunctionPropertySheetShlExt

#include "stdafx.h"
#include "JunctionPropertySheetShlExt.h"
using namespace FSLinks;

// Functions to handle messages from the property page.
BOOL CALLBACK PropPageDlgProc ( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
UINT CALLBACK PropPageCallbackProc ( HWND hwnd, UINT uMsg, LPPROPSHEETPAGE ppsp );
BOOL OnInitDialog ( HWND hwnd, LPARAM lParam );
BOOL OnApply ( HWND hwnd, PSHNOTIFY* phdr );

// CJunctionPropertySheetShlExt

HRESULT CJunctionPropertySheetShlExt::Initialize(LPCITEMIDLIST pidlFolder,
												 LPDATAOBJECT pDataObj,
												 HKEY hProgID){
	UINT uNumFiles;
	HDROP hdrop;
	FORMATETC etc = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
	STGMEDIUM stg;
	INITCOMMONCONTROLSEX iccex = { sizeof(INITCOMMONCONTROLSEX), ICC_DATE_CLASSES };

	// Init the common controls.
	InitCommonControlsEx(&iccex);

	// Read the list of folders from the data object.  They're stored in HDROP
	// form, so just get the HDROP handle and then use the drag 'n' drop APIs
	// on it.
	if (FAILED(pDataObj->GetData(&etc, &stg))){
		return E_INVALIDARG;
	}

	// Get an HDROP handle.
	hdrop = (HDROP) GlobalLock(stg.hGlobal);

	if(NULL == hdrop){
		ReleaseStgMedium(&stg);
		return E_INVALIDARG;
	}

	// Determine how many files are involved in this operation.
	uNumFiles = DragQueryFile(hdrop, 0xFFFFFFFF, NULL, 0);

	// We only work on one file at a time.
	if(uNumFiles != 1){
		GlobalUnlock(stg.hGlobal);
		ReleaseStgMedium(&stg);
		return E_FAIL;
	}

	// Get the filename
	if (0 == DragQueryFile(hdrop, 0, m_filename, MAX_PATH)){
		GlobalUnlock(stg.hGlobal);
		ReleaseStgMedium(&stg);
		return E_FAIL;
	}

	// Check to see if it's a reparse point
	DWORD dwAttr = GetFileAttributes(m_filename);
	if(dwAttr == INVALID_FILE_ATTRIBUTES || !(dwAttr & FILE_ATTRIBUTE_REPARSE_POINT)){
		// An error occurred or it's not a reparse point
		GlobalUnlock(stg.hGlobal);
		ReleaseStgMedium(&stg);
		return E_FAIL;
	}
    
	// Release resources.
    GlobalUnlock(stg.hGlobal);
    ReleaseStgMedium(&stg);

    // We've got the filename; return OK
	return S_OK;
}

HRESULT CJunctionPropertySheetShlExt::AddPages (LPFNADDPROPSHEETPAGE lpfnAddPageProc,
												LPARAM lParam ){
	PROPSHEETPAGE psp;
	HPROPSHEETPAGE hPage;

	// Get a copy of the filename - that's the parameter
	LPCTSTR szFile = _tcsdup(m_filename);
	if ( NULL == szFile )
		return E_OUTOFMEMORY;

	// Set up the property sheet page
	psp.dwSize = sizeof(PROPSHEETPAGE);
	psp.dwFlags = PSP_USEREFPARENT | PSP_USECALLBACK | PSP_DEFAULT;
	psp.hInstance = _AtlBaseModule.GetModuleInstance();
	psp.pszTemplate = MAKEINTRESOURCE(IDD_PROPPAGE_SMALL);
	psp.pfnDlgProc = PropPageDlgProc;
	psp.lParam = (LPARAM)szFile;
	psp.pfnCallback = PropPageCallbackProc;
	psp.pcRefParent = (UINT*) &this->m_dwRef;

	// Create the property sheet page
	hPage = CreatePropertySheetPage(&psp);

	if ( NULL != hPage ){
		// Call the shell's callback function, so it adds the page to
		// the property sheet.
		if (!lpfnAddPageProc(hPage, lParam)){
			DestroyPropertySheetPage(hPage);
		}
		else{
			return S_OK;
		}
	}
	else{
			return E_OUTOFMEMORY;
	}
	return E_FAIL;
}

BOOL CALLBACK PropPageDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	BOOL bRet = FALSE;

	switch(uMsg){
		case WM_INITDIALOG:
			bRet = OnInitDialog ( hwnd, lParam );
			break;

		case WM_NOTIFY:
			{
				NMHDR* phdr = (NMHDR*) lParam;

				switch (phdr->code){
					case PSN_APPLY:
						bRet = OnApply(hwnd, (PSHNOTIFY*) phdr);
						break;
				}
			}
			break;
	}

	return bRet;
}

UINT CALLBACK PropPageCallbackProc(HWND hwnd, UINT uMsg, LPPROPSHEETPAGE ppsp){
	if(PSPCB_RELEASE == uMsg){
		free((void*)ppsp->lParam);
	}
	return 1;	// used for PSPCB_CREATE - let the page be created
}

BOOL OnInitDialog(HWND hwnd, LPARAM lParam){        
	PROPSHEETPAGE* ppsp = (PROPSHEETPAGE*) lParam;
	LPCTSTR szFile = (LPCTSTR) ppsp->lParam;

	// Get the reparse point destination
	const int bufSize = MAX_PATH * 3;
	TCHAR szDest[bufSize];
	const DWORD dwRet = FSLinks::GetJunctionPointInfo(szFile, szDest, bufSize);
	
	// Set the dialog box text
	if(dwRet == 0 || dwRet > bufSize){
		SetDlgItemText(hwnd, IDC_EDIT1, "Error reading junction info.");
	}
	else{
		TCHAR *finalString = NULL;
		if(_tcsncmp("\\??\\", szDest, 4) == 0){
			finalString = _tcsninc(szDest, 4);
		}
		else{
			finalString = szDest;
		}
		SetDlgItemText(hwnd, IDC_EDIT1, finalString);
	}

	return FALSE; // Take the default focus handling.
}

BOOL OnApply( HWND hwnd, PSHNOTIFY* phdr){
	// Return PSNRET_NOERROR to allow the sheet to close if the user clicked OK.
	SetWindowLong (hwnd, DWL_MSGRESULT, PSNRET_NOERROR);
	return TRUE;
}
