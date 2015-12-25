
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Plang_Lib_Main) {

	ZEPHIR_REGISTER_CLASS(Plang\\Lib, Main, plang, lib_main, plang_lib_main_method_entry, 0);

	return SUCCESS;

}

/**
 * Import usage:
 *<code>
 *      import 'file.html'
 *</code>
 */
PHP_METHOD(Plang_Lib_Main, import) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *plang = NULL, *_0, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "/import '(.*)'/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "include('$1');", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", NULL, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * HTTP usage:
 *<code>
 *      http.get("url")
 *      http.post("post")
 *      http.request("req")
 *</code>
 */
PHP_METHOD(Plang_Lib_Main, http) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *plang = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "/http.get\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "$_GET[$1];", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/http.request\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "$_REQUEST[$1];", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/http.post\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "$_POST[$1];", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * OS usage:
 *<code>
 *      os.kernel()
 *      os.user()
 *      os.type()
 *</code>
 */
PHP_METHOD(Plang_Lib_Main, os) {

	zval *plang = NULL, *_0 = NULL, _1, _2, _3, _4, _5, _6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "os.kernel()", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "exec('uname -r');", 0);
	zephir_fast_str_replace(&_0, &_1, &_2, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "os.user()", 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "exec('whoami');", 0);
	zephir_fast_str_replace(&_0, &_3, &_4, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "os.type()", 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "exec('uname -o');", 0);
	zephir_fast_str_replace(&_0, &_5, &_6, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * Command usage:
 *<code>
 *      cmd("commands")
 *      system("commands")
 *      exec("commands")
 *</code>
 */
PHP_METHOD(Plang_Lib_Main, commands) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *plang = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "/cmd\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "exec($1);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/system\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "exec($1);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/exec\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "exec($1);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

