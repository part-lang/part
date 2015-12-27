namespace Part\Lib;

class File {
 
	public static function create(string! location, string! content) {
	var file;
    let file = fopen(location,"w");
    fwrite(file, content);
    fclose(file);
	}
	
	public static function read(string! location) {
	return file_get_contents(location, true);
	}
	
	public static function extension(string! location) {
	return pathinfo(location, PATHINFO_EXTENSION);
	}
	
	public static function time(string! format, string! location) {
	return date(format, filemtime(location));
	}
	
	public static function copy(string! location, string! newlocation) {
	if (!copy(location, newlocation)) {
    	echo "failed to copy...\n";
	}
	}
	
	public static function size(string! location, format = false) {
	if(format == true){
	    var size, base;
	    array type;
	    let type = [" bytes", " KB", " MB", " GB", " TB"];
    	let size = filesize(location);
	    let base = log(size, 1024);
            if(base > 0){
                return round(pow(1024, base - floor(base)), 2) . type[base];
                }else{
                return "0 bytes";
            }
        }else{
        return filesize(location);
    }
	
	}
}
