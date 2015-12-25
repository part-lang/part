### Plang
Based on Zend Engine

Sebuah bahasa yang difokuskan dalam web development. Plang menggunakan syntax yang mudah dibaca dan mudah dipelajari

### Example Hello World
```java
print 'Hello world'
```
Output : Hello World

### Example Variable

```java
@text = 'Hello World'
print @text
```
Output : Hello World

### Example variable with strlen
```java
@text = 'Hello World'
print strlen(@text)
```
Output : 11

### Example plang + html
```java
@title = 'Hello title'
@content = 'Hello world'

html:
<title>%title%</title>
<body>
<p>%content%</p>
</body>
```

### Example IF

```java
@text = "Hello World"
if(@text >= "5")
print "Higher"
else
print "Low"
end
```
Output : Higher

### Example mathematic
```java
print 1+1
```
Output : 2

### Example fibonacci with function & for

```java
call fibonacci(0, 1)

def fibonacci(@x , @y)

    for(@i = 0 | @i <= 10 | @i++)
        @z = @x + @y
        print @z
        print '<br/>'
        @x = @y    
        @y = @z     
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
```java
class Hello
    public say = 'Null'
    def talk(@text)
    this->say = @text
    end
end

@hello = new Hello()
print @hello->talk("Hello World")
print @hello->say
```
Output : Hello World

### Example import static file
```java
import 'hello.html'
```
### Example function, import
```java
import 'header.html'
@text = "Welcome"
call main(@text)
import 'footer.html'

def main(@hello)
print @hello
end
```
### Example for
```java
@cars = array("Volvo", "BMW", "Toyota")
@arrlength = count(@cars)

for(@x = 0 | @x < @arrlength | @x++)
    print @cars[@x]
    print "<br>"
end
```

### Example while
```java
@i = 1
while(@i <= 10)
    print @i++
end
```
Output: 123456789

### Example http.get() , http.post(), http.request()
```java
print http.get("text")
```
GET : index.p?text=Hello World

OUTPUT : Hello World

```java
print http.post("text")

print '<form method="post">'
print '<input type="text" name="text" value="Hello World">'
print '</form>'
```
POST : text: Hello World

OUTPUT : Hello World