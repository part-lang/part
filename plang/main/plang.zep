namespace Plang\Main;
 
class Plang {
 
	public static function main_engine(location) {
	var plang;
	// Setting index
	if(location == ""){
	let location = "index.p";
	}
	// 404 not found
	if(!file_exists(location)){
	header("HTTP/1.1 404 Not Found");
    header("Date: ".date("D, d M Y h:i:s T"));
    header("Content-Type: text/html; charset=iso-8859-1");
    header("X-Powered-By: P language");
    echo "404 Not Found";
	die();
	}
	
    let plang = file_get_contents(location, true);
    let plang = str_replace("time.now()", "date('H:i:s');", plang);
    let plang = preg_replace("/import '(.*)'/", "include('$1');", plang);
    let plang = preg_replace("/var (.*) = (.*)/", "$$1 = $2;", plang);
    let plang = preg_replace("/strlen.(.*)/", "strlen($$1)", plang);
    let plang = preg_replace("/string.(.*)/", "$$1", plang);
    let plang = preg_replace("/htmlescape.(.*)/", "htmlspecialchars($$1)", plang);
    let plang = preg_replace("/print (.*)/", "echo $1;", plang);
    let plang = preg_replace("/if\((.*)\)/", "if($1){;", plang);
    let plang = preg_replace("/else/", "}else{", plang);
    let plang = preg_replace("/end/", "}", plang);
    eval(plang);
	}
 
}