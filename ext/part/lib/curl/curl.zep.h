
extern zend_class_entry *part_lib_curl_curl_ce;

ZEPHIR_INIT_CLASS(Part_Lib_Curl_Curl);

PHP_METHOD(Part_Lib_Curl_Curl, post);
PHP_METHOD(Part_Lib_Curl_Curl, get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_lib_curl_curl_post, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, user_agent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_lib_curl_curl_get, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, user_agent)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(part_lib_curl_curl_method_entry) {
	PHP_ME(Part_Lib_Curl_Curl, post, arginfo_part_lib_curl_curl_post, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Part_Lib_Curl_Curl, get, arginfo_part_lib_curl_curl_get, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
