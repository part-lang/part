
extern zend_class_entry *part_lib_random_strings_ce;

ZEPHIR_INIT_CLASS(Part_Lib_Random_Strings);

PHP_METHOD(Part_Lib_Random_Strings, random);

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_lib_random_strings_random, 0, 0, 0)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(part_lib_random_strings_method_entry) {
	PHP_ME(Part_Lib_Random_Strings, random, arginfo_part_lib_random_strings_random, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
