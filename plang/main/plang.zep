namespace Plang\Main;
 
class Plang {
 
	public static function main_engine() {
	var main;
	var extension;
	var location;
	let location = $_GET["_url"];
	let main = new Plang();
	// Setting index
	if(location == ""){
	let location = "index.p";
	}
    let extension = pathinfo(location, PATHINFO_EXTENSION);
    main->notfound(location); // 404 not found
	if(extension == "p"){
    main->engine(location);
	}elseif(extension == "html"){
	main->content(location, "text/html");
	}else{
    main->content(location, "text/plain");
	}
	}
	
	public static function engine(location) {
	var plang;
	var main;
	let main = new Plang();
	let plang = file_get_contents(location, true);
    let plang = str_replace("os.kernel()", "exec('uname -r');", plang);
    let plang = str_replace("os.user()", "exec('whoami');", plang);
    let plang = str_replace("os.type()", "exec('uname -o');", plang);
    let plang = str_replace("time.now()", "date('H:i:s');", plang);
    let plang = str_replace("|", ";", plang);
    let plang = str_replace("plang:", "<?php", plang);
    let plang = str_replace("html:", "?>", plang);
    let plang = preg_replace("/cmd\((.*)\)/", "exec($1);", plang); // cmd(func)
    let plang = preg_replace("/import '(.*)'/", "include('$1');", plang); // import 'file'
    let plang = main->http(plang);
    let plang = main->variable(plang);
    let plang = main->print(plang);
    let plang = preg_replace("/while\((.*)\)/", "while($1){", plang); // while(statement)
    let plang = preg_replace("/if\((.*)\)/", "if($1){", plang); // if(var.text == blalala)
    let plang = preg_replace("/elseif (.*)/", "} else if($1){", plang); // elseif
    let plang = preg_replace("/for\((.*)\)/", "for($1){", plang); // for(statement)
    let plang = preg_replace("/foreach\((.*)\)/", "foreach($1){", plang); // foreach(statemet)
    let plang = preg_replace("/call (.*)\((.*)\)/", "$1($2);", plang); // func name()
    let plang = preg_replace("/(.*)\((.*)\)/", "$1($2)", plang); // func name()
    let plang = preg_replace("/def (.*)/", "function $1 {", plang); // def name()
    let plang = preg_replace("/def (.*)\((.*)\)/", "function $1($2) {", plang); // def name()
    let plang = preg_replace("/else/", "}else{", plang); // else
    let plang = preg_replace("/end/", "}", plang); // end
    let plang = preg_replace("/class (.*)/", "class $1 {", plang); // class
    let plang = preg_replace("/public (.*) = (.*)/", "public $$1 = $2;", plang); // public name = hello
    let plang = preg_replace("/this->(.*)/", "$this->$1;", plang); // public name = hello
    let plang = preg_replace("/%(.*)%/", "<?php echo $1;?>", plang); // public name = hello
    eval(plang);
	}
	
	public static function content(location, type_header) {
	var plang;
	header("Content-Type: ".type_header."; charset=iso-8859-1");
	let plang = file_get_contents(location, true);
	echo plang;
	}
	
	public static function notfound(location) {
	if(!file_exists(location)){
	header("HTTP/1.1 404 Not Found");
    header("Date: ".date("D, d M Y h:i:s T"));
    header("Content-Type: text/html; charset=iso-8859-1");
    header("X-Powered-By: P language");
    echo "404 Not Found";
	die();
	}
	}
	
	private static function print(plang){
    let plang = preg_replace("/write (.*)/", ";echo $1;", plang); // write text
    let plang = preg_replace("/print (.*)/", ";echo $1;", plang); // print text
    let plang = preg_replace("/return (.*)/", ";return $1;", plang); // return text
	return plang;
	}
	
	private static function http(plang) {
	let plang = preg_replace("/http.get\((.*)\)/", "$_GET[$1];", plang); // http.get()
    let plang = preg_replace("/http.request\((.*)\)/", "$_REQUEST[$1];", plang); // http.request()
    let plang = preg_replace("/http.post\((.*)\)/", "$_POST[$1];", plang); // http.post()
    return plang;
	}
	
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
    return plang;
    } 
}