## jemalloc example

This is a test to have a minimal implementation using jemalloc directly included into a sample app and not linked as an external library. 

It is **not** really intended for normal use. Use a library. 

go [here](https://github.com/jemalloc/jemalloc) for the official and latest

to make this you need cmake > 3.1

```$xslt
$ cmake .
$ make 
$ ./testjemalloc
```