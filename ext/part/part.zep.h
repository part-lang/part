
extern zend_class_entry *part_part_ce;

ZEPHIR_INIT_CLASS(Part_Part);

PHP_METHOD(Part_Part, main_engine);
PHP_METHOD(Part_Part, engine);

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_part_main_engine, 0, 0, 1)
	ZEND_ARG_INFO(0, types)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_part_engine, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(part_part_method_entry) {
	PHP_ME(Part_Part, main_engine, arginfo_part_part_main_engine, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Part_Part, engine, arginfo_part_part_engine, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
