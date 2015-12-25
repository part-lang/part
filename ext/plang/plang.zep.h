
extern zend_class_entry *plang_plang_ce;

ZEPHIR_INIT_CLASS(Plang_Plang);

PHP_METHOD(Plang_Plang, main_engine);
PHP_METHOD(Plang_Plang, engine);

ZEND_BEGIN_ARG_INFO_EX(arginfo_plang_plang_engine, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(plang_plang_method_entry) {
	PHP_ME(Plang_Plang, main_engine, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Plang_Plang, engine, arginfo_plang_plang_engine, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
