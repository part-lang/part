
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/math.h"


ZEPHIR_INIT_CLASS(Part_Lib_File_File) {

	ZEPHIR_REGISTER_CLASS(Part\\Lib\\File, File, part, lib_file_file, part_lib_file_file_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Part_Lib_File_File, create) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, *content_param = NULL, _GET, file, dir, _0, _1, _2;
	zval location, content;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&location);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_fetch_params(1, 2, 0, &location_param, &content_param);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(&location, location_param);
	} else {
		ZEPHIR_INIT_VAR(&location);
		ZVAL_EMPTY_STRING(&location);
	}
	if (unlikely(Z_TYPE_P(content_param) != IS_STRING && Z_TYPE_P(content_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'content' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(content_param) == IS_STRING)) {
		zephir_get_strval(&content, content_param);
	} else {
		ZEPHIR_INIT_VAR(&content);
		ZVAL_EMPTY_STRING(&content);
	}


	zephir_array_fetch_string(&_0, &_GET, SL("_url"), PH_NOISY | PH_READONLY, "part/lib/file/file.zep", 7 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&dir, "dirname", NULL, 17, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VSV(&_1, &dir, "/", &location);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "w");
	ZEPHIR_CALL_FUNCTION(&file, "fopen", NULL, 12, &_1, &_2);
	zephir_check_call_status();
	zephir_fwrite(NULL, &file, &content TSRMLS_CC);
	zephir_fclose(&file TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Part_Lib_File_File, read) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, _GET, __$true, dir, _0, _1;
	zval location;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&location);
	ZVAL_UNDEF(&_GET);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_fetch_params(1, 1, 0, &location_param);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(&location, location_param);
	} else {
		ZEPHIR_INIT_VAR(&location);
		ZVAL_EMPTY_STRING(&location);
	}


	zephir_array_fetch_string(&_0, &_GET, SL("_url"), PH_NOISY | PH_READONLY, "part/lib/file/file.zep", 15 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&dir, "dirname", NULL, 17, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VSV(&_1, &dir, "/", &location);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 18, &_1, &__$true);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Part_Lib_File_File, extension) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, _GET, dir, _0, _1, _2;
	zval location;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&location);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_fetch_params(1, 1, 0, &location_param);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(&location, location_param);
	} else {
		ZEPHIR_INIT_VAR(&location);
		ZVAL_EMPTY_STRING(&location);
	}


	zephir_array_fetch_string(&_0, &_GET, SL("_url"), PH_NOISY | PH_READONLY, "part/lib/file/file.zep", 21 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&dir, "dirname", NULL, 17, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VSV(&_1, &dir, "/", &location);
	ZVAL_LONG(&_2, 4);
	ZEPHIR_RETURN_CALL_FUNCTION("pathinfo", NULL, 19, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Part_Lib_File_File, time) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *format_param = NULL, *location_param = NULL, _GET, dir, _0, _1, _2;
	zval format, location;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&format);
	ZVAL_UNDEF(&location);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_fetch_params(1, 2, 0, &format_param, &location_param);

	if (unlikely(Z_TYPE_P(format_param) != IS_STRING && Z_TYPE_P(format_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'format' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(format_param) == IS_STRING)) {
		zephir_get_strval(&format, format_param);
	} else {
		ZEPHIR_INIT_VAR(&format);
		ZVAL_EMPTY_STRING(&format);
	}
	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(&location, location_param);
	} else {
		ZEPHIR_INIT_VAR(&location);
		ZVAL_EMPTY_STRING(&location);
	}


	zephir_array_fetch_string(&_0, &_GET, SL("_url"), PH_NOISY | PH_READONLY, "part/lib/file/file.zep", 27 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&dir, "dirname", NULL, 17, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSV(&_2, &dir, "/", &location);
	zephir_filemtime(&_1, &_2 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("date", NULL, 20, &format, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Part_Lib_File_File, copy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, *newlocation_param = NULL, _GET, dir, _0, _1, _2, _3;
	zval location, newlocation;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&location);
	ZVAL_UNDEF(&newlocation);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_fetch_params(1, 2, 0, &location_param, &newlocation_param);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(&location, location_param);
	} else {
		ZEPHIR_INIT_VAR(&location);
		ZVAL_EMPTY_STRING(&location);
	}
	if (unlikely(Z_TYPE_P(newlocation_param) != IS_STRING && Z_TYPE_P(newlocation_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'newlocation' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(newlocation_param) == IS_STRING)) {
		zephir_get_strval(&newlocation, newlocation_param);
	} else {
		ZEPHIR_INIT_VAR(&newlocation);
		ZVAL_EMPTY_STRING(&newlocation);
	}


	zephir_array_fetch_string(&_0, &_GET, SL("_url"), PH_NOISY | PH_READONLY, "part/lib/file/file.zep", 33 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&dir, "dirname", NULL, 17, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VSV(&_1, &dir, "/", &location);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSV(&_2, &dir, "/", &newlocation);
	ZEPHIR_CALL_FUNCTION(&_3, "copy", NULL, 21, &_1, &_2);
	zephir_check_call_status();
	if (!zephir_is_true(&_3)) {
		php_printf("%s", "failed to copy...\n");
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Part_Lib_File_File, rename) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, *newname_param = NULL, _GET, dir, _0, _1, _2, _3;
	zval location, newname;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&location);
	ZVAL_UNDEF(&newname);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_fetch_params(1, 2, 0, &location_param, &newname_param);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(&location, location_param);
	} else {
		ZEPHIR_INIT_VAR(&location);
		ZVAL_EMPTY_STRING(&location);
	}
	if (unlikely(Z_TYPE_P(newname_param) != IS_STRING && Z_TYPE_P(newname_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'newname' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(newname_param) == IS_STRING)) {
		zephir_get_strval(&newname, newname_param);
	} else {
		ZEPHIR_INIT_VAR(&newname);
		ZVAL_EMPTY_STRING(&newname);
	}


	zephir_array_fetch_string(&_0, &_GET, SL("_url"), PH_NOISY | PH_READONLY, "part/lib/file/file.zep", 41 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&dir, "dirname", NULL, 17, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VSV(&_1, &dir, "/", &location);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VSV(&_2, &dir, "/", &newname);
	ZEPHIR_CALL_FUNCTION(&_3, "rename", NULL, 22, &_1, &_2);
	zephir_check_call_status();
	if (!zephir_is_true(&_3)) {
		php_printf("%s", "failed to rename...\n");
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Part_Lib_File_File, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, _GET, dir, _0, _1, _2;
	zval location;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&location);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_fetch_params(1, 1, 0, &location_param);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(&location, location_param);
	} else {
		ZEPHIR_INIT_VAR(&location);
		ZVAL_EMPTY_STRING(&location);
	}


	zephir_array_fetch_string(&_0, &_GET, SL("_url"), PH_NOISY | PH_READONLY, "part/lib/file/file.zep", 49 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&dir, "dirname", NULL, 17, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VSV(&_1, &dir, "/", &location);
	ZEPHIR_CALL_FUNCTION(&_2, "unlink", NULL, 23, &_1);
	zephir_check_call_status();
	if (!zephir_is_true(&_2)) {
		php_printf("%s", "failed to delete...\n");
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Part_Lib_File_File, size) {

	zval type$$3;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, *format = NULL, format_sub, _GET, __$false, size, base, dir, _0, _1$$3, _2$$3, _4$$3, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _10$$4, _11$$6;
	zval location;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&location);
	ZVAL_UNDEF(&format_sub);
	ZVAL_UNDEF(&_GET);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&base);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&type$$3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_GET, SL("_GET"));
	zephir_fetch_params(1, 1, 1, &location_param, &format);

	if (unlikely(Z_TYPE_P(location_param) != IS_STRING && Z_TYPE_P(location_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'location' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(location_param) == IS_STRING)) {
		zephir_get_strval(&location, location_param);
	} else {
		ZEPHIR_INIT_VAR(&location);
		ZVAL_EMPTY_STRING(&location);
	}
	if (!format) {
		format = &format_sub;
		format = &__$false;
	}


	zephir_array_fetch_string(&_0, &_GET, SL("_url"), PH_NOISY | PH_READONLY, "part/lib/file/file.zep", 57 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&dir, "dirname", NULL, 17, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(format)) {
		ZEPHIR_INIT_VAR(&type$$3);
		zephir_create_array(&type$$3, 5, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, " bytes");
		zephir_array_fast_append(&type$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, " KB");
		zephir_array_fast_append(&type$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, " MB");
		zephir_array_fast_append(&type$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, " GB");
		zephir_array_fast_append(&type$$3, &_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, " TB");
		zephir_array_fast_append(&type$$3, &_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VSV(&_2$$3, &dir, "/", &location);
		ZEPHIR_CALL_FUNCTION(&size, "filesize", &_3, 24, &_2$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, 1024);
		ZEPHIR_CALL_FUNCTION(&base, "log", NULL, 25, &size, &_4$$3);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(&base, 0)) {
			ZEPHIR_INIT_VAR(&_5$$4);
			ZEPHIR_INIT_VAR(&_6$$4);
			ZVAL_LONG(&_7$$4, 1024);
			ZVAL_DOUBLE(&_8$$4, (zephir_get_numberval(&base) - zephir_floor(&base TSRMLS_CC)));
			zephir_pow_function(&_6$$4, &_7$$4, &_8$$4);
			ZVAL_LONG(&_9$$4, 2);
			zephir_round(&_5$$4, &_6$$4, &_9$$4, NULL TSRMLS_CC);
			zephir_array_fetch(&_10$$4, &type$$3, &base, PH_NOISY | PH_READONLY, "part/lib/file/file.zep", 64 TSRMLS_CC);
			ZEPHIR_CONCAT_VV(return_value, &_5$$4, &_10$$4);
			RETURN_MM();
		} else {
			RETURN_MM_STRING("0 bytes");
		}
	} else {
		ZEPHIR_INIT_VAR(&_11$$6);
		ZEPHIR_CONCAT_VSV(&_11$$6, &dir, "/", &location);
		ZEPHIR_RETURN_CALL_FUNCTION("filesize", &_3, 24, &_11$$6);
		zephir_check_call_status();
		RETURN_MM();
	}

}

