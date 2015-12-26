
extern zend_class_entry *plang_lib_main_ce;

ZEPHIR_INIT_CLASS(Plang_Lib_Main);

PHP_METHOD(Plang_Lib_Main, import);
PHP_METHOD(Plang_Lib_Main, http);
PHP_METHOD(Plang_Lib_Main, server);
PHP_METHOD(Plang_Lib_Main, os);
PHP_METHOD(Plang_Lib_Main, commands);

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_lib_main_import, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_lib_main_http, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_lib_main_server, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_lib_main_os, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_lib_main_commands, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(plang_lib_main_method_entry) {
	PHP_ME(Plang_Lib_Main, import, arginfo_plang_lib_main_import, ZEND_ACC_PUBLIC)
	PHP_ME(Plang_Lib_Main, http, arginfo_plang_lib_main_http, ZEND_ACC_PUBLIC)
	PHP_ME(Plang_Lib_Main, server, arginfo_plang_lib_main_server, ZEND_ACC_PUBLIC)
	PHP_ME(Plang_Lib_Main, os, arginfo_plang_lib_main_os, ZEND_ACC_PUBLIC)
	PHP_ME(Plang_Lib_Main, commands, arginfo_plang_lib_main_commands, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
