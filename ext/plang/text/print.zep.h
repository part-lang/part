
extern zend_class_entry *plang_text_print_ce;

ZEPHIR_INIT_CLASS(Plang_Text_Print);

PHP_METHOD(Plang_Text_Print, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_text_print_write, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(plang_text_print_method_entry) {
	PHP_ME(Plang_Text_Print, write, arginfo_plang_text_print_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
