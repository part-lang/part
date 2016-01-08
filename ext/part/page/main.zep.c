
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
#include "kernel/file.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/exit.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Part_Page_Main) {

	ZEPHIR_REGISTER_CLASS(Part\\Page, Main, part, page_main, part_page_main_method_entry, 0);

	return SUCCESS;

}

/**
 * 404 Not found:
 */
PHP_METHOD(Part_Page_Main, notfound) {

	zephir_fcall_cache_entry *_1 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *location, location_sub, __$true, main$$3, _0$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$4, _7$$4, _9$$5, _10$$5, _11$$5, _12$$5;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&location_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&main$$3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location);



	if (!((zephir_file_exists(location TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_VAR(&main$$3);
		object_init_ex(&main$$3, part_page_main_ce);
		if (zephir_has_constructor(&main$$3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &main$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "HTTP/1.1 404 Not Found");
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 40, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "D, d M Y h:i:s T");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "date", NULL, 21, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "Date: ", &_2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 40, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "Content-Type: text/html; charset=iso-8859-1");
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 40, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "X-Powered-By: P language");
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 40, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "config");
		ZVAL_LONG(&_5$$3, 404);
		ZEPHIR_CALL_METHOD(&_4$$3, &main$$3, "config", NULL, 41, &_0$$3, &_5$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(&_4$$3, "none")) {
			ZEPHIR_INIT_VAR(&_6$$4);
			ZVAL_STRING(&_6$$4, "/etc/part/page/404.html");
			ZEPHIR_CALL_FUNCTION(&_7$$4, "file_get_contents", &_8, 19, &_6$$4, &__$true);
			zephir_check_call_status();
			zend_print_zval(&_7$$4, 0);
		} else {
			ZEPHIR_INIT_VAR(&_10$$5);
			ZVAL_STRING(&_10$$5, "config");
			ZVAL_LONG(&_11$$5, 404);
			ZEPHIR_CALL_METHOD(&_9$$5, &main$$3, "config", NULL, 41, &_10$$5, &_11$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_12$$5, "file_get_contents", &_8, 19, &_9$$5, &__$true);
			zephir_check_call_status();
			zend_print_zval(&_12$$5, 0);
		}
		ZEPHIR_MM_RESTORE();
		zephir_exit_empty();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 403 Forbidden:
 */
PHP_METHOD(Part_Page_Main, forbidden) {

	zval __$true, main, _0, _2, _3, _4, _5, _6$$3, _7$$3, _9$$4, _10$$4, _11$$4, _12$$4;
	zephir_fcall_cache_entry *_1 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&main);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&main);
	object_init_ex(&main, part_page_main_ce);
	if (zephir_has_constructor(&main TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &main, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "HTTP/1.1 403 Forbidden");
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 40, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "D, d M Y h:i:s T");
	ZEPHIR_CALL_FUNCTION(&_2, "date", NULL, 21, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "Date: ", &_2);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 40, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Content-Type: text/html; charset=iso-8859-1");
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 40, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "X-Powered-By: P language");
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 40, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "config");
	ZVAL_LONG(&_5, 403);
	ZEPHIR_CALL_METHOD(&_4, &main, "config", NULL, 41, &_0, &_5);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&_4, "none")) {
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "/etc/part/page/403.html");
		ZEPHIR_CALL_FUNCTION(&_7$$3, "file_get_contents", &_8, 19, &_6$$3, &__$true);
		zephir_check_call_status();
		zend_print_zval(&_7$$3, 0);
	} else {
		ZEPHIR_INIT_VAR(&_10$$4);
		ZVAL_STRING(&_10$$4, "config");
		ZVAL_LONG(&_11$$4, 403);
		ZEPHIR_CALL_METHOD(&_9$$4, &main, "config", NULL, 41, &_10$$4, &_11$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_12$$4, "file_get_contents", &_8, 19, &_9$$4, &__$true);
		zephir_check_call_status();
		zend_print_zval(&_12$$4, 0);
	}
	ZEPHIR_MM_RESTORE();
	zephir_exit_empty();
	ZEPHIR_MM_RESTORE();

}

/**
 * Set content:
 */
PHP_METHOD(Part_Page_Main, content) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location, location_sub, *type_header, type_header_sub, __$true, plang, _0;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&location_sub);
	ZVAL_UNDEF(&type_header_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&plang);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &location, &type_header);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "Content-Type: ", type_header, "; charset=iso-8859-1");
	ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 40, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&plang, "file_get_contents", NULL, 19, location, &__$true);
	zephir_check_call_status();
	zend_print_zval(&plang, 0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get config file:
 */
PHP_METHOD(Part_Page_Main, config) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *section, section_sub, *config, config_sub, _SERVER, __$true, setting, location, _0, _1$$3, _2$$4, _3$$4;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&section_sub);
	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&setting);
	ZVAL_UNDEF(&location);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 2, 0, &section, &config);



	zephir_array_fetch_string(&_0, &_SERVER, SL("DOCUMENT_ROOT"), PH_NOISY | PH_READONLY, "part/page/main.zep", 56 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&location);
	ZEPHIR_CONCAT_VS(&location, &_0, "/part.ini");
	if ((zephir_file_exists(&location TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&setting, "parse_ini_file", NULL, 42, &location, &__$true);
		zephir_check_call_status();
		zephir_array_fetch(&_1$$3, &setting, section, PH_READONLY, "part/page/main.zep", 59 TSRMLS_CC);
		if (zephir_array_isset(&_1$$3, config)) {
			zephir_array_fetch(&_2$$4, &setting, section, PH_NOISY | PH_READONLY, "part/page/main.zep", 60 TSRMLS_CC);
			zephir_array_fetch(&_3$$4, &_2$$4, config, PH_NOISY | PH_READONLY, "part/page/main.zep", 60 TSRMLS_CC);
			RETURN_CTOR(_3$$4);
		} else {
			RETURN_MM_STRING("none");
		}
	} else {
		RETURN_MM_STRING("none");
	}

}

