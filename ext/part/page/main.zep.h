
extern zend_class_entry *part_page_main_ce;

ZEPHIR_INIT_CLASS(Part_Page_Main);

PHP_METHOD(Part_Page_Main, notfound);
PHP_METHOD(Part_Page_Main, content);
PHP_METHOD(Part_Page_Main, config);

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_page_main_notfound, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_page_main_content, 0, 0, 2)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, type_header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_page_main_config, 0, 0, 2)
	ZEND_ARG_INFO(0, section)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(part_page_main_method_entry) {
	PHP_ME(Part_Page_Main, notfound, arginfo_part_page_main_notfound, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Part_Page_Main, content, arginfo_part_page_main_content, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Part_Page_Main, config, arginfo_part_page_main_config, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
