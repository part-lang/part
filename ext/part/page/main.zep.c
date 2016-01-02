
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

	zephir_fcall_cache_entry *_1 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *location, *main$$3 = NULL, _0$$3 = zval_used_for_init, *_2$$3 = NULL, *_3$$3, *_4$$3 = NULL, *_5$$3, *_6$$3, _7$$4, *_8$$4 = NULL, *_10$$5 = NULL, *_11$$5, *_12$$5, *_13$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location);



	if (!((zephir_file_exists(location TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_INIT_VAR(main$$3);
		object_init_ex(main$$3, part_page_main_ce);
		if (zephir_has_constructor(main$$3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, main$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, "HTTP/1.1 404 Not Found", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 22, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0$$3);
		ZVAL_STRING(&_0$$3, "D, d M Y h:i:s T", 0);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "date", NULL, 16, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, "Date: ", _2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 22, _3$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0$$3);
		ZVAL_STRING(&_0$$3, "Content-Type: text/html; charset=iso-8859-1", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 22, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0$$3);
		ZVAL_STRING(&_0$$3, "X-Powered-By: P language", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 22, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_5$$3);
		ZVAL_STRING(_5$$3, "config", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_6$$3);
		ZVAL_LONG(_6$$3, 404);
		ZEPHIR_CALL_METHOD(&_4$$3, main$$3, "config", NULL, 23, _5$$3, _6$$3);
		zephir_check_temp_parameter(_5$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(_4$$3, "")) {
			ZEPHIR_SINIT_VAR(_7$$4);
			ZVAL_STRING(&_7$$4, "/etc/part/page/404.html", 0);
			ZEPHIR_CALL_FUNCTION(&_8$$4, "file_get_contents", &_9, 14, &_7$$4, ZEPHIR_GLOBAL(global_true));
			zephir_check_call_status();
			zend_print_zval(_8$$4, 0);
		} else {
			ZEPHIR_INIT_VAR(_11$$5);
			ZVAL_STRING(_11$$5, "config", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_12$$5);
			ZVAL_LONG(_12$$5, 404);
			ZEPHIR_CALL_METHOD(&_10$$5, main$$3, "config", NULL, 23, _11$$5, _12$$5);
			zephir_check_temp_parameter(_11$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_13$$5, "file_get_contents", &_9, 14, _10$$5, ZEPHIR_GLOBAL(global_true));
			zephir_check_call_status();
			zend_print_zval(_13$$5, 0);
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

	zval *main = NULL, _0 = zval_used_for_init, *_2 = NULL, *_3, *_4 = NULL, *_5, *_6, _7$$3, *_8$$3 = NULL, *_10$$4 = NULL, *_11$$4, *_12$$4, *_13$$4 = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(main);
	object_init_ex(main, part_page_main_ce);
	if (zephir_has_constructor(main TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, main, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "HTTP/1.1 403 Forbidden", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 22, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "D, d M Y h:i:s T", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "date", NULL, 16, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SV(_3, "Date: ", _2);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 22, _3);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "Content-Type: text/html; charset=iso-8859-1", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 22, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "X-Powered-By: P language", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 22, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, 403);
	ZEPHIR_CALL_METHOD(&_4, main, "config", NULL, 23, _5, _6);
	zephir_check_temp_parameter(_5);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(_4, "")) {
		ZEPHIR_SINIT_VAR(_7$$3);
		ZVAL_STRING(&_7$$3, "/etc/part/page/403.html", 0);
		ZEPHIR_CALL_FUNCTION(&_8$$3, "file_get_contents", &_9, 14, &_7$$3, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		zend_print_zval(_8$$3, 0);
	} else {
		ZEPHIR_INIT_VAR(_11$$4);
		ZVAL_STRING(_11$$4, "config", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_12$$4);
		ZVAL_LONG(_12$$4, 403);
		ZEPHIR_CALL_METHOD(&_10$$4, main, "config", NULL, 23, _11$$4, _12$$4);
		zephir_check_temp_parameter(_11$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_13$$4, "file_get_contents", &_9, 14, _10$$4, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		zend_print_zval(_13$$4, 0);
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
	zval *location, *type_header, *plang = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &location, &type_header);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "Content-Type: ", type_header, "; charset=iso-8859-1");
	ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 22, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&plang, "file_get_contents", NULL, 14, location, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	zend_print_zval(plang, 0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get config file:
 */
PHP_METHOD(Part_Page_Main, config) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *section, *config, *setting = NULL, _0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &section, &config);



	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "part.ini", 0);
	ZEPHIR_CALL_FUNCTION(&setting, "parse_ini_file", NULL, 24, &_0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	zephir_array_fetch(&_1, setting, section, PH_NOISY | PH_READONLY, "part/page/main.zep", 57 TSRMLS_CC);
	zephir_array_fetch(&_2, _1, config, PH_NOISY | PH_READONLY, "part/page/main.zep", 57 TSRMLS_CC);
	RETURN_CTOR(_2);

}

