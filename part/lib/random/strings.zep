namespace Part\Lib\Random;

class Strings {

            public static function random(length = 10) {
                return substr(str_shuffle("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"), 0, $length);
            }

}