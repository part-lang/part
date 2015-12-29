
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


ZEPHIR_INIT_CLASS(Part_Lib_Load) {

	ZEPHIR_REGISTER_CLASS(Part\\Lib, Load, part, lib_load, part_lib_load_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Part_Lib_Load, load_view) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location, *extension = NULL, *code = NULL, *part = NULL, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location);



	ZEPHIR_INIT_VAR(part);
	object_init_ex(part, part_part_ce);
	if (zephir_has_constructor(part TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, part, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&code, "file_get_contents", NULL, 13, location, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&extension, "pathinfo", NULL, 14, location, &_0);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_STRING(extension, "p")) {
			ZEPHIR_CALL_METHOD(NULL, part, "engine", NULL, 3, location);
			zephir_check_call_status();
			break;
		}
		RETURN_CCTOR(code);
	} while(0);

	ZEPHIR_MM_RESTORE();

}

