
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Part_Lib_Curl_Curl) {

	ZEPHIR_REGISTER_CLASS(Part\\Lib\\Curl, Curl, part, lib_curl_curl, part_lib_curl_curl_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Part_Lib_Curl_Curl, post) {

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *content, *user_agent = NULL, *ch = NULL, *result = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &url_param, &content, &user_agent);

	if (unlikely(Z_TYPE_P(url_param) != IS_STRING && Z_TYPE_P(url_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'url' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(url_param) == IS_STRING)) {
		zephir_get_strval(url, url_param);
	} else {
		ZEPHIR_INIT_VAR(url);
		ZVAL_EMPTY_STRING(url);
	}
	if (!user_agent) {
		ZEPHIR_INIT_VAR(user_agent);
		ZVAL_STRING(user_agent, "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.13) Gecko/20080311 Firefox/2.0.0.13", 1);
	}


	ZEPHIR_CALL_FUNCTION(&ch, "curl_init", NULL, 8, url);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 10036);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "POST", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 9, ch, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 19913);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 9, ch, &_0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 10015);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 9, ch, &_0, content);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 52);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 9, ch, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 10018);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 9, ch, &_0, user_agent);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "curl_exec", NULL, 10, ch);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 11, ch);
	zephir_check_call_status();
	RETURN_CCTOR(result);

}

PHP_METHOD(Part_Lib_Curl_Curl, get) {

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *content, *user_agent = NULL, *ch = NULL, *result = NULL, *_0, _1 = zval_used_for_init, _3;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &url_param, &content, &user_agent);

	if (unlikely(Z_TYPE_P(url_param) != IS_STRING && Z_TYPE_P(url_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'url' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(url_param) == IS_STRING)) {
		zephir_get_strval(url, url_param);
	} else {
		ZEPHIR_INIT_VAR(url);
		ZVAL_EMPTY_STRING(url);
	}
	if (!user_agent) {
		ZEPHIR_INIT_VAR(user_agent);
		ZVAL_STRING(user_agent, "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.13) Gecko/20080311 Firefox/2.0.0.13", 1);
	}


	ZEPHIR_CALL_FUNCTION(&ch, "curl_init", NULL, 8);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_VV(_0, url, content);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 10002);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 9, ch, &_1, _0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 19913);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 9, ch, &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 10018);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 9, ch, &_1, user_agent);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "curl_exec", NULL, 10, ch);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 11, ch);
	zephir_check_call_status();
	RETURN_CCTOR(result);

}

