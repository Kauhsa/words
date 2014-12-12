words
=====

Little program that reads standard input and prints some statistics. **Tested only on Linux**.

Disclaimer: Not really a C programmer, just felt like tinkering with it a little :-)

## Building

You'll need **CMake 2.8.4+** and a C compiler that can handle C99. Run the following in command line while in project root:

    $ cmake . && make
  
This should output a binary called ``words`` in the project directory.

Or, alternatively, if you'd rather not use ``cmake`` for such a trivial program, the following works too (if you have GCC installed):

    $ gcc -std=c99 main.c dyn_str.c -o words
 
## Usage

Run the following in directory where you compiled the binary:

    $ echo -n "hai linux" | ./words
    Output: xunil iah
    Words: 2
    Length: 9

    $ echo -n "nisumaa oli isäsi ilo aamusin" | ./words
    Output: nisumaa oli isäsi ilo aamusin
    Words: 5
    Length: 29

Or you can use ```<<<``` to redirect a string to stdin, but it seems to add a newline to the end unlike ```echo -n```:

    $ ./words <<< "Hello!"
    Output:
    !elloH
    Words: 1
    Length: 7

You use files as an input also:

    $ ./words < HelloWorld.txt
    Output: 
    !dlrow ,olleH
    Words: 2
    Length: 14
    
Or just type to standard input and press Ctrl+D when you're ready:

    $ ./words
    Hello, world!
    Output: 
    !dlrow ,olleH
    Words: 2
    Length: 14
    
All whitespace (spaces, newlines) are added to length.
