
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Part_Function_Main) {

	ZEPHIR_REGISTER_CLASS(Part\\Function, Main, part, function_main, part_function_main_method_entry, 0);

	return SUCCESS;

}

/**
 * Load all function
 */
PHP_METHOD(Part_Function_Main, loader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL;
	zval *plang = NULL, plang_sub, _0;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_CALL_SELF(&_0, "def_function", &_1, 1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_SELF(&_0, "func_function", &_2, 2, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_SELF(&_0, "class_function", &_3, 3, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	ZEPHIR_CALL_SELF(&_0, "call_function", &_4, 4, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_0);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * Func function usage:
 *<code>
 *      func name()
 *
 *      end
 *</code>
 */
PHP_METHOD(Part_Function_Main, func_function) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *plang = NULL, plang_sub, _0, _1, _2;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/func (.*)/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "function $1 {");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/func (.*)\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "function $1($2) {");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/public func (.*)\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "public function $1($2) {");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/private func (.*)\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "private function $1($2) {");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/public static func (.*)\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "public static function $1($2) {");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/private static func (.*)\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "private static function $1($2) {");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * Def function usage:
 *<code>
 *      def name()
 *
 *      end
 *</code>
 */
PHP_METHOD(Part_Function_Main, def_function) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *plang = NULL, plang_sub, _0, _1, _2;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/def (.*)/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "function $1 {");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/def (.*)\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "function $1($2) {");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/public def (.*)\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "public function $1($2) {");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/private def (.*)\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "private function $1($2) {");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/public static def (.*)\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "public static function $1($2) {");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/private static def (.*)\\((.*)\\)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "private static function $1($2) {");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * Class usage:
 *<code>
 *      class Name
 *
 *          def name()
 *
 *          end
 *
 *      end
 *</code>
 */
PHP_METHOD(Part_Function_Main, class_function) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *plang = NULL, plang_sub, _0, _1, _2;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/class (.*)/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "class $1 {");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/public (.*) = (.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "public $$1 = $2;");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/private (.*) = (.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "private $$1 = $2;");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/protected (.*) = (.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "protected $$1 = $2;");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/@this->(.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "$this->$1;");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/namespace (.*)/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "namespace $1;");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", &_3, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

/**
 * Call usage:
 *<code>
 *  call name()
 *</code>
 */
PHP_METHOD(Part_Function_Main, call_function) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *plang = NULL, plang_sub, _0, _1, _2;
		zval this_zv;
	zval *this_ptr = getThis();
	if (EXPECTED(this_ptr)) {
		ZVAL_OBJ(&this_zv, Z_OBJ_P(this_ptr));
		this_ptr = &this_zv;
	} else this_ptr = NULL;
	
	ZVAL_UNDEF(&plang_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &plang);

	ZEPHIR_SEPARATE_PARAM(plang);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/call (.*)\\((.*)\\)/");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "$1($2);");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", NULL, 5, &_0, &_1, plang);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(plang, &_2);
	RETVAL_ZVAL(plang, 1, 0);
	RETURN_MM();

}

