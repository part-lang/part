
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
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/exit.h"


ZEPHIR_INIT_CLASS(Plang_Main_Plang) {

	ZEPHIR_REGISTER_CLASS(Plang\\Main, Plang, plang, main_plang, plang_main_plang_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Plang_Main_Plang, main_engine) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location = NULL, *main = NULL, *extension = NULL, _0, *_1$$5, *_2$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location);

	ZEPHIR_SEPARATE_PARAM(location);


	ZEPHIR_INIT_VAR(main);
	object_init_ex(main, plang_main_plang_ce);
	if (zephir_has_constructor(main TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, main, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_STRING(location, "")) {
		ZEPHIR_INIT_NVAR(location);
		ZVAL_STRING(location, "index.p", 1);
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&extension, "pathinfo", NULL, 1, location, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, main, "notfound", NULL, 2, location);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(extension, "p")) {
		ZEPHIR_CALL_METHOD(NULL, main, "engine", NULL, 3, location);
		zephir_check_call_status();
	} else if (ZEPHIR_IS_STRING(extension, "html")) {
		ZEPHIR_INIT_VAR(_1$$5);
		ZVAL_STRING(_1$$5, "text/html", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, main, "content", NULL, 4, location, _1$$5);
		zephir_check_temp_parameter(_1$$5);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_2$$6);
		ZVAL_STRING(_2$$6, "text/plain", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, main, "content", NULL, 4, location, _2$$6);
		zephir_check_temp_parameter(_2$$6);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Plang_Main_Plang, engine) {

	zephir_fcall_cache_entry *_17 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *location, *plang = NULL, *_0 = NULL, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, *_15 = NULL, *_16 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location);



	ZEPHIR_CALL_FUNCTION(&plang, "file_get_contents", NULL, 5, location, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
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
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "time.now()", 0);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, "date('H:i:s');", 0);
	zephir_fast_str_replace(&_0, &_7, &_8, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_STRING(&_9, "|", 0);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_STRING(&_10, ";", 0);
	zephir_fast_str_replace(&_0, &_9, &_10, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_STRING(&_11, "plang:", 0);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_STRING(&_12, "<?php", 0);
	zephir_fast_str_replace(&_0, &_11, &_12, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_STRING(&_13, "html:", 0);
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_STRING(&_14, "?>", 0);
	zephir_fast_str_replace(&_0, &_13, &_14, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/http.get\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_15);
	ZVAL_STRING(_15, "$_GET[$1];", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/http.request\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "$_REQUEST[$1];", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/http.post\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "$_POST[$1];", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/cmd\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "exec($1);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/import '(.*)'/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "include('$1');", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/var (.*) = (.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "$$1 = $2;", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/var (.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "$$1", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/strlen.(.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "strlen($$1)", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/string.(.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "$$1", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/var.(.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "$$1", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/htmlescape.(.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "htmlspecialchars($$1)", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/write (.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, ";echo $1;", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/print (.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, ";echo $1;", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/return (.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, ";return $1;", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/if\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "if($1){", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/elseif (.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "} else if($1){", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/for\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "for($1){", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/foreach\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "foreach($1){", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/call (.*)\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "$1($2);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/(.*)\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "$1($2)", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/def (.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "function $1 {", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/def (.*)\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "function $1($2) {", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/else/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "}else{", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/end/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "}", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/class (.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "class $1 {", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/public (.*) = (.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "public $$1 = $2;", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/this->(.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "$this->$1;", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/%(.*)%/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "<?php echo $1;?>", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 6, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	zephir_eval_php(plang, _0, "/home/ubuntu/workspace/plang/plang/main/plang.zep:63" TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Plang_Main_Plang, content) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location, *type_header, *plang = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &location, &type_header);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "Content-Type: ", type_header, "; charset=iso-8859-1");
	ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 7, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&plang, "file_get_contents", NULL, 5, location, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	zend_print_zval(plang, 0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Plang_Main_Plang, notfound) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *location, _0$$3 = zval_used_for_init, *_2$$3 = NULL, *_3$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location);



	if (!((zephir_file_exists(location TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, "HTTP/1.1 404 Not Found", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 7, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0$$3);
		ZVAL_STRING(&_0$$3, "D, d M Y h:i:s T", 0);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "date", NULL, 8, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, "Date: ", _2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 7, _3$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0$$3);
		ZVAL_STRING(&_0$$3, "Content-Type: text/html; charset=iso-8859-1", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 7, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0$$3);
		ZVAL_STRING(&_0$$3, "X-Powered-By: P language", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 7, &_0$$3);
		zephir_check_call_status();
		php_printf("%s", "404 Not Found");
		ZEPHIR_MM_RESTORE();
		zephir_exit_empty();
	}
	ZEPHIR_MM_RESTORE();

}

