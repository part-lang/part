namespace Part\Lib;

class Compile {
    public static function compile_engine(location){
    var compiler, result, files;
    let compiler = new \Part\Part;
    let files = new \Part\Lib\File();
    ob_start();
    compiler->engine(location);
    let result = ob_get_contents();
    mkdir("static", 0700);
    files->create("static/".location.".so",result);
    ob_end_flush();
    echo " Compile ".location." to static files success";
    }
}