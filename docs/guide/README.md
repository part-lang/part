### Getting started

#### Create application
```bash
part create hello
```

#### Run application
```bash
cd hello
part index.p
```

#### Run application with http server
```bash
cd hello
part run 8080
```

Output:
```bash
Listening on http://0.0.0.0:8080
Document root is /home/devilscream/part/examples
Press Ctrl-C to quit.
```

#### Compile file to static
```bash
cd hello
part compile index.p
```