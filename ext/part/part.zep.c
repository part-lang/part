
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Part_Part) {

	ZEPHIR_REGISTER_CLASS(Part, Part, part, part, part_part_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Part_Part, main_engine) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_GET, *main = NULL, *engine = NULL, *extension = NULL, *location = NULL, _0, *_1$$5, *_2$$6, *_3$$7, *_4$$8;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);

	ZEPHIR_OBS_VAR(location);
	zephir_array_fetch_string(&location, _GET, SL("_url"), PH_NOISY, "part/part.zep", 7 TSRMLS_CC);
	ZEPHIR_INIT_VAR(main);
	object_init_ex(main, part_page_main_ce);
	if (zephir_has_constructor(main TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, main, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(engine);
	object_init_ex(engine, part_part_ce);
	if (zephir_has_constructor(engine TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, engine, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_STRING(location, "")) {
		ZEPHIR_INIT_NVAR(location);
		ZVAL_STRING(location, "index.p", 1);
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&extension, "pathinfo", NULL, 5, location, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, main, "notfound", NULL, 6, location);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_STRING(extension, "p")) {
			ZEPHIR_CALL_METHOD(NULL, engine, "engine", NULL, 7, location);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(extension, "html")) {
			ZEPHIR_INIT_VAR(_1$$5);
			ZVAL_STRING(_1$$5, "text/html", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, main, "content", NULL, 8, location, _1$$5);
			zephir_check_temp_parameter(_1$$5);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(extension, "css")) {
			ZEPHIR_INIT_VAR(_2$$6);
			ZVAL_STRING(_2$$6, "text/css", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, main, "content", NULL, 8, location, _2$$6);
			zephir_check_temp_parameter(_2$$6);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(extension, "js")) {
			ZEPHIR_INIT_VAR(_3$$7);
			ZVAL_STRING(_3$$7, "application/javascript", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, main, "content", NULL, 8, location, _3$$7);
			zephir_check_temp_parameter(_3$$7);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_VAR(_4$$8);
		ZVAL_STRING(_4$$8, "text/plain", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, main, "content", NULL, 8, location, _4$$8);
		zephir_check_temp_parameter(_4$$8);
		zephir_check_call_status();
	} while(0);

	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Part_Part, engine) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location, *plang = NULL, *statement = NULL, *text = NULL, *functions = NULL, *library = NULL, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location);



	ZEPHIR_INIT_VAR(statement);
	object_init_ex(statement, part_statement_main_ce);
	if (zephir_has_constructor(statement TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, statement, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(text);
	object_init_ex(text, part_text_main_ce);
	if (zephir_has_constructor(text TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, text, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(functions);
	object_init_ex(functions, part_function_main_ce);
	if (zephir_has_constructor(functions TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, functions, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(library);
	object_init_ex(library, part_lib_main_ce);
	if (zephir_has_constructor(library TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, library, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&plang, "file_get_contents", NULL, 4, location, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, library, "os", NULL, 9, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, library, "import", NULL, 10, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, library, "http", NULL, 11, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, library, "server", NULL, 12, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, library, "commands", NULL, 13, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, library, "file", NULL, 14, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, text, "variable", NULL, 15, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, text, "write", NULL, 16, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, text, "symbol", NULL, 17, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, text, "html", NULL, 18, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, functions, "def_function", NULL, 19, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, functions, "class_function", NULL, 20, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, functions, "call_function", NULL, 21, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, statement, "switch_statement", NULL, 22, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, statement, "while_statement", NULL, 23, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, statement, "if_statement", NULL, 24, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, statement, "for_statement", NULL, 25, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_VAR(_1);
	zephir_eval_php(plang, _1, "/home/ubuntu/workspace/part/part/part.zep:62" TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

