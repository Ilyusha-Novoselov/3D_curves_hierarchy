#ifdef CURVES_DLL_EXPORT
#define CURVES_DLL_API __declspec(dllexport)
#else
#define CURVES_DLL_API __declspec(dllimport)
#endif