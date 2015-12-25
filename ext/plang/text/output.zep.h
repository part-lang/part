
extern zend_class_entry *plang_text_output_ce;

ZEPHIR_INIT_CLASS(Plang_Text_Output);

PHP_METHOD(Plang_Text_Output, print);

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_text_output_print, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(plang_text_output_method_entry) {
	PHP_ME(Plang_Text_Output, print, arginfo_plang_text_output_print, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
