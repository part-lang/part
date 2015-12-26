namespace Plang;

class Plang {
 
	public static function main_engine() {
	    var main, engine, extension, location;
	    let location = $_GET["_url"];
	    let main = new \Plang\Page\Main();
	    let engine = new Plang();
	    if(location == ""){
	        let location = "index.p";
	    }
        let extension = pathinfo(location, PATHINFO_EXTENSION);
        main->notfound(location);
	    if(extension == "p"){
            engine->engine(location);
	    }elseif(extension == "html"){
	        main->content(location, "text/html");
	    }else{
            main->content(location, "text/plain");
	    }
	}
	
	public static function engine(location) {
	    var plang, statement, text, functions, library;
	    let statement = new \Plang\Statement\Main();
	    let text = new \Plang\Text\Main();
	    let functions = new \Plang\Function\Main();
	    let library = new \Plang\Lib\Main();
	    let plang = file_get_contents(location, true);
        let plang = library->os(plang);
        let plang = library->import(plang);
        let plang = library->http(plang);
        let plang = library->server(plang);
        let plang = library->commands(plang);
        let plang = text->variable(plang);
        let plang = text->write(plang);
        let plang = text->symbol(plang);
        let plang = functions->def_function(plang);
        let plang = functions->class_function(plang);
        let plang = functions->call_function(plang);
        let plang = statement->switch_statement(plang);
        let plang = statement->while_statement(plang);
        let plang = statement->if_statement(plang);
        let plang = statement->for_statement(plang);
        let plang = preg_replace("/%(.*)%/", "<?php echo $1;?>", plang); // public name = hello
        eval(plang);
	}

}