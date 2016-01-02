
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
#include "kernel/file.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Part_Lib_Compile) {

	ZEPHIR_REGISTER_CLASS(Part\\Lib, Compile, part, lib_compile, part_lib_compile_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Part_Lib_Compile, compile_engine) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location, location_sub, compiler, result, files, _0, _3, _4, _1$$3, _2$$3;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&location_sub);
	ZVAL_UNDEF(&compiler);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location);



	ZEPHIR_INIT_VAR(&compiler);
	object_init_ex(&compiler, part_part_ce);
	if (zephir_has_constructor(&compiler TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &compiler, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&files);
	object_init_ex(&files, part_lib_compile_ce);
	if (zephir_has_constructor(&files TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &files, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &compiler, "engine", NULL, 3, location);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "ob_get_contents", NULL, 4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "static");
	if (!((zephir_file_exists(&_0 TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "static");
		ZVAL_LONG(&_2$$3, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 5, &_1$$3, &_2$$3);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVS(&_3, "static/", location, ".static");
	ZEPHIR_CALL_METHOD(NULL, &files, "create", NULL, 6, &_3, &result);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_flush", NULL, 7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SVS(&_4, " Compile ", location, " to static files success");
	zend_print_zval(&_4, 0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Part_Lib_Compile, create) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, *content_param = NULL, file, _0;
	zval location, content;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&location);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &location_param, &content_param);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(&location, location_param);
	} else {
		ZEPHIR_INIT_VAR(&location);
		ZVAL_EMPTY_STRING(&location);
	}
	if (unlikely(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(&content, content_param);
	} else {
		ZEPHIR_INIT_VAR(&content);
		ZVAL_EMPTY_STRING(&content);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "w");
	ZEPHIR_CALL_FUNCTION(&file, "fopen", NULL, 8, &location, &_0);
	zephir_check_call_status();
	zephir_fwrite(NULL, &file, &content TSRMLS_CC);
	zephir_fclose(&file TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

