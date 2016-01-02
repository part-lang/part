
extern zend_class_entry *part_text_main_ce;

ZEPHIR_INIT_CLASS(Part_Text_Main);

PHP_METHOD(Part_Text_Main, loader);
PHP_METHOD(Part_Text_Main, html);
PHP_METHOD(Part_Text_Main, symbol);
PHP_METHOD(Part_Text_Main, write);
PHP_METHOD(Part_Text_Main, variable);

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_text_main_loader, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_text_main_html, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_text_main_symbol, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_text_main_write, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_text_main_variable, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(part_text_main_method_entry) {
	PHP_ME(Part_Text_Main, loader, arginfo_part_text_main_loader, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Part_Text_Main, html, arginfo_part_text_main_html, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Part_Text_Main, symbol, arginfo_part_text_main_symbol, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Part_Text_Main, write, arginfo_part_text_main_write, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Part_Text_Main, variable, arginfo_part_text_main_variable, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
