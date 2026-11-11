#ifndef QJS_COMPAT_H
#define QJS_COMPAT_H
#include "quickjs.h"
/* Unison fork: API differences between Bellard QuickJS and quickjs-ng */
#ifdef QJS_NG
#define QJS_IS_ARRAY(ctx, v) JS_IsArray(v)
#define QJS_IS_ERROR(ctx, v) JS_IsError(v)
typedef bool qjs_bool_t;
#else
#define QJS_IS_ARRAY(ctx, v) JS_IsArray(ctx, v)
#define QJS_IS_ERROR(ctx, v) JS_IsError(ctx, v)
typedef int qjs_bool_t;
#endif
#endif
