
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
#include "kernel/exit.h"


ZEPHIR_INIT_CLASS(Part_Page_Main) {

	ZEPHIR_REGISTER_CLASS(Part\\Page, Main, part, page_main, part_page_main_method_entry, 0);

	return SUCCESS;

}

/**
 * 404 Not found:
 */
PHP_METHOD(Part_Page_Main, notfound) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *location, _0$$3 = zval_used_for_init, *_2$$3 = NULL, *_3$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &location);



	if (!((zephir_file_exists(location TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, "HTTP/1.1 404 Not Found", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 21, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0$$3);
		ZVAL_STRING(&_0$$3, "D, d M Y h:i:s T", 0);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "date", NULL, 15, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, "Date: ", _2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 21, _3$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0$$3);
		ZVAL_STRING(&_0$$3, "Content-Type: text/html; charset=iso-8859-1", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 21, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0$$3);
		ZVAL_STRING(&_0$$3, "X-Powered-By: P language", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_1, 21, &_0$$3);
		zephir_check_call_status();
		php_printf("%s", "404 Not Found");
		ZEPHIR_MM_RESTORE();
		zephir_exit_empty();
	}
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
	ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 21, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&plang, "file_get_contents", NULL, 13, location, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	zend_print_zval(plang, 0);
	ZEPHIR_MM_RESTORE();

}

