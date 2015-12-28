
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
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Part_Lib_Compile) {

	ZEPHIR_REGISTER_CLASS(Part\\Lib, Compile, part, lib_compile, part_lib_compile_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Part_Lib_Compile, compile_engine) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location, *compiler = NULL, *result = NULL, *files = NULL, _0, _1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location);



	ZEPHIR_INIT_VAR(compiler);
	object_init_ex(compiler, part_part_ce);
	if (zephir_has_constructor(compiler TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, compiler, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(files);
	object_init_ex(files, part_lib_file_ce);
	if (zephir_has_constructor(files TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, files, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, compiler, "engine", NULL, 3, location);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "ob_get_contents", NULL, 4);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "static", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0700);
	ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 5, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVS(_2, "static/", location, ".so");
	ZEPHIR_CALL_METHOD(NULL, files, "create", NULL, 6, _2, result);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_flush", NULL, 7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVS(_3, " Compile ", location, " to static files success");
	zend_print_zval(_3, 0);
	ZEPHIR_MM_RESTORE();

}
