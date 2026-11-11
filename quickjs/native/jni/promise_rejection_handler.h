#ifndef QJS_KT_PROMISE_REJECTION_HANDLER_H
#define QJS_KT_PROMISE_REJECTION_HANDLER_H

#include "quickjs.h"
#include "qjs_compat.h"

void promise_rejection_handler(JSContext *ctx, JSValue promise,
                               JSValue reason,
                               qjs_bool_t is_handled, void *opaque);

#endif //QJS_KT_PROMISE_REJECTION_HANDLER_H
