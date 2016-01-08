
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
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Part_Lib_Main) {

	ZEPHIR_REGISTER_CLASS(Part\\Lib, Main, part, lib_main, part_lib_main_method_entry, 0);

	return SUCCESS;

}

/**
 * Load all library
 */
PHP_METHOD(Part_Lib_Main, loader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *plang = NULL, plang_sub, library, _0;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&library);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&library);
	object_init_ex(&library, part_lib_main_ce);
	if (zephir_has_constructor(&library TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &library, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_0, &library, "os", NULL, 27, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &library, "import", NULL, 28, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &library, "http", NULL, 29, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &library, "server", NULL, 30, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &library, "commands", NULL, 31, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &library, "file", NULL, 32, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &library, "mysql", NULL, 33, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &library, "mysqli", NULL, 34, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &library, "curl", NULL, 35, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &library, "load", NULL, 36, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &library, "session", NULL, 37, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_METHOD(&_0, &library, "str_random", NULL, 38, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * Random string usage:
 *<code>
 *      string.random()
 *		string.random(100)
 *</code>
 */
PHP_METHOD(Part_Lib_Main, str_random) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *plang = NULL, plang_sub, _0, _1, _2;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/string.random\\((.*)\\)/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Part\\Lib\\Random\\Strings::random($1);");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", NULL, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * MySQL usage:
 *<code>
 *      mysql.connect()
 *</code>
 */
PHP_METHOD(Part_Lib_Main, mysql) {

	zval *plang = NULL, plang_sub, _0, _1, _2;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "mysql.");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "mysql_");
	zephir_fast_str_replace(&_0, &_1, &_2, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * MySQLI usage:
 *<code>
 *      mysqli.connect()
 *</code>
 */
PHP_METHOD(Part_Lib_Main, mysqli) {

	zval *plang = NULL, plang_sub, _0, _1, _2;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "mysqli.");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "mysqli_");
	zephir_fast_str_replace(&_0, &_1, &_2, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * Curl usage:
 *<code>
 *      curl.get(url, parameter, user_agent)
 *		curl.post(url, parameter, user_agent)
 *		curl.version()
 *</code>
 */
PHP_METHOD(Part_Lib_Main, curl) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *plang = NULL, plang_sub, _0, _1, _2, _4;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/curl.get\\((.*)\\)/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Part\\Lib\\Curl\\Curl::get($1);");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/curl.post\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Part\\Lib\\Curl\\Curl::post($1);");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "curl.version()");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "Part\\Lib\\Curl\\Curl::version();");
	zephir_fast_str_replace(&_0, &_1, &_4, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * Import usage:
 *<code>
 *      import Library\Func
 *</code>
 */
PHP_METHOD(Part_Lib_Main, import) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *plang = NULL, plang_sub, _0, _1, _2;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/import (.*)/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "use $1;");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", NULL, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * Load usage:
 *<code>
 *      load "file.p"
 *		require "file.p"
 *</code>
 */
PHP_METHOD(Part_Lib_Main, load) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *plang = NULL, plang_sub, _0, _1, _2;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/load (.*)/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Part\\Lib\\Load\\Load::load_view($1);");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/require (.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Part\\Lib\\Load\\Load::load_view($1);");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * Session usage:
 *<code>
 *		session.start()
 *      session.save(key,value)
 *		session.get(key)
 *</code>
 */
PHP_METHOD(Part_Lib_Main, session) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_7 = NULL;
	zval *plang = NULL, plang_sub, _0, _1, _2, _3, _4, _5, _6;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "session.start()");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "session_start();");
	zephir_fast_str_replace(&_0, &_1, &_2, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "session.clear()");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "session_destroy();");
	zephir_fast_str_replace(&_0, &_3, &_4, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/session.save\\((.*),(.*)\\)/");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "$_SESSION[$1] = $2;");
	ZEPHIR_CALL_FUNCTION(&_6, "preg_replace", &_7, 5, &_0, &_5, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_6);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/session.get\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "$_SESSION[$1]");
	ZEPHIR_CALL_FUNCTION(&_6, "preg_replace", &_7, 5, &_0, &_5, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_6);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * File usage:
 *<code>
 *      file.read(location)
 *		file.size(location)
 *		file.ext(location)
 *		file.create(location, content)
 *		file.copy(location, newlocation)
 *		file.time(format, location)
 *</code>
 */
