namespace Part\Lib;

class Cli {

        public static function cli_engine(location){
                var runtime;
                let runtime = new \Part\Part;
                runtime->engine(location);
        }
        
}