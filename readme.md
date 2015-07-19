Just a couple of functions to read and write a variable
length unsigned long to a file.

This is just me playing around with bitwise operations in C++.

### Running the code

```
$ make
$ ./vlong 4242
```

Should write the bytes to `example.bin`:

```
$ hexdump example.bin
0000000 a1 12
0000002
```
