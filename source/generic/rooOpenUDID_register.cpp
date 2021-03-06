/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/*
 * This file contains the automatically generated loader-side
 * functions that form part of the extension.
 *
 * This file is awlays compiled into all loaders but compiles
 * to nothing if this extension is not enabled in the loader
 * at build time.
 */
#include "IwDebug.h"
#include "rooOpenUDID_autodefs.h"
#include "s3eEdk.h"
#include "rooOpenUDID.h"
//Declarations of Init and Term functions
extern s3eResult rooOpenUDIDInit();
extern void rooOpenUDIDTerminate();


// On platforms that use a seperate UI/OS thread we can autowrap functions
// here.   Note that we can't use the S3E_USE_OS_THREAD define since this
// code is oftern build standalone, outside the main loader build.
#if defined I3D_OS_IPHONE || defined I3D_OS_OSX || defined I3D_OS_LINUX || defined I3D_OS_WINDOWS

static void rooOpenUDID_init_wrap()
{
    IwTrace(ROOOPENUDID_VERBOSE, ("calling rooOpenUDID func on main thread: rooOpenUDID_init"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooOpenUDID_init, 0);
}

static bool rooOpenUDID_isInitialized_wrap()
{
    IwTrace(ROOOPENUDID_VERBOSE, ("calling rooOpenUDID func on main thread: rooOpenUDID_isInitialized"));
    return (bool)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooOpenUDID_isInitialized, 0);
}

static const char * rooOpenUDID_getValue_wrap()
{
    IwTrace(ROOOPENUDID_VERBOSE, ("calling rooOpenUDID func on main thread: rooOpenUDID_getValue"));
    return (const char *)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)rooOpenUDID_getValue, 0);
}

#define rooOpenUDID_init rooOpenUDID_init_wrap
#define rooOpenUDID_isInitialized rooOpenUDID_isInitialized_wrap
#define rooOpenUDID_getValue rooOpenUDID_getValue_wrap

#endif

void rooOpenUDIDRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[3];
    funcPtrs[0] = (void*)rooOpenUDID_init;
    funcPtrs[1] = (void*)rooOpenUDID_isInitialized;
    funcPtrs[2] = (void*)rooOpenUDID_getValue;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[3] = { 0 };

    /*
     * Register the extension
     */
    s3eEdkRegister("rooOpenUDID", funcPtrs, sizeof(funcPtrs), flags, rooOpenUDIDInit, rooOpenUDIDTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int rooOpenUDIDStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&rooOpenUDIDRegisterExt;
    return 0;
}

int g_rooOpenUDIDVal = rooOpenUDIDStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    rooOpenUDIDRegisterExt();
}
#endif

#endif
