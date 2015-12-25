
extern zend_class_entry *plang_statement_switches_ce;

ZEPHIR_INIT_CLASS(Plang_Statement_Switches);

PHP_METHOD(Plang_Statement_Switches, switchs);

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_statement_switches_switchs, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(plang_statement_switches_method_entry) {
	PHP_ME(Plang_Statement_Switches, switchs, arginfo_plang_statement_switches_switchs, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
