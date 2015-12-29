
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
#include "kernel/string.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Part_Lib_Main) {

	ZEPHIR_REGISTER_CLASS(Part\\Lib, Main, part, lib_main, part_lib_main_method_entry, 0);

	return SUCCESS;

}

/**
 * MySQL usage:
 *<code>
 *      mysql.connect()
 *</code>
 */
PHP_METHOD(Part_Lib_Main, mysql) {

	zval *plang = NULL, *_0, _1, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "mysql.", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "mysql_", 0);
	zephir_fast_str_replace(&_0, &_1, &_2, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
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

	zval *plang = NULL, *_0, _1, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "mysqli.", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "mysqli_", 0);
	zephir_fast_str_replace(&_0, &_1, &_2, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * Curl usage:
 *<code>
 *      curl.get(url, parameter, user_agent)
 *		curl.post(url, parameter, user_agent)
 *</code>
 */
PHP_METHOD(Part_Lib_Main, curl) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *plang = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "/curl.get\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Part\\Lib\\Curl::get($1);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/curl.post\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Part\\Lib\\Curl::post($1);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
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
	zval *plang = NULL, *_0, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "/import (.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "use $1;", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", NULL, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
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
	zval *plang = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "/load (.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Part\\Lib\\Load::load_view($1);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/require (.*)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Part\\Lib\\Load::load_view($1);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
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
	zval *plang = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "/file.read\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Part\\Lib\\File::read($1);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/file.load\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Part\\Lib\\File::read($1);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/file.size\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Part\\Lib\\File::size($1);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/file.ext\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Part\\Lib\\File::extension($1);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/file.create\\((.*),(.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Part\\Lib\\File::create($1,$2);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/file.copy\\((.*),(.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Part\\Lib\\File::copy($1,$2);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/file.time\\((.*),(.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Part\\Lib\\File::time($1,$2);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/file.rename\\((.*),(.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Part\\Lib\\File::rename($1,$2);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/file.delete\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Part\\Lib\\File::delete($1);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
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
	zval *plang = NULL, *_0 = NULL, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, *_15 = NULL, *_16 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "http.host()", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "$_SERVER['HTTP_HOST'];", 0);
	zephir_fast_str_replace(&_0, &_1, &_2, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "http.referer()", 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "$_SERVER['HTTP_REFERER'];", 0);
	zephir_fast_str_replace(&_0, &_3, &_4, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "http.user_agent()", 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "$_SERVER['HTTP_USER_AGENT'];", 0);
	zephir_fast_str_replace(&_0, &_5, &_6, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "http.method()", 0);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, "$_SERVER['REQUEST_METHOD'];", 0);
	zephir_fast_str_replace(&_0, &_7, &_8, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_STRING(&_9, "http.header()", 0);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_STRING(&_10, "$_SERVER['HTTP_ACCEPT'];", 0);
	zephir_fast_str_replace(&_0, &_9, &_10, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_STRING(&_11, "http.ip()", 0);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_STRING(&_12, "$_SERVER['REMOTE_ADDR'];", 0);
	zephir_fast_str_replace(&_0, &_11, &_12, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_STRING(&_13, "http.port()", 0);
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_STRING(&_14, "$_SERVER['REMOTE_PORT'];", 0);
	zephir_fast_str_replace(&_0, &_13, &_14, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/http.get\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_15);
	ZVAL_STRING(_15, "$_GET[$1];", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 1, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/http.request\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "$_REQUEST[$1];", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 1, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/http.post\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "$_POST[$1];", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_16, "preg_replace", &_17, 1, _0, _15, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _16);
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

	zval *plang = NULL, *_0 = NULL, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "server.self()", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "$_SERVER['PHP_SELF'];", 0);
	zephir_fast_str_replace(&_0, &_1, &_2, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "server.domain()", 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "$_SERVER['SERVER_NAME'];", 0);
	zephir_fast_str_replace(&_0, &_3, &_4, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "server.ip()", 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "$_SERVER['SERVER_ADDR'];", 0);
	zephir_fast_str_replace(&_0, &_5, &_6, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "server.port()", 0);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, "$_SERVER['SERVER_PORT'];", 0);
	zephir_fast_str_replace(&_0, &_7, &_8, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_STRING(&_9, "server.webserver()", 0);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_STRING(&_10, "$_SERVER['SERVER_SOFTWARE'];", 0);
	zephir_fast_str_replace(&_0, &_9, &_10, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_STRING(&_11, "server.protocol()", 0);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_STRING(&_12, "$_SERVER['SERVER_PROTOCOL'];", 0);
	zephir_fast_str_replace(&_0, &_11, &_12, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_STRING(&_13, "server.admin()", 0);
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_STRING(&_14, "$_SERVER['SERVER_ADMIN'];", 0);
	zephir_fast_str_replace(&_0, &_13, &_14, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
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

	zval *plang = NULL, *_0 = NULL, _1, _2, _3, _4, _5, _6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "os.kernel()", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "exec('uname -r');", 0);
	zephir_fast_str_replace(&_0, &_1, &_2, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "os.user()", 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "exec('whoami');", 0);
	zephir_fast_str_replace(&_0, &_3, &_4, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "os.type()", 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "exec('uname -o');", 0);
	zephir_fast_str_replace(&_0, &_5, &_6, plang TSRMLS_CC);
	ZEPHIR_CPY_WRT(plang, _0);
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
	zval *plang = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "/cmd\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "exec($1);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/system\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "exec($1);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/exec\\((.*)\\)/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "exec($1);", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 1, _0, _1, plang);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, _2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

