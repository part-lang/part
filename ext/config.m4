PHP_ARG_ENABLE(plang, whether to enable plang, [ --enable-plang   Enable Plang])

if test "$PHP_PLANG" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, PLANG_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_PLANG, 1, [Whether you have Plang])
	plang_sources="plang.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c plang/function/main.zep.c
	plang/lib/main.zep.c
	plang/page/main.zep.c
	plang/plang.zep.c
	plang/statement/main.zep.c
	plang/text/main.zep.c "
	PHP_NEW_EXTENSION(plang, $plang_sources, $ext_shared,, )
	PHP_SUBST(PLANG_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([plang], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([plang], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/plang], [php_PLANG.h])

fi
