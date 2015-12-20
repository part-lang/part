
extern zend_class_entry *plang_main_plang_ce;

ZEPHIR_INIT_CLASS(Plang_Main_Plang);

PHP_METHOD(Plang_Main_Plang, main_engine);

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_main_plang_main_engine, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(plang_main_plang_method_entry) {
	PHP_ME(Plang_Main_Plang, main_engine, arginfo_plang_main_plang_main_engine, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
