namespace Plang\Text;

class Main {
    /**
	 * Symbol
	 */
	
	public function symbol(plang){
    let plang = str_replace("|", ";", plang);
    let plang = str_replace("plang:", "<?php", plang);
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
	
	public function write(plang){
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
	public function variable(plang) {
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
    let plang = preg_replace("/const (.*) = (.*)/", "define('$1', $2);", plang); // @variable
    return plang;
    } 
}