
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/file.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/exit.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Plang_Main_Plang) {

	ZEPHIR_REGISTER_CLASS(Plang\\Main, Plang, plang, main_plang, plang_main_plang_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Plang_Main_Plang, main_engine) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_9 = NULL;
	zval *location = NULL, *plang = NULL, *_4 = NULL, _5, _6, *_7 = NULL, *_8 = NULL, _0$$4 = zval_used_for_init, *_2$$4 = NULL, *_3$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location);

	ZEPHIR_SEPARATE_PARAM(location);


	if (ZEPHIR_IS_STRING(location, "")) {
		ZEPHIR_INIT_NVAR(location);
		ZVAL_STRING(location, "index.p", 1);
	}
	if (!((zephir_file_exists(location TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_SINIT_VAR(_0$$4);
		ZVAL_STRING(&_0$$4, "HTTP/1.1 404 Not Found", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 1, &_0$$4);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0$$4);
		ZVAL_STRING(&_0$$4, "D, d M Y h:i:s T", 0);
		ZEPHIR_CALL_FUNCTION(&_2$$4, "date", NULL, 2, &_0$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SV(_3$$4, "Date: ", _2$$4);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 1, _3$$4);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0$$4);
		ZVAL_STRING(&_0$$4, "Content-Type: text/html; charset=iso-8859-1", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 1, &_0$$4);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0$$4);
		ZVAL_STRING(&_0$$4, "X-Powered-By: P language", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 1, &_0$$4);
		zephir_check_call_status();
		php_printf("%s", "404 Not Found");
		ZEPHIR_MM_RESTORE();
		zephir_exit_empty();
	}
	ZEPHIR_CALL_FUNCTION(&plang, "file_get_contents", NULL, 3, location, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "time.now()", 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "date('H:i:s');", 0);
	zephir_fast_str_replace(&_4, &_5, &_6, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "/import '(.*)'/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_STRING(_7, "include('$1');", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_8, "preg_replace", &_9, 4, _4, _7, plang);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _8);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "/var (.*) = (.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "$$1 = $2;", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_8, "preg_replace", &_9, 4, _4, _7, plang);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _8);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "/strlen.(.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "strlen($$1)", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_8, "preg_replace", &_9, 4, _4, _7, plang);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _8);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "/string.(.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "$$1", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_8, "preg_replace", &_9, 4, _4, _7, plang);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _8);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "/htmlescape.(.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "htmlspecialchars($$1)", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_8, "preg_replace", &_9, 4, _4, _7, plang);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _8);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "/print (.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "echo $1;", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_8, "preg_replace", &_9, 4, _4, _7, plang);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _8);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "/if\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "if($1){;", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_8, "preg_replace", &_9, 4, _4, _7, plang);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _8);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "/else/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "}else{", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_8, "preg_replace", &_9, 4, _4, _7, plang);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _8);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "/end/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "}", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_8, "preg_replace", &_9, 4, _4, _7, plang);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _8);
	ZEPHIR_INIT_NVAR(_4);
	zephir_eval_php(plang, _4, "/home/ubuntu/workspace/plang/plang/main/plang.zep:32" TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

