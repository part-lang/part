namespace Part\Lib;

class Main {
		/**
		 * Load all library
		 */

		private static function loader(plang) {
		var library;
		let library = new Main();
		let plang = library->os(plang);
		let plang = library->import(plang);
		let plang = library->http(plang);
		let plang = library->server(plang);
		let plang = library->commands(plang);
		let plang = library->file(plang);
		let plang = library->mysql(plang);
		let plang = library->mysqli(plang);
		let plang = library->curl(plang);
		let plang = library->load(plang);
		let plang = library->session(plang);
		let plang = library->str_random(plang);
		return plang;
		}
		
		/**
		 * Random string usage:
		 *<code>
		 *      string.random()
		 *		string.random(100)
		 *</code>
		 */

		private static function str_random(plang) {
		let plang = preg_replace("/string.random\((.*)\)/", "Part\Lib\Random\Strings::random($1);", plang);
		return plang;
		}

		/**
		 * MySQL usage:
		 *<code>
		 *      mysql.connect()
		 *</code>
		 */

		private static function mysql(plang) {
		let plang = str_replace("mysql.", "mysql_", plang);
		return plang;
		}

		/**
		 * MySQLI usage:
		 *<code>
		 *      mysqli.connect()
		 *</code>
		 */

		private static function mysqli(plang) {
		let plang = str_replace("mysqli.", "mysqli_", plang);
		return plang;
		}

		/**
		 * Curl usage:
		 *<code>
		 *      curl.get(url, parameter, user_agent)
		 *		curl.post(url, parameter, user_agent)
		 *		curl.version()
		 *</code>
		 */

		private static function curl(plang) {
		let plang = preg_replace("/curl.get\((.*)\)/", "Part\Lib\Curl\Curl::get($1);", plang);
		let plang = preg_replace("/curl.post\((.*)\)/", "Part\Lib\Curl\Curl::post($1);", plang);
		let plang = str_replace("curl.version()", "Part\Lib\Curl\Curl::version();", plang);
		return plang;
		}

		/**
		 * Import usage:
		 *<code>
		 *      import Library\Func
		 *</code>
		 */

		private static function import(plang) {
		let plang = preg_replace("/import (.*)/", "use $1;", plang);
		return plang;
		}

		 /**
		 * Load usage:
		 *<code>
		 *      load "file.p"
		 *		require "file.p"
		 *</code>
		 */

		private static function load(plang) {
		let plang = preg_replace("/load (.*)/", "Part\Lib\Load\Load::load_view($1);", plang);
		let plang = preg_replace("/require (.*)/", "Part\Lib\Load\Load::load_view($1);", plang);
		return plang;
		}

		/**
		 * Session usage:
		 *<code>
		 *		session.start()
		 *      session.save(key,value)
		 *		session.get(key)
		 *</code>
		 */

		private static function session(plang) {
		let plang = str_replace("session.start()", "session_start();", plang);
		let plang = str_replace("session.clear()", "session_destroy();", plang);
		let plang = preg_replace("/session.save\((.*),(.*)\)/", "$_SESSION[$1] = $2;", plang);
		let plang = preg_replace("/session.get\((.*)\)/", "$_SESSION[$1]", plang);
		return plang;
		}


		/**
		 * File usage:
		 *<code>
		 *      file.read(location)
		 *		file.size(location)
		 *		file.ext(location)
		 *		file.create(location, content)
		 *		file.copy(location, newlocation)
		 *		file.time(format, location)
		 *</code>
		 */

		private static function file(plang) {
		let plang = preg_replace("/file.read\((.*)\)/", "Part\Lib\File\File::read($1);", plang);
		let plang = preg_replace("/file.load\((.*)\)/", "Part\Lib\File\File::read($1);", plang);
		let plang = preg_replace("/file.size\((.*)\)/", "Part\Lib\File\File::size($1);", plang);
		let plang = preg_replace("/file.ext\((.*)\)/", "Part\Lib\File\File::extension($1);", plang);
		let plang = preg_replace("/file.create\((.*),(.*)\)/", "Part\Lib\File\File::create($1,$2);", plang);
		let plang = preg_replace("/file.copy\((.*),(.*)\)/", "Part\Lib\File\File::copy($1,$2);", plang);
		let plang = preg_replace("/file.time\((.*),(.*)\)/", "Part\Lib\File\File::time($1,$2);", plang);
		let plang = preg_replace("/file.rename\((.*),(.*)\)/", "Part\Lib\File\File::rename($1,$2);", plang);
		let plang = preg_replace("/file.delete\((.*)\)/", "Part\Lib\File\File::delete($1);", plang);
		return plang;
		}

		/**
		 * HTTP usage:
		 *<code>
		 *      http.get("url")
		 *      http.post("post")
		 *      http.request("req")
		 *		http.host()
		 *		http.referer()
		 *		http.user_agent()
		 *		http.method()
		 *		http.header()
		 *		http.ip()
		 *		http.port()
		 *</code>
		 */

		private static function http(plang) {
		let plang = str_replace("http.host()", "$_SERVER['HTTP_HOST'];", plang);
		let plang = str_replace("http.referer()", "$_SERVER['HTTP_REFERER'];", plang);
		let plang = str_replace("http.user_agent()", "$_SERVER['HTTP_USER_AGENT'];", plang);
		let plang = str_replace("http.method()", "$_SERVER['REQUEST_METHOD'];", plang);
		let plang = str_replace("http.header()", "$_SERVER['HTTP_ACCEPT'];", plang);
		let plang = str_replace("http.ip()", "$_SERVER['REMOTE_ADDR'];", plang);
		let plang = str_replace("http.port()", "$_SERVER['REMOTE_PORT'];", plang);
		let plang = preg_replace("/http.get\((.*)\)/", "$_GET[$1];", plang);
		let plang = preg_replace("/http.request\((.*)\)/", "$_REQUEST[$1];", plang);
		let plang = preg_replace("/http.post\((.*)\)/", "$_POST[$1];", plang);
		return plang;
		}

		/**
		 * Server usage:
		 *<code>
		 *      server.self()
		 *      server.domain()
		 *      server.ip()
		 *		server.webserver()
		 *		server.protocol()
		 *		server.admin()
		 *</code>
		 */

		private static function server(plang) {
		let plang = str_replace("server.self()", "$_SERVER['PHP_SELF'];", plang);
		let plang = str_replace("server.domain()", "$_SERVER['SERVER_NAME'];", plang);
		let plang = str_replace("server.ip()", "$_SERVER['SERVER_ADDR'];", plang);
		let plang = str_replace("server.port()", "$_SERVER['SERVER_PORT'];", plang);
		let plang = str_replace("server.webserver()", "$_SERVER['SERVER_SOFTWARE'];", plang);
		let plang = str_replace("server.protocol()", "$_SERVER['SERVER_PROTOCOL'];", plang);
		let plang = str_replace("server.admin()", "$_SERVER['SERVER_ADMIN'];", plang);
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

		private static function os(plang) {
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

		private static function commands(plang) {
		let plang = preg_replace("/cmd\((.*)\)/", "exec($1);", plang);
		let plang = preg_replace("/system\((.*)\)/", "exec($1);", plang);
		let plang = preg_replace("/exec\((.*)\)/", "exec($1);", plang);
		return plang;
		}


}
