namespace Part;

class Part {

	public static function main_engine() {
        var main, extension, location, phplang, bashlang;
        let location = trim($_SERVER["SCRIPT_NAME"], "/");
        let main = new \Part\Page\Main();
        if(location == ""){
            if(main->config("config","index") == "none"){
                let location = "index.p";
            }else{
                let location = main->config("config","index");
            }
        }

        let extension = pathinfo(location, PATHINFO_EXTENSION);
        main->notfound(location);

        switch (extension) {
            case "p":
            if(!file_exists("static/".location.".static")){
                self::engine(location);
                }else{
                main->content("static/".location.".static", "text/html");
            }
            break;
            
            case "php":
                let phplang = file_get_contents(location, true);
                eval("?> ".phplang);
            break;
            
            case "sh":
                let bashlang = file_get_contents(location, true);
                system(bashlang);
            break;
            
            case "pp":
            main->forbidden();
            break;

            case "ini":
            main->forbidden();
            break;

            case "html":
            main->content(location, "text/html");
            break;

            case "css":
            main->content(location, "text/css");
            break;

            case "js":
            main->content(location, "application/javascript");
            break;

            default:
            main->content(location, "text/plain");
        }
	}

	private static function engine(location)
	{
            var plang, statement, text, functions, library;
            
            let statement = new \Part\Statement\Main();
            let text = new \Part\Text\Main();
            let functions = new \Part\Function\Main();
            let library = new \Part\Lib\Main();
            let plang = file_get_contents(location, true);
            let plang = library->loader(plang);
            let plang = text->loader(plang);
            let plang = functions->loader(plang);
            let plang = statement->loader(plang);
            eval(plang);

	}

}
