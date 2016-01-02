
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_PART_H
#define PHP_PART_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_PART_NAME        "part"
#define PHP_PART_VERSION     "0.0.1"
#define PHP_PART_EXTNAME     "part"
#define PHP_PART_AUTHOR      ""
#define PHP_PART_ZEPVERSION  "0.9.1a-dev"
#define PHP_PART_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(part)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(part)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(part)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(part_globals_id, zend_part_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (part_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_part_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(part_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(part_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def part_globals
#define zend_zephir_globals_def zend_part_globals

extern zend_module_entry part_module_entry;
#define phpext_part_ptr &part_module_entry

#endif
