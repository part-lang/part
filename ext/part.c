
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "part.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *part_function_main_ce;
zend_class_entry *part_lib_compile_ce;
zend_class_entry *part_lib_curl_curl_ce;
zend_class_entry *part_lib_file_file_ce;
zend_class_entry *part_lib_load_load_ce;
zend_class_entry *part_lib_main_ce;
zend_class_entry *part_page_main_ce;
zend_class_entry *part_part_ce;
zend_class_entry *part_statement_main_ce;
zend_class_entry *part_text_main_ce;

ZEND_DECLARE_MODULE_GLOBALS(part)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(part)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(Part_Function_Main);
	ZEPHIR_INIT(Part_Lib_Compile);
	ZEPHIR_INIT(Part_Lib_Curl_Curl);
	ZEPHIR_INIT(Part_Lib_File_File);
	ZEPHIR_INIT(Part_Lib_Load_Load);
	ZEPHIR_INIT(Part_Lib_Main);
	ZEPHIR_INIT(Part_Page_Main);
	ZEPHIR_INIT(Part_Part);
	ZEPHIR_INIT(Part_Statement_Main);
	ZEPHIR_INIT(Part_Text_Main);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(part)
{

	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_part_globals *part_globals TSRMLS_DC)
{
	part_globals->initialized = 0;

	/* Memory options */
	part_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	part_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	part_globals->cache_enabled = 1;

	/* Recursive Lock */
	part_globals->recursive_lock = 0;

	/* Static cache */
	memset(part_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

static PHP_RINIT_FUNCTION(part)
{

	zend_part_globals *part_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(part_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(part_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(part)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(part)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_PART_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_PART_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_PART_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_PART_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_PART_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(part)
{
	php_zephir_init_globals(part_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(part)
{

}


zend_function_entry php_part_functions[] = {
ZEND_FE_END

};

zend_module_entry part_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_PART_EXTNAME,
	php_part_functions,
	PHP_MINIT(part),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(part),
#else
	NULL,
#endif
	PHP_RINIT(part),
	PHP_RSHUTDOWN(part),
	PHP_MINFO(part),
	PHP_PART_VERSION,
	ZEND_MODULE_GLOBALS(part),
	PHP_GINIT(part),
	PHP_GSHUTDOWN(part),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_PART
ZEND_GET_MODULE(part)
#endif
