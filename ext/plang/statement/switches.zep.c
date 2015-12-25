
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


ZEPHIR_INIT_CLASS(Plang_Statement_Switches) {

	ZEPHIR_REGISTER_CLASS(Plang\\Statement, Switches, plang, statement_switches, plang_statement_switches_method_entry, 0);

	return SUCCESS;

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
PHP_METHOD(Plang_Statement_Switches, switchs) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *plang = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "/switch(.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "switch $1 {", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 6, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/case(.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "case $1:", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 6, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/break/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "break;", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 6, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

