### Plang
Based on Zend Engine 2/3

Build with Zephir

Sebuah bahasa yang difokuskan dalam web development. Plang menggunakan syntax yang mudah dibaca dan mudah dipelajari

### Example Hello World
```ruby
print 'Hello world'
```
Output : Hello World

### Example Variable

```ruby
var text = 'Hello World'
print var.text
```
Output : Hello World

### Example variable with strlen
```ruby
var text = 'Hello World'
print strlen.text
```
Output : 11

### Example plang + html
```ruby
var title = 'Hello title'
var content = 'Hello world'

html:
<title>%title%</title>
<body>
<p>%content%</p>
</body>
```

### Example IF

```ruby
var text = "Hello World"
if var.text >= "5"
print "Higher"
else
print "Low"
end
```
Output : Higher

### Example mathematic
```ruby
print 1+1
```
Output : 2

### Example fibonacci with function & for

```ruby
fibonacci("0", "1")

def fibonacci(var x , var y)

    for(var i = 0 | var i <= 10 | var i++)
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
```ruby
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
```ruby
import 'hello.html'
```
### Example function, import
```ruby
import 'header.html'
var text = "Welcome"
main(var.text)
import 'footer.html'

def main(var hello)
print var.hello
end
```
### Example for
```ruby
var cars = array("Volvo", "BMW", "Toyota")
var arrlength = count(var.cars)

for(var x = 0 | var.x < var arrlength | var x++)
    print var.cars[var.x]
    print "<br>"
end
```

### Example http.get() , http.post(), http.request()
```ruby
print http.get("text")
```
GET : index.p?text=Hello World

OUTPUT : Hello World

```ruby
print http.post("text")

print '<form method="post">'
print '<input type="text" name="text" value="Hello World">'
print '</form>'
```
POST : text: Hello World

OUTPUT : Hello World