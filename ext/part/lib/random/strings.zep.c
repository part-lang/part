
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Part_Lib_Random_Strings) {

	ZEPHIR_REGISTER_CLASS(Part\\Lib\\Random, Strings, part, lib_random_strings, part_lib_random_strings_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Part_Lib_Random_Strings, random) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *length = NULL, length_sub, _0, _1, _2;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&length_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &length);

	if (!length) {
		length = &length_sub;
		ZEPHIR_INIT_VAR(length);
		ZVAL_LONG(length, 10);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	ZEPHIR_CALL_FUNCTION(&_1, "str_shuffle", NULL, 38, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 0);
	zephir_substr(return_value, &_1, 0 , zephir_get_intval(length), 0);
	RETURN_MM();

}

