// Create file hello.txt
file.create("hello.txt","Hello World")

// Copy file hello.txt to hello_world.txt
file.copy("hello.txt","hello_world.txt")

// Read file hello.txt
print file.read("hello.txt")

// Get size from file hello.txt
print file.size("hello.txt")

// Get size from file hello.txt with format Bytes,KB,MB,GB,TB
print file.size("hello.txt",true)

// Get extension from file hello.txt
print file.ext("hello.txt")

// Get time file created from hello.txt
print file.time("d M Y","hello.txt")