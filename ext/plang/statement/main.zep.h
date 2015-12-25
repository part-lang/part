
extern zend_class_entry *plang_statement_main_ce;

ZEPHIR_INIT_CLASS(Plang_Statement_Main);

PHP_METHOD(Plang_Statement_Main, switch_statement);
PHP_METHOD(Plang_Statement_Main, while_statement);
PHP_METHOD(Plang_Statement_Main, if_statement);
PHP_METHOD(Plang_Statement_Main, for_statement);

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_statement_main_switch_statement, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_statement_main_while_statement, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_statement_main_if_statement, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_statement_main_for_statement, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(plang_statement_main_method_entry) {
	PHP_ME(Plang_Statement_Main, switch_statement, arginfo_plang_statement_main_switch_statement, ZEND_ACC_PUBLIC)
	PHP_ME(Plang_Statement_Main, while_statement, arginfo_plang_statement_main_while_statement, ZEND_ACC_PUBLIC)
	PHP_ME(Plang_Statement_Main, if_statement, arginfo_plang_statement_main_if_statement, ZEND_ACC_PUBLIC)
	PHP_ME(Plang_Statement_Main, for_statement, arginfo_plang_statement_main_for_statement, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
