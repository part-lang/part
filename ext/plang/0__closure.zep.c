
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
#include "kernel/fcall.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(plang_0__closure) {

	ZEPHIR_REGISTER_CLASS(plang, 0__closure, plang, 0__closure, plang_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(plang_0__closure, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *matches, *teks = NULL, *_0, *_1, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &matches);



	zephir_array_fetch_long(&_0, matches, 1, PH_NOISY | PH_READONLY, "plang/main/plang.zep", 10 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&teks, "file_get_contents", NULL, 1, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "#main/plang", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "<?php", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_3, "preg_replace", NULL, 2, _1, _2, teks);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(teks, _3);
	zephir_eval_php(teks, return_value, "/home/ubuntu/workspace/plang/plang/main/plang.zep:12" TSRMLS_CC);
	RETURN_MM();

}

