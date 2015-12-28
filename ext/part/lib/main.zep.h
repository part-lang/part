
extern zend_class_entry *part_lib_main_ce;

ZEPHIR_INIT_CLASS(Part_Lib_Main);

PHP_METHOD(Part_Lib_Main, compiler);
PHP_METHOD(Part_Lib_Main, import);
PHP_METHOD(Part_Lib_Main, file);
PHP_METHOD(Part_Lib_Main, http);
PHP_METHOD(Part_Lib_Main, server);
PHP_METHOD(Part_Lib_Main, os);
PHP_METHOD(Part_Lib_Main, commands);

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_lib_main_compiler, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_lib_main_import, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_lib_main_file, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_lib_main_http, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_lib_main_server, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_lib_main_os, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_lib_main_commands, 0, 0, 1)
	ZEND_ARG_INFO(0, plang)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(part_lib_main_method_entry) {
	PHP_ME(Part_Lib_Main, compiler, arginfo_part_lib_main_compiler, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Part_Lib_Main, import, arginfo_part_lib_main_import, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Part_Lib_Main, file, arginfo_part_lib_main_file, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Part_Lib_Main, http, arginfo_part_lib_main_http, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Part_Lib_Main, server, arginfo_part_lib_main_server, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Part_Lib_Main, os, arginfo_part_lib_main_os, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Part_Lib_Main, commands, arginfo_part_lib_main_commands, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
