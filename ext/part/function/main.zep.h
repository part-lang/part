
extern zend_class_entry *part_function_main_ce;

ZEPHIR_INIT_CLASS(Part_Function_Main);

PHP_METHOD(Part_Function_Main, func_function);
PHP_METHOD(Part_Function_Main, def_function);
PHP_METHOD(Part_Function_Main, class_function);
PHP_METHOD(Part_Function_Main, call_function);

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_function_main_func_function, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_function_main_def_function, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_function_main_class_function, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_function_main_call_function, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(part_function_main_method_entry) {
	PHP_ME(Part_Function_Main, func_function, arginfo_part_function_main_func_function, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Part_Function_Main, def_function, arginfo_part_function_main_def_function, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Part_Function_Main, class_function, arginfo_part_function_main_class_function, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Part_Function_Main, call_function, arginfo_part_function_main_call_function, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
