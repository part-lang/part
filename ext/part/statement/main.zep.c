
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


ZEPHIR_INIT_CLASS(Part_Statement_Main) {

	ZEPHIR_REGISTER_CLASS(Part\\Statement, Main, part, statement_main, part_statement_main_method_entry, 0);

	return SUCCESS;

}

/**
 * Load all statement
 */
PHP_METHOD(Part_Statement_Main, loader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *plang = NULL, plang_sub, statement, _0;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&statement);
	object_init_ex(&statement, part_statement_main_ce);
	if (zephir_has_constructor(&statement TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &statement, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_0, &statement, "switch_statement", NULL, 49, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &statement, "while_statement", NULL, 50, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &statement, "if_statement", NULL, 51, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &statement, "for_statement", NULL, 52, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * Switch statement usage:
 *<code>
 *      switch (statement)
 *
 *      case "1"
 *      print "Hello"
 *      break
 *
 *      end
 *</code>
 */
PHP_METHOD(Part_Statement_Main, switch_statement) {

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
	ZVAL_STRING(&_0, "/switch(.*)/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "switch $1 {");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/case(.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "case $1:");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/break/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "break;");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * While statement usage:
 *<code>
 *      while (statement)
 *
 *      end
 *</code>
 */
PHP_METHOD(Part_Statement_Main, while_statement) {

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
	ZVAL_STRING(&_0, "/while(.*)/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "while $1 {");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", NULL, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * IF statement usage:
 *<code>
 *      if (statement)
 *		else
 *      end
 *</code>
 */
PHP_METHOD(Part_Statement_Main, if_statement) {

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
	ZVAL_STRING(&_0, "/if(.*)/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "if $1 {");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/elseif(.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "} elseif $1 {");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/else/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "}else{");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/end/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "}");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * For & Foreach statement usage:
 *<code>
 *      for (statement)
 *
 *      end
 *
 *		foreach (statement)
 *
 *		end
 *</code>
 */
PHP_METHOD(Part_Statement_Main, for_statement) {

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
	ZVAL_STRING(&_0, "/for\\((.*)\\)/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "for($1){");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/for \\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "for($1){");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/foreach(.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "foreach $1 {");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

