namespace Part\Lib;

class Curl {
 
    	public static function post(string! url, content, user_agent = "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.13) Gecko/20080311 Firefox/2.0.0.13") {
    	var ch,result;
    	let ch = curl_init(url);
        curl_setopt(ch, CURLOPT_CUSTOMREQUEST, "POST");
        curl_setopt(ch, CURLOPT_RETURNTRANSFER, true);
        curl_setopt(ch, CURLOPT_POSTFIELDS, content);
        curl_setopt(ch, CURLOPT_FOLLOWLOCATION, 1);
        curl_setopt(ch, CURLOPT_USERAGENT,user_agent);
        let result = curl_exec(ch);
        curl_close(ch);
        return result;
    	}
    	
    	public static function get(string! url, content, user_agent = "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.13) Gecko/20080311 Firefox/2.0.0.13"){
    	var ch,result;
    	let ch = curl_init(); 
        curl_setopt(ch, CURLOPT_URL,url.content); 
        curl_setopt(ch, CURLOPT_RETURNTRANSFER, 1);
        curl_setopt(ch, CURLOPT_USERAGENT,user_agent);
        let result = curl_exec(ch); 
        curl_close(ch);
        return result;
    	}
 
}