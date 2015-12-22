
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
	zephir_fcall_cache_entry *_1 = NULL, *_6 = NULL, *_24 = NULL;
	zval *location = NULL, *plang = NULL, _4, *_5 = NULL, _0$$4 = zval_used_for_init, *_2$$4 = NULL, *_3$$4, *_7$$5 = NULL, _8$$5, _9$$5, _10$$5, _11$$5, _12$$5, _13$$5, _14$$5, _15$$5, _16$$5, _17$$5, _18$$5, _19$$5, _20$$5, _21$$5, *_22$$5 = NULL, *_23$$5 = NULL;

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
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 4);
	ZEPHIR_CALL_FUNCTION(&_5, "pathinfo", NULL, 3, location, &_4);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(_5, "p")) {
		ZEPHIR_CALL_FUNCTION(&plang, "file_get_contents", &_6, 4, location, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_7$$5);
		ZEPHIR_SINIT_VAR(_8$$5);
		ZVAL_STRING(&_8$$5, "os.kernel()", 0);
		ZEPHIR_SINIT_VAR(_9$$5);
		ZVAL_STRING(&_9$$5, "exec('uname -r');", 0);
		zephir_fast_str_replace(&_7$$5, &_8$$5, &_9$$5, plang TSRMLS_CC);
		ZEPHIR_CPY_WRT(plang, _7$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZEPHIR_SINIT_VAR(_10$$5);
		ZVAL_STRING(&_10$$5, "os.user()", 0);
		ZEPHIR_SINIT_VAR(_11$$5);
		ZVAL_STRING(&_11$$5, "exec('whoami');", 0);
		zephir_fast_str_replace(&_7$$5, &_10$$5, &_11$$5, plang TSRMLS_CC);
		ZEPHIR_CPY_WRT(plang, _7$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZEPHIR_SINIT_VAR(_12$$5);
		ZVAL_STRING(&_12$$5, "os.type()", 0);
		ZEPHIR_SINIT_VAR(_13$$5);
		ZVAL_STRING(&_13$$5, "exec('uname -o');", 0);
		zephir_fast_str_replace(&_7$$5, &_12$$5, &_13$$5, plang TSRMLS_CC);
		ZEPHIR_CPY_WRT(plang, _7$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZEPHIR_SINIT_VAR(_14$$5);
		ZVAL_STRING(&_14$$5, "time.now()", 0);
		ZEPHIR_SINIT_VAR(_15$$5);
		ZVAL_STRING(&_15$$5, "date('H:i:s');", 0);
		zephir_fast_str_replace(&_7$$5, &_14$$5, &_15$$5, plang TSRMLS_CC);
		ZEPHIR_CPY_WRT(plang, _7$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZEPHIR_SINIT_VAR(_16$$5);
		ZVAL_STRING(&_16$$5, "|", 0);
		ZEPHIR_SINIT_VAR(_17$$5);
		ZVAL_STRING(&_17$$5, ";", 0);
		zephir_fast_str_replace(&_7$$5, &_16$$5, &_17$$5, plang TSRMLS_CC);
		ZEPHIR_CPY_WRT(plang, _7$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZEPHIR_SINIT_VAR(_18$$5);
		ZVAL_STRING(&_18$$5, "plang:", 0);
		ZEPHIR_SINIT_VAR(_19$$5);
		ZVAL_STRING(&_19$$5, "<?php", 0);
		zephir_fast_str_replace(&_7$$5, &_18$$5, &_19$$5, plang TSRMLS_CC);
		ZEPHIR_CPY_WRT(plang, _7$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZEPHIR_SINIT_VAR(_20$$5);
		ZVAL_STRING(&_20$$5, "html:", 0);
		ZEPHIR_SINIT_VAR(_21$$5);
		ZVAL_STRING(&_21$$5, "?>", 0);
		zephir_fast_str_replace(&_7$$5, &_20$$5, &_21$$5, plang TSRMLS_CC);
		ZEPHIR_CPY_WRT(plang, _7$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/http.get\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_22$$5);
		ZVAL_STRING(_22$$5, "$_GET[$1];", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/http.request\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "$_REQUEST[$1];", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/http.post\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "$_POST[$1];", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/cmd\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "exec($1);", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/import '(.*)'/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "include('$1');", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/var (.*) = (.*)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "$$1 = $2;", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/var (.*)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "$$1", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/strlen.(.*)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "strlen($$1)", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/string.(.*)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "$$1", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/var.(.*)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "$$1", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/htmlescape.(.*)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "htmlspecialchars($$1)", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/write (.*)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, ";echo $1;", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/print (.*)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, ";echo $1;", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/return (.*)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, ";return $1;", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/if (.*)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "if($1){", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/elseif (.*)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "} else if($1){", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/for\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "for($1){", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/foreach\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "foreach($1){", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/(.*)\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, ";$1($2)", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/def (.*)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "function $1{", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/else/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "}else{", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/end/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "}", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/class (.*)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "class $1 {", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/def (.*)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "function $1{", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/public (.*) = (.*)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "public $$1 = $2", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/this->(.*)/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "$this->$1;", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		ZVAL_STRING(_7$$5, "/%(.*)%/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_22$$5);
		ZVAL_STRING(_22$$5, "<?php echo $1;?>", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_23$$5, "preg_replace", &_24, 5, _7$$5, _22$$5, plang);
		zephir_check_temp_parameter(_7$$5);
		zephir_check_temp_parameter(_22$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(plang, _23$$5);
		ZEPHIR_INIT_NVAR(_7$$5);
		zephir_eval_php(plang, _7$$5, "/home/ubuntu/workspace/plang/plang/main/plang.zep:57" TSRMLS_CC);
	} else {
		ZEPHIR_CALL_FUNCTION(&plang, "file_get_contents", &_6, 4, location, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		zend_print_zval(plang, 0);
	}
	ZEPHIR_MM_RESTORE();

}

