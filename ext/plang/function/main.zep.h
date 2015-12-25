
extern zend_class_entry *plang_function_main_ce;

ZEPHIR_INIT_CLASS(Plang_Function_Main);

PHP_METHOD(Plang_Function_Main, def_function);
PHP_METHOD(Plang_Function_Main, class_function);
PHP_METHOD(Plang_Function_Main, call_function);

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_function_main_def_function, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_function_main_class_function, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_function_main_call_function, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(plang_function_main_method_entry) {
	PHP_ME(Plang_Function_Main, def_function, arginfo_plang_function_main_def_function, ZEND_ACC_PUBLIC)
	PHP_ME(Plang_Function_Main, class_function, arginfo_plang_function_main_class_function, ZEND_ACC_PUBLIC)
	PHP_ME(Plang_Function_Main, call_function, arginfo_plang_function_main_call_function, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
