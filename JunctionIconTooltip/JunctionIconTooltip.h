

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Wed Jun 29 16:18:01 2005
 */
/* Compiler settings for .\JunctionIconTooltip.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __JunctionIconTooltip_h__
#define __JunctionIconTooltip_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IJunctionTooltipShlExt_FWD_DEFINED__
#define __IJunctionTooltipShlExt_FWD_DEFINED__
typedef interface IJunctionTooltipShlExt IJunctionTooltipShlExt;
#endif 	/* __IJunctionTooltipShlExt_FWD_DEFINED__ */


#ifndef __JunctionTooltipShlExt_FWD_DEFINED__
#define __JunctionTooltipShlExt_FWD_DEFINED__

#ifdef __cplusplus
typedef class JunctionTooltipShlExt JunctionTooltipShlExt;
#else
typedef struct JunctionTooltipShlExt JunctionTooltipShlExt;
#endif /* __cplusplus */

#endif 	/* __JunctionTooltipShlExt_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IJunctionTooltipShlExt_INTERFACE_DEFINED__
#define __IJunctionTooltipShlExt_INTERFACE_DEFINED__

/* interface IJunctionTooltipShlExt */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IJunctionTooltipShlExt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("865757CF-D094-4A14-819F-EAB0CB4757D3")
    IJunctionTooltipShlExt : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IJunctionTooltipShlExtVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IJunctionTooltipShlExt * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IJunctionTooltipShlExt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IJunctionTooltipShlExt * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IJunctionTooltipShlExt * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IJunctionTooltipShlExt * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IJunctionTooltipShlExt * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IJunctionTooltipShlExt * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IJunctionTooltipShlExtVtbl;

    interface IJunctionTooltipShlExt
    {
        CONST_VTBL struct IJunctionTooltipShlExtVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IJunctionTooltipShlExt_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IJunctionTooltipShlExt_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IJunctionTooltipShlExt_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IJunctionTooltipShlExt_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IJunctionTooltipShlExt_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IJunctionTooltipShlExt_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IJunctionTooltipShlExt_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IJunctionTooltipShlExt_INTERFACE_DEFINED__ */



#ifndef __JunctionIconTooltipLib_LIBRARY_DEFINED__
#define __JunctionIconTooltipLib_LIBRARY_DEFINED__

/* library JunctionIconTooltipLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_JunctionIconTooltipLib;

EXTERN_C const CLSID CLSID_JunctionTooltipShlExt;

#ifdef __cplusplus

class DECLSPEC_UUID("088C74CA-76D2-4C1F-A411-D13736875597")
JunctionTooltipShlExt;
#endif
#endif /* __JunctionIconTooltipLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


