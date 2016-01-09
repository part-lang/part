### Getting started

#### Create folder for server
```bash
mkdir hello
cd hello
```

#### Create file
```bash
nano index.p
```

```php
print "Hello World"
```

#### Run file
```bash
part index.p
```

#### Run server
```bash
cd hello
part -s 8080
```

Output:
```bash
Listening on http://0.0.0.0:8080
Document root is /home/devilscream/part/examples
Press Ctrl-C to quit.
```

#### Compile single file to static
```bash
cd hello
part -c index.p
```