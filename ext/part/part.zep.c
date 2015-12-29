
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
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/exit.h"


ZEPHIR_INIT_CLASS(Part_Part) {

	ZEPHIR_REGISTER_CLASS(Part, Part, part, part, part_part_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Part_Part, main_engine) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_GET, *main = NULL, *engine = NULL, *extension = NULL, *location = NULL, _5, *_0$$3 = NULL, *_1$$3, *_2$$3, *_3$$5, *_4$$5, *_6$$6, *_7$$8, *_8$$8, *_9$$11, *_10$$12, *_11$$13, *_12$$14;

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
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "config", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "index", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_0$$3, main, "config", NULL, 24, _1$$3, _2$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(_0$$3, "")) {
			ZEPHIR_INIT_NVAR(location);
			ZVAL_STRING(location, "index.p", 1);
		} else {
			ZEPHIR_INIT_VAR(_3$$5);
			ZVAL_STRING(_3$$5, "config", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_4$$5);
			ZVAL_STRING(_4$$5, "index", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&location, main, "config", NULL, 24, _3$$5, _4$$5);
			zephir_check_temp_parameter(_3$$5);
			zephir_check_temp_parameter(_4$$5);
			zephir_check_call_status();
		}
	}
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 4);
	ZEPHIR_CALL_FUNCTION(&extension, "pathinfo", NULL, 15, location, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, main, "notfound", NULL, 25, location);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_STRING(extension, "p")) {
			ZEPHIR_INIT_VAR(_6$$6);
			ZEPHIR_CONCAT_SVS(_6$$6, "static/", location, ".so");
			if (!((zephir_file_exists(_6$$6 TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_CALL_METHOD(NULL, engine, "engine", NULL, 3, location);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(_7$$8);
				ZEPHIR_CONCAT_SVS(_7$$8, "static/", location, ".so");
				ZEPHIR_INIT_VAR(_8$$8);
				ZVAL_STRING(_8$$8, "text/html", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, main, "content", NULL, 26, _7$$8, _8$$8);
				zephir_check_temp_parameter(_8$$8);
				zephir_check_call_status();
			}
			break;
		}
		if (ZEPHIR_IS_STRING(extension, "pp")) {
			ZEPHIR_MM_RESTORE();
			zephir_exit_empty();
			break;
		}
		if (ZEPHIR_IS_STRING(extension, "ini")) {
			ZEPHIR_MM_RESTORE();
			zephir_exit_empty();
			break;
		}
		if (ZEPHIR_IS_STRING(extension, "html")) {
			ZEPHIR_INIT_VAR(_9$$11);
			ZVAL_STRING(_9$$11, "text/html", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, main, "content", NULL, 26, location, _9$$11);
			zephir_check_temp_parameter(_9$$11);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(extension, "css")) {
			ZEPHIR_INIT_VAR(_10$$12);
			ZVAL_STRING(_10$$12, "text/css", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, main, "content", NULL, 26, location, _10$$12);
			zephir_check_temp_parameter(_10$$12);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(extension, "js")) {
			ZEPHIR_INIT_VAR(_11$$13);
			ZVAL_STRING(_11$$13, "application/javascript", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, main, "content", NULL, 26, location, _11$$13);
			zephir_check_temp_parameter(_11$$13);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_VAR(_12$$14);
		ZVAL_STRING(_12$$14, "text/plain", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, main, "content", NULL, 26, location, _12$$14);
		zephir_check_temp_parameter(_12$$14);
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
	ZEPHIR_CALL_FUNCTION(&plang, "file_get_contents", NULL, 14, location, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, library, "os", NULL, 27, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, library, "import", NULL, 28, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, library, "http", NULL, 29, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, library, "server", NULL, 30, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, library, "commands", NULL, 31, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, library, "file", NULL, 32, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, library, "mysql", NULL, 33, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, library, "mysqli", NULL, 34, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, library, "curl", NULL, 35, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, library, "load", NULL, 36, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, library, "session", NULL, 37, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, text, "variable", NULL, 38, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, text, "write", NULL, 39, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, text, "symbol", NULL, 40, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, text, "html", NULL, 41, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, functions, "def_function", NULL, 42, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, functions, "class_function", NULL, 43, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, functions, "call_function", NULL, 44, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, statement, "switch_statement", NULL, 45, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, statement, "while_statement", NULL, 46, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, statement, "if_statement", NULL, 47, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_CALL_METHOD(&_0, statement, "for_statement", NULL, 48, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_VAR(_1);
	zephir_eval_php(plang, _1, "/home/ubuntu/workspace/part/part/part.zep:85" TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

