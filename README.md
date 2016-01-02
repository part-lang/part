### Part language
Sebuah bahasa pemrograman yang difokuskan dalam pengembangan website. Part menggunakan syntax yang simpel, mudah dibaca dan mudah dipelajari.

### Examples
Untuk contoh-contoh kode, bisa dilihat di https://github.com/part-lang/part/tree/master/examples

### Installation
```bash
git clone https://github.com/part-lang/part.git
cd part
chmod +x install
./install
```

### Getting started
Create folder for server
```bash
mkdir hello
cd hello
```

Create file
```bash
nano index.p
```

```php
print "Hello World"
```

Run server
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

Compile single file to static
```bash
cd hello
part -c index.p
```

### License

The MIT License (MIT)

Copyright (c) 2015 Part language

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
