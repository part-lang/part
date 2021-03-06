namespace Part\Text;

class Main {
        /**
         * Load all text
         */

        private static function loader(plang) {
        let plang = self::variable(plang);
        let plang = self::write(plang);
        let plang = self::symbol(plang);
        let plang = self::html(plang);
        return plang;
        }

         /**
         * HTML Template
         */

        private static function html(plang){
        let plang = preg_replace("/%(.*)%/", "<?php echo $1;?>", plang); // public name = hello
        return plang;
        }
        /**
         * Symbol
         */
        private static function symbol(plang){
        let plang = str_replace("|", ";", plang);
        let plang = str_replace("part:", "<?php", plang);
        let plang = str_replace("html:", "?>", plang);
        return plang;
        }

        /**
         * Print usage:
         *<code>
         *      print "Hello World"
         *      write "Hello World"
         *      return "Hello World"
         *</code>
         */

        private static function write(plang){
        let plang = preg_replace("/write (.*)/", ";echo $1;", plang);
        let plang = preg_replace("/print (.*)/", ";echo $1;", plang);
        let plang = preg_replace("/return (.*)/", ";return $1;", plang);
        return plang;
        }

        /**
         * Variable usage:
         *<code>
         *      @hello = "Hello World"
         *      print @hello
         *</code>
         */
        private static function variable(plang) {
        let plang = preg_replace("/@(.*) = (.*)/", "$$1 = $2;", plang); // @= "text"
        let plang = preg_replace("/@(.*)/", "$$1", plang); // @text
        let plang = preg_replace("/@(.*) = (.*)/", "$$1 = $2;", plang); // @= "text"
        let plang = preg_replace("/@(.*)/", "$$1", plang); // @text
        let plang = preg_replace("/@(.*) = (.*)/", "$$1 = $2;", plang); // @= "text"
        let plang = preg_replace("/@(.*)/", "$$1", plang); // @text
        let plang = preg_replace("/@(.*) = (.*)/", "$$1 = $2;", plang); // @= "text"
        let plang = preg_replace("/@(.*)/", "$$1", plang); // @text
        let plang = preg_replace("/@(.*) = (.*)/", "$$1 = $2;", plang); // @= "text"
        let plang = preg_replace("/@(.*)/", "$$1", plang); // @text
        let plang = preg_replace("/@(.*) = (.*)/", "$$1 = $2;", plang); // @= "text"
        let plang = preg_replace("/@(.*)/", "$$1", plang); // var text
        let plang = preg_replace("/@(.*)/", "$$1", plang); // @variable
        let plang = preg_replace("/@(.*)/", "$$1", plang); // @variable
        let plang = preg_replace("/@(.*)/", "$$1", plang); // @variable
        let plang = preg_replace("/@(.*)/", "$$1", plang); // @variable
        let plang = preg_replace("/@(.*)/", "$$1", plang); // @variable
        let plang = preg_replace("/@(.*)/", "$$1", plang); // @variable
        let plang = preg_replace("/@(.*)/", "$$1", plang); // @variable
        let plang = preg_replace("/@(.*)/", "$$1", plang); // @variable
        let plang = preg_replace("/const (.*) = (.*)/", "const $1 = $2;", plang); // @variable
        return plang;
        }
}
