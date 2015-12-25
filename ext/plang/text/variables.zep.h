
extern zend_class_entry *plang_text_variables_ce;

ZEPHIR_INIT_CLASS(Plang_Text_Variables);

PHP_METHOD(Plang_Text_Variables, variable);

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_text_variables_variable, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(plang_text_variables_method_entry) {
	PHP_ME(Plang_Text_Variables, variable, arginfo_plang_text_variables_variable, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
