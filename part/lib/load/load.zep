namespace Part\Lib\Load;

class Load {
        public static function load_view(location) {
        var extension, code, part;
        let part = new \Part\Part();
        let code = file_get_contents(location, true);
        let extension = pathinfo(location, PATHINFO_EXTENSION);
        switch (extension) {
            case "p":
            part->engine(location);
            break;
          
            default:
            return code;
            
            }
        }
}