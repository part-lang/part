namespace Part\Lib;

class Compile {

        public static function compile_engine(location){
                var compiler, result, files;
                let compiler = new \Part\Part;
                let files = new Compile();
                ob_start();
                compiler->engine(location);
                let result = ob_get_contents();
                if(!file_exists("static")){
                        mkdir("static", 0700);
                }
                files->create("static/".location.".static",result);
                ob_end_flush();
                echo " Compile ".location." to static files success";
        }
        
        private static function create(string! location, string! content) {
		var file;
		let file = fopen(location,"w");
		fwrite(file, content);
		fclose(file);
	}
}