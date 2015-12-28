namespace Part\Function;

class Main {
    /**
	 * Def function usage:
	 *<code>
	 *      def name()
	 *
	 *      end
	 *</code>
	 */
    private static function def_function(plang) {
    let plang = preg_replace("/def (.*)/", "function $1 {", plang);
    let plang = preg_replace("/def (.*)\((.*)\)/", "function $1($2) {", plang);
    let plang = preg_replace("/public def (.*)\((.*)\)/", "public function $1($2) {", plang);
    let plang = preg_replace("/private def (.*)\((.*)\)/", "private function $1($2) {", plang);
    let plang = preg_replace("/public static def (.*)\((.*)\)/", "public static function $1($2) {", plang);
    let plang = preg_replace("/private static def (.*)\((.*)\)/", "private static function $1($2) {", plang);
    return plang;
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
    private static function class_function(plang) {
    let plang = preg_replace("/class (.*)/", "class $1 {", plang);
    let plang = preg_replace("/public (.*) = (.*)/", "public $$1 = $2;", plang);
    let plang = preg_replace("/private (.*) = (.*)/", "private $$1 = $2;", plang);
    let plang = preg_replace("/protected (.*) = (.*)/", "protected $$1 = $2;", plang);
    let plang = preg_replace("/@this->(.*)/", "$this->$1;", plang);
    let plang = preg_replace("/namespace (.*)/", "namespace $1;", plang); // @variable
    return plang;
    }
    
    /**
	 * Call usage:
	 *<code>
	 *  call name()
	 *</code>
	 */
    private static function call_function(plang) {
    let plang = preg_replace("/call (.*)\((.*)\)/", "$1($2);", plang); // func name()
    return plang;
    }
}