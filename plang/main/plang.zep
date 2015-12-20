namespace Plang\Main;
 
class Plang {
 
	public static function main_engine(location) {
    var plang;
    let plang = file_get_contents(location, true);
    let plang = str_replace("time.now()", "date('H:i:s');", plang);
    let plang = preg_replace("/import '(.*)'/", "include('$1');", plang);
    let plang = preg_replace("/var (.*) = (.*)/", "$$1 = $2;", plang);
    let plang = preg_replace("/main.(.*)/", "$$1", plang);
    let plang = preg_replace("/write (.*)/", "echo $1;", plang);
    
    eval(plang);
	}
 
}