
extern zend_class_entry *plang_page_main_ce;

ZEPHIR_INIT_CLASS(Plang_Page_Main);

PHP_METHOD(Plang_Page_Main, notfound);
PHP_METHOD(Plang_Page_Main, content);

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_page_main_notfound, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_page_main_content, 0, 0, 2)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, type_header)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(plang_page_main_method_entry) {
	PHP_ME(Plang_Page_Main, notfound, arginfo_plang_page_main_notfound, ZEND_ACC_PUBLIC)
	PHP_ME(Plang_Page_Main, content, arginfo_plang_page_main_content, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
