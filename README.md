### Plang
Based on Zend Engine 2/3

Build with Zephir

Sebuah bahasa yang difokuskan dalam web development. Plang menggunakan syntax yang mudah dibaca dan mudah dipelajari

### Example Hello World
```php
print 'Hello world'
```
Output : Hello World

### Example Variable

```php
var text = 'Hello World'
print var.text
```
Output : Hello World

### Example variable with strlen
```php
var text = 'Hello World'
print strlen.text
```
Output : 11

### Example IF

```php
var text = "Hello World"
if var.text >= "5"
print "Higher"
else
print "Low"
end
```
Output : Higher

### Example mathematic
```php
print 1+1
```
Output : 2

### Example fibonacci with function & for

```php
fibonacci("0", "1")

def fibonacci(var x , var y)
var x = var x
var y = var y

    for(var i = 0; var i <= 10; var i++)
        var z = var x + var y
        print var.z
        print '<br/>'
        var x = var y    
        var y = var z     
    end

end
```

Output :
1
2
3
5
8
13
21
34
55
89
144

### Example Class
```php
class Hello
    public say = 'Null'
    def talk(var text)
    this->say = var.text
    end
end

var hello = new Hello()
print var.hello->talk("Hello World")
print var.hello->say
```
Output : Hello World

### Example import static file
```php
import 'hello.html'
```
### Example function, import
```php
import 'header.html'
var text = "Welcome"
main(var.text)
import 'footer.html'

def main(var hello)
print var.hello
end
```
### Example for
```php
var cars = array("Volvo", "BMW", "Toyota")
var arrlength = count(var.cars)

for(var x = 0; var.x < var arrlength; var x++)
    print var.cars[var.x]
    print "<br>"
end
```
