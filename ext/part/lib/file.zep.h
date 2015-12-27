
extern zend_class_entry *part_lib_file_ce;

ZEPHIR_INIT_CLASS(Part_Lib_File);

PHP_METHOD(Part_Lib_File, create);
PHP_METHOD(Part_Lib_File, read);
PHP_METHOD(Part_Lib_File, extension);
PHP_METHOD(Part_Lib_File, time);
PHP_METHOD(Part_Lib_File, size);

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_lib_file_create, 0, 0, 2)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_lib_file_read, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_lib_file_extension, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_lib_file_time, 0, 0, 2)
	ZEND_ARG_INFO(0, format)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_part_lib_file_size, 0, 0, 1)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(part_lib_file_method_entry) {
	PHP_ME(Part_Lib_File, create, arginfo_part_lib_file_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Part_Lib_File, read, arginfo_part_lib_file_read, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Part_Lib_File, extension, arginfo_part_lib_file_extension, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Part_Lib_File, time, arginfo_part_lib_file_time, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Part_Lib_File, size, arginfo_part_lib_file_size, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
