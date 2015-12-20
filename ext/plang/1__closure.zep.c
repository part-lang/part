
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(plang_1__closure) {

	ZEPHIR_REGISTER_CLASS(plang, 1__closure, plang, 1__closure, plang_1__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(plang_1__closure, __invoke) {

	zval *matches, *_0;

	zephir_fetch_params(0, 1, 0, &matches);



	zephir_array_fetch_long(&_0, matches, 1, PH_NOISY | PH_READONLY, "plang/main/plang.zep", 14 TSRMLS_CC);
	zend_print_zval(_0, 0);

}

