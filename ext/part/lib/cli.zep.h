
extern zend_class_entry *part_lib_cli_ce;

ZEPHIR_INIT_CLASS(Part_Lib_Cli);

PHP_METHOD(Part_Lib_Cli, cli_engine);

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_lib_cli_cli_engine, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(part_lib_cli_method_entry) {
	PHP_ME(Part_Lib_Cli, cli_engine, arginfo_part_lib_cli_cli_engine, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
