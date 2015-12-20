
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "plang.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *plang_main_plang_ce;

ZEND_DECLARE_MODULE_GLOBALS(plang)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(plang)
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
	ZEPHIR_INIT(Plang_Main_Plang);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(plang)
{

	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_plang_globals *plang_globals TSRMLS_DC)
{
	plang_globals->initialized = 0;

	/* Memory options */
	plang_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	plang_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	plang_globals->cache_enabled = 1;

	/* Recursive Lock */
	plang_globals->recursive_lock = 0;

	/* Static cache */
	memset(plang_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

static PHP_RINIT_FUNCTION(plang)
{

	zend_plang_globals *plang_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(plang_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(plang_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(plang)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(plang)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_PLANG_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_PLANG_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_PLANG_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_PLANG_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_PLANG_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(plang)
{
	php_zephir_init_globals(plang_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(plang)
{

}


zend_function_entry php_plang_functions[] = {
ZEND_FE_END

};

zend_module_entry plang_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_PLANG_EXTNAME,
	php_plang_functions,
	PHP_MINIT(plang),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(plang),
#else
	NULL,
#endif
	PHP_RINIT(plang),
	PHP_RSHUTDOWN(plang),
	PHP_MINFO(plang),
	PHP_PLANG_VERSION,
	ZEND_MODULE_GLOBALS(plang),
	PHP_GINIT(plang),
	PHP_GSHUTDOWN(plang),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_PLANG
ZEND_GET_MODULE(plang)
#endif
