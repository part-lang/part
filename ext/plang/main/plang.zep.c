
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Plang_Main_Plang) {

	ZEPHIR_REGISTER_CLASS(Plang\\Main, Plang, plang, main_plang, plang_main_plang_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Plang_Main_Plang, main_engine) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *location, *plang = NULL, *_0 = NULL, _1, _2, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location);



	ZEPHIR_CALL_FUNCTION(&plang, "file_get_contents", NULL, 1, location, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "time.now()", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "date('H:i:s');", 0);
	zephir_fast_str_replace(&_0, &_1, &_2, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/import '(.*)'/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "include('$1');", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_4, "preg_replace", &_5, 2, _0, _3, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _4);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/var (.*) = (.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "$$1 = $2;", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_4, "preg_replace", &_5, 2, _0, _3, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _4);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/main.(.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "$$1", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_4, "preg_replace", &_5, 2, _0, _3, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _4);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/write (.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "echo $1;", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_4, "preg_replace", &_5, 2, _0, _3, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _4);
	ZEPHIR_INIT_NVAR(_0);
	zephir_eval_php(plang, _0, "/home/ubuntu/workspace/plang/plang/main/plang.zep:14" TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

