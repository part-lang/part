
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


ZEPHIR_INIT_CLASS(Part_Text_Main) {

	ZEPHIR_REGISTER_CLASS(Part\\Text, Main, part, text_main, part_text_main_method_entry, 0);

	return SUCCESS;

}

/**
 * Load all text
 */
PHP_METHOD(Part_Text_Main, loader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *plang = NULL, plang_sub, text, _0;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&text);
	object_init_ex(&text, part_text_main_ce);
	if (zephir_has_constructor(&text TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &text, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_0, &text, "variable", NULL, 54, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &text, "write", NULL, 55, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &text, "symbol", NULL, 56, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &text, "html", NULL, 57, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * HTML Template
 */
PHP_METHOD(Part_Text_Main, html) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *plang = NULL, plang_sub, _0, _1, _2;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/%(.*)%/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "<?php echo $1;?>");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", NULL, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * Symbol
 */
PHP_METHOD(Part_Text_Main, symbol) {

	zval *plang = NULL, plang_sub, _0, _1, _2, _3, _4, _5, _6;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "|");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, ";");
	zephir_fast_str_replace(&_0, &_1, &_2, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "part:");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "<?php");
	zephir_fast_str_replace(&_0, &_3, &_4, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "html:");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "?>");
	zephir_fast_str_replace(&_0, &_5, &_6, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * Print usage:
 *<code>
 *      print "Hello World"
 *      write "Hello World"
 *      return "Hello World"
 *</code>
 */
PHP_METHOD(Part_Text_Main, write) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *plang = NULL, plang_sub, _0, _1, _2;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/write (.*)/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ";echo $1;");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/print (.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, ";echo $1;");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/return (.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, ";return $1;");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * Variable usage:
 *<code>
 *      @hello = "Hello World"
 *      print @hello
 *</code>
 */
PHP_METHOD(Part_Text_Main, variable) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *plang = NULL, plang_sub, _0, _1, _2;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/@(.*) = (.*)/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "$$1 = $2;");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*) = (.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1 = $2;");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*) = (.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1 = $2;");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*) = (.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1 = $2;");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*) = (.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1 = $2;");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*) = (.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1 = $2;");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@(.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$$1");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/const (.*) = (.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "const $1 = $2;");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

