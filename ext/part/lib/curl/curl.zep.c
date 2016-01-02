
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
	zval *url_param = NULL, *content, content_sub, *user_agent = NULL, user_agent_sub, __$true, ch, result, _0, _1, _3;
	zval url;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&user_agent_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&ch);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &url_param, &content, &user_agent);

	if (unlikely(Z_TYPE_P(url_param) != IS_STRING && Z_TYPE_P(url_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'url' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(url_param) == IS_STRING)) {
		zephir_get_strval(&url, url_param);
	} else {
		ZEPHIR_INIT_VAR(&url);
		ZVAL_EMPTY_STRING(&url);
	}
	if (!user_agent) {
		user_agent = &user_agent_sub;
		ZEPHIR_INIT_VAR(user_agent);
		ZVAL_STRING(user_agent, "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.13) Gecko/20080311 Firefox/2.0.0.13");
	}


	ZEPHIR_CALL_FUNCTION(&ch, "curl_init", NULL, 13, &url);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 10036);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "POST");
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 14, &ch, &_0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 19913);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 14, &ch, &_0, &__$true);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 10015);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 14, &ch, &_0, content);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 52);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 14, &ch, &_0, &_3);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 10018);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 14, &ch, &_0, user_agent);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "curl_exec", NULL, 15, &ch);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 16, &ch);
	zephir_check_call_status();
	RETURN_CCTOR(result);

}

PHP_METHOD(Part_Lib_Curl_Curl, get) {

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *content, content_sub, *user_agent = NULL, user_agent_sub, ch, result, _0, _1, _3;
	zval url;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&user_agent_sub);
	ZVAL_UNDEF(&ch);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &url_param, &content, &user_agent);

	if (unlikely(Z_TYPE_P(url_param) != IS_STRING && Z_TYPE_P(url_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'url' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(url_param) == IS_STRING)) {
		zephir_get_strval(&url, url_param);
	} else {
		ZEPHIR_INIT_VAR(&url);
		ZVAL_EMPTY_STRING(&url);
	}
	if (!user_agent) {
		user_agent = &user_agent_sub;
		ZEPHIR_INIT_VAR(user_agent);
		ZVAL_STRING(user_agent, "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.13) Gecko/20080311 Firefox/2.0.0.13");
	}


	ZEPHIR_CALL_FUNCTION(&ch, "curl_init", NULL, 13);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VV(&_0, &url, content);
	ZVAL_LONG(&_1, 10002);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 14, &ch, &_1, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 19913);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 14, &ch, &_1, &_3);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 10018);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_2, 14, &ch, &_1, user_agent);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&result, "curl_exec", NULL, 15, &ch);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 16, &ch);
	zephir_check_call_status();
	RETURN_CCTOR(result);

}

