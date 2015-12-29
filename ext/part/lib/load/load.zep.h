
extern zend_class_entry *part_lib_load_load_ce;

ZEPHIR_INIT_CLASS(Part_Lib_Load_Load);

PHP_METHOD(Part_Lib_Load_Load, load_view);

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_lib_load_load_load_view, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(part_lib_load_load_method_entry) {
	PHP_ME(Part_Lib_Load_Load, load_view, arginfo_part_lib_load_load_load_view, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