PHP_METHOD(Part_Lib_Main, file) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *plang = NULL, plang_sub, _0, _1, _2;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/file.read\\((.*)\\)/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Part\\Lib\\File\\File::read($1);");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/file.load\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Part\\Lib\\File\\File::read($1);");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/file.size\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Part\\Lib\\File\\File::size($1);");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/file.ext\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Part\\Lib\\File\\File::extension($1);");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/file.create\\((.*),(.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Part\\Lib\\File\\File::create($1,$2);");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/file.copy\\((.*),(.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Part\\Lib\\File\\File::copy($1,$2);");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/file.time\\((.*),(.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Part\\Lib\\File\\File::time($1,$2);");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/file.rename\\((.*),(.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Part\\Lib\\File\\File::rename($1,$2);");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/file.delete\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Part\\Lib\\File\\File::delete($1);");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * HTTP usage:
 *<code>
 *      http.get("url")
 *      http.post("post")
 *      http.request("req")
 *		http.host()
 *		http.referer()
 *		http.user_agent()
 *		http.method()
 *		http.header()
 *		http.ip()
 *		http.port()
 *</code>
 */
PHP_METHOD(Part_Lib_Main, http) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_17 = NULL;
	zval *plang = NULL, plang_sub, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "http.host()");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "$_SERVER['HTTP_HOST'];");
	zephir_fast_str_replace(&_0, &_1, &_2, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "http.referer()");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "$_SERVER['HTTP_REFERER'];");
	zephir_fast_str_replace(&_0, &_3, &_4, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "http.user_agent()");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "$_SERVER['HTTP_USER_AGENT'];");
	zephir_fast_str_replace(&_0, &_5, &_6, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "http.method()");
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "$_SERVER['REQUEST_METHOD'];");
	zephir_fast_str_replace(&_0, &_7, &_8, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "http.header()");
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "$_SERVER['HTTP_ACCEPT'];");
	zephir_fast_str_replace(&_0, &_9, &_10, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "http.ip()");
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "$_SERVER['REMOTE_ADDR'];");
	zephir_fast_str_replace(&_0, &_11, &_12, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "http.port()");
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "$_SERVER['REMOTE_PORT'];");
	zephir_fast_str_replace(&_0, &_13, &_14, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/http.get\\((.*)\\)/");
	ZEPHIR_INIT_VAR(&_15);
	ZVAL_STRING(&_15, "$_GET[$1];");
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 5, &_0, &_15, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_16);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/http.request\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_15);
	ZVAL_STRING(&_15, "$_REQUEST[$1];");
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 5, &_0, &_15, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_16);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/http.post\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_15);
	ZVAL_STRING(&_15, "$_POST[$1];");
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 5, &_0, &_15, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_16);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * Server usage:
 *<code>
 *      server.self()
 *      server.domain()
 *      server.ip()
 *		server.webserver()
 *		server.protocol()
 *		server.admin()
 *</code>
 */
PHP_METHOD(Part_Lib_Main, server) {

	zval *plang = NULL, plang_sub, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "server.self()");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "$_SERVER['PHP_SELF'];");
	zephir_fast_str_replace(&_0, &_1, &_2, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "server.domain()");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "$_SERVER['SERVER_NAME'];");
	zephir_fast_str_replace(&_0, &_3, &_4, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "server.ip()");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "$_SERVER['SERVER_ADDR'];");
	zephir_fast_str_replace(&_0, &_5, &_6, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "server.port()");
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "$_SERVER['SERVER_PORT'];");
	zephir_fast_str_replace(&_0, &_7, &_8, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "server.webserver()");
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "$_SERVER['SERVER_SOFTWARE'];");
	zephir_fast_str_replace(&_0, &_9, &_10, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "server.protocol()");
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "$_SERVER['SERVER_PROTOCOL'];");
	zephir_fast_str_replace(&_0, &_11, &_12, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "server.admin()");
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "$_SERVER['SERVER_ADMIN'];");
	zephir_fast_str_replace(&_0, &_13, &_14, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * OS usage:
 *<code>
 *      os.kernel()
 *      os.user()
 *      os.type()
 *</code>
 */
PHP_METHOD(Part_Lib_Main, os) {

	zval *plang = NULL, plang_sub, _0, _1, _2, _3, _4, _5, _6;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "os.kernel()");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "exec('uname -r');");
	zephir_fast_str_replace(&_0, &_1, &_2, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "os.user()");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "exec('whoami');");
	zephir_fast_str_replace(&_0, &_3, &_4, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "os.type()");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "exec('uname -o');");
	zephir_fast_str_replace(&_0, &_5, &_6, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, &_0);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * Command usage:
 *<code>
 *      cmd("commands")
 *      system("commands")
 *      exec("commands")
 *</code>
 */
PHP_METHOD(Part_Lib_Main, commands) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *plang = NULL, plang_sub, _0, _1, _2;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/cmd\\((.*)\\)/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "exec($1);");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/system\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "exec($1);");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/exec\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "exec($1);");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

