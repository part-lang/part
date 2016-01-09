
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


ZEPHIR_INIT_CLASS(Part_Lib_Cli) {

	ZEPHIR_REGISTER_CLASS(Part\\Lib, Cli, part, lib_cli, part_lib_cli_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Part_Lib_Cli, cli_engine) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location, location_sub, runtime;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&location_sub);
	ZVAL_UNDEF(&runtime);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location);



	ZEPHIR_INIT_VAR(&runtime);
	object_init_ex(&runtime, part_part_ce);
	if (zephir_has_constructor(&runtime TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &runtime, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &runtime, "engine", NULL, 6, location);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

