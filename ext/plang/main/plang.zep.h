
extern zend_class_entry *plang_main_plang_ce;

ZEPHIR_INIT_CLASS(Plang_Main_Plang);

PHP_METHOD(Plang_Main_Plang, main_engine);
PHP_METHOD(Plang_Main_Plang, engine);
PHP_METHOD(Plang_Main_Plang, content);
PHP_METHOD(Plang_Main_Plang, notfound);

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_main_plang_main_engine, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_main_plang_engine, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_main_plang_content, 0, 0, 2)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, type_header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_main_plang_notfound, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(plang_main_plang_method_entry) {
	PHP_ME(Plang_Main_Plang, main_engine, arginfo_plang_main_plang_main_engine, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Plang_Main_Plang, engine, arginfo_plang_main_plang_engine, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Plang_Main_Plang, content, arginfo_plang_main_plang_content, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Plang_Main_Plang, notfound, arginfo_plang_main_plang_notfound, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
