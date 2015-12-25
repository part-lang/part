
extern zend_class_entry *plang_text_variable_ce;

ZEPHIR_INIT_CLASS(Plang_Text_Variable);

PHP_METHOD(Plang_Text_Variable, variable);

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_text_variable_variable, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(plang_text_variable_method_entry) {
	PHP_ME(Plang_Text_Variable, variable, arginfo_plang_text_variable_variable, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
