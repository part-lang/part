
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/file.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Part_Part) {

	ZEPHIR_REGISTER_CLASS(Part, Part, part, part, part_part_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Part_Part, main_engine) {

	zephir_fcall_cache_entry *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval _SERVER, __$true, main, extension, location, phplang, _0, _1, _7, _2$$3, _3$$3, _4$$3, _5$$5, _6$$5, _8$$6, _10$$8, _11$$8, _12$$9, _13$$9, _14$$9, _15$$12, _16$$13, _17$$14, _18$$15;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&_SERVER);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&main);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&location);
	ZVAL_UNDEF(&phplang);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_18$$15);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));

	zephir_array_fetch_string(&_0, &_SERVER, SL("SCRIPT_NAME"), PH_NOISY | PH_READONLY, "part/part.zep", 7 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	ZEPHIR_INIT_VAR(&location);
	zephir_fast_trim(&location, &_0, &_1, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(&main);
	object_init_ex(&main, part_page_main_ce);
	if (zephir_has_constructor(&main TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &main, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_STRING(&location, "")) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "config");
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "index");
		ZEPHIR_CALL_METHOD(&_2$$3, &main, "config", NULL, 41, &_3$$3, &_4$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(&_2$$3, "none")) {
			ZEPHIR_INIT_NVAR(&location);
			ZVAL_STRING(&location, "index.p");
		} else {
			ZEPHIR_INIT_VAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "config");
			ZEPHIR_INIT_VAR(&_6$$5);
			ZVAL_STRING(&_6$$5, "index");
			ZEPHIR_CALL_METHOD(&location, &main, "config", NULL, 41, &_5$$5, &_6$$5);
			zephir_check_call_status();
		}
	}
	ZVAL_LONG(&_7, 4);
	ZEPHIR_CALL_FUNCTION(&extension, "pathinfo", NULL, 20, &location, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &main, "notfound", NULL, 43, &location);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_STRING(&extension, "p")) {
			ZEPHIR_INIT_VAR(&_8$$6);
			ZEPHIR_CONCAT_SVS(&_8$$6, "static/", &location, ".static");
			if (!((zephir_file_exists(&_8$$6 TSRMLS_CC) == SUCCESS))) {
				ZEPHIR_CALL_SELF(NULL, "engine", &_9, 6, &location);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(&_10$$8);
				ZEPHIR_CONCAT_SVS(&_10$$8, "static/", &location, ".static");
				ZEPHIR_INIT_VAR(&_11$$8);
				ZVAL_STRING(&_11$$8, "text/html");
				ZEPHIR_CALL_METHOD(NULL, &main, "content", NULL, 44, &_10$$8, &_11$$8);
				zephir_check_call_status();
			}
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "php")) {
			ZEPHIR_INIT_VAR(&_12$$9);
			ZEPHIR_CONCAT_SVS(&_12$$9, "static/", &location, ".static");
			ZEPHIR_INIT_VAR(&_13$$9);
			ZVAL_STRING(&_13$$9, "text/html");
			ZEPHIR_CALL_METHOD(NULL, &main, "content", NULL, 44, &_12$$9, &_13$$9);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&phplang, "file_get_contents", NULL, 19, &location, &__$true);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_13$$9);
			ZEPHIR_INIT_VAR(&_14$$9);
			ZEPHIR_CONCAT_SV(&_14$$9, "?> ", &phplang);
			zephir_eval_php(&_14$$9, &_13$$9, "/home/ubuntu/workspace/part/part/part.zep:32" TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "pp")) {
			ZEPHIR_CALL_METHOD(NULL, &main, "forbidden", NULL, 45);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "ini")) {
			ZEPHIR_CALL_METHOD(NULL, &main, "forbidden", NULL, 45);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "html")) {
			ZEPHIR_INIT_VAR(&_15$$12);
			ZVAL_STRING(&_15$$12, "text/html");
			ZEPHIR_CALL_METHOD(NULL, &main, "content", NULL, 44, &location, &_15$$12);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "css")) {
			ZEPHIR_INIT_VAR(&_16$$13);
			ZVAL_STRING(&_16$$13, "text/css");
			ZEPHIR_CALL_METHOD(NULL, &main, "content", NULL, 44, &location, &_16$$13);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&extension, "js")) {
			ZEPHIR_INIT_VAR(&_17$$14);
			ZVAL_STRING(&_17$$14, "application/javascript");
			ZEPHIR_CALL_METHOD(NULL, &main, "content", NULL, 44, &location, &_17$$14);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_VAR(&_18$$15);
		ZVAL_STRING(&_18$$15, "text/plain");
		ZEPHIR_CALL_METHOD(NULL, &main, "content", NULL, 44, &location, &_18$$15);
		zephir_check_call_status();
	} while(0);

	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Part_Part, engine) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location, location_sub, __$true, plang, statement, text, functions, library, _0, _1;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&location_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&plang);
	ZVAL_UNDEF(&statement);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&functions);
	ZVAL_UNDEF(&library);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location);



	ZEPHIR_INIT_VAR(&statement);
	object_init_ex(&statement, part_statement_main_ce);
	if (zephir_has_constructor(&statement TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &statement, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&text);
	object_init_ex(&text, part_text_main_ce);
	if (zephir_has_constructor(&text TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &text, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&functions);
	object_init_ex(&functions, part_function_main_ce);
	if (zephir_has_constructor(&functions TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &functions, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&library);
	object_init_ex(&library, part_lib_main_ce);
	if (zephir_has_constructor(&library TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &library, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&plang, "file_get_contents", NULL, 19, location, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &library, "loader", NULL, 46, &plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &text, "loader", NULL, 47, &plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &functions, "loader", NULL, 48, &plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &statement, "loader", NULL, 49, &plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&plang, &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_eval_php(&plang, &_1, "/home/ubuntu/workspace/part/part/part.zep:73" TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

