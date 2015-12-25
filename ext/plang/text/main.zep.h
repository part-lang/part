
extern zend_class_entry *plang_text_main_ce;

ZEPHIR_INIT_CLASS(Plang_Text_Main);

PHP_METHOD(Plang_Text_Main, symbol);
PHP_METHOD(Plang_Text_Main, write);
PHP_METHOD(Plang_Text_Main, variable);

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_text_main_symbol, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_text_main_write, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_text_main_variable, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(plang_text_main_method_entry) {
	PHP_ME(Plang_Text_Main, symbol, arginfo_plang_text_main_symbol, ZEND_ACC_PUBLIC)
	PHP_ME(Plang_Text_Main, write, arginfo_plang_text_main_write, ZEND_ACC_PUBLIC)
	PHP_ME(Plang_Text_Main, variable, arginfo_plang_text_main_variable, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
