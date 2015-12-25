namespace Plang\Function;

class Main {
    /**
	 * Def function usage:
	 *<code>
	 *      def name()
	 *
	 *      end
	 *</code>
	 */
    public function def_function(plang) {
    let plang = preg_replace("/def (.*)/", "function $1 {", plang);
    let plang = preg_replace("/def (.*)\((.*)\)/", "function $1($2) {", plang);
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
    public function class_function(plang) {
    let plang = preg_replace("/class (.*)/", "class $1 {", plang);
    let plang = preg_replace("/public (.*) = (.*)/", "public $$1 = $2;", plang);
    let plang = preg_replace("/this->(.*)/", "$this->$1;", plang);
    return plang;
    }
    
    /**
	 * Call usage:
	 *<code>
	 *  call name()
	 *</code>
	 */
    public function call_function(plang) {
    let plang = preg_replace("/call (.*)\((.*)\)/", "$1($2);", plang); // func name()
    return plang;
    }
}