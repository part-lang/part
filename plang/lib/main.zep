namespace Plang\Lib;

class Main {

    /**
	 * Import usage:
	 *<code>
	 *      import 'file.html'
	 *</code>
	 */
	 
	public function import(plang) {
	let plang = preg_replace("/import '(.*)'/", "include('$1');", plang); // import 'file'
    return plang;
	}

    /**
	 * HTTP usage:
	 *<code>
	 *      http.get("url")
	 *      http.post("post")
	 *      http.request("req")
	 *</code>
	 */
	 
	public function http(plang) {
	let plang = preg_replace("/http.get\((.*)\)/", "$_GET[$1];", plang);
    let plang = preg_replace("/http.request\((.*)\)/", "$_REQUEST[$1];", plang);
    let plang = preg_replace("/http.post\((.*)\)/", "$_POST[$1];", plang);
    return plang;
	}
	
	/**
	 * OS usage:
	 *<code>
	 *      os.kernel()
	 *      os.user()
	 *      os.type()
	 *</code>
	 */
	 
	public function os(plang) {
	let plang = str_replace("os.kernel()", "exec('uname -r');", plang);
    let plang = str_replace("os.user()", "exec('whoami');", plang);
    let plang = str_replace("os.type()", "exec('uname -o');", plang);
    return plang;
	}
	
	/**
	 * Command usage:
	 *<code>
	 *      cmd("commands")
	 *      system("commands")
	 *      exec("commands")
	 *</code>
	 */
	 
	public function commands(plang) {
	let plang = preg_replace("/cmd\((.*)\)/", "exec($1);", plang);
	let plang = preg_replace("/system\((.*)\)/", "exec($1);", plang);
	let plang = preg_replace("/exec\((.*)\)/", "exec($1);", plang);
    return plang;
	}


}