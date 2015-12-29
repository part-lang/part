namespace Part;

class Part {
 
	public static function main_engine() {
        var main, engine, extension, location;
        let location = $_GET["_url"];
        let main = new \Part\Page\Main();
        let engine = new Part();
        if(location == ""){
                let location = "index.p";
        }
        let extension = pathinfo(location, PATHINFO_EXTENSION);
        main->notfound(location);
        
        switch (extension) {
            case "p":
            if(!file_exists("static/".location.".so")){
                engine->engine(location);
                }else{
                main->content("static/".location.".so", "text/html");
            }
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
            let plang = text->variable(plang);
            let plang = text->write(plang);
            let plang = text->symbol(plang);
            let plang = text->html(plang);
            let plang = functions->def_function(plang);
            let plang = functions->class_function(plang);
            let plang = functions->call_function(plang);
            let plang = statement->switch_statement(plang);
            let plang = statement->while_statement(plang);
            let plang = statement->if_statement(plang);
            let plang = statement->for_statement(plang);
            eval(plang);
        
	}

}