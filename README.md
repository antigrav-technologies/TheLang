# TheLang
TheLang is an esoteric programming language (esolang) derived from Brainfuck, encoded in base1 using the word "the".

How It Works
-------------

To rewrite a program from Brainfuck to TheLang, follow these steps:

1. Convert each command to its corresponding number:
	* \< - 0
	* \> - 1
	* \+ - 2
	* \- - 3
	* \. - 4
	* \, - 5
	* \[ - 6
	* \] - 7
2. Convert the reversed sequence to an octal (base8) number.
3. Enter that many "the"s.

Example
-------

Let's encode the Brainfuck code `--.`:

1. Convert to numbers: `--.` becomes `334`.
2. Reverse the sequence: `334` -> `0o433` -> `283`.
3. Append "the" that many times:
```
the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the the
```

Compiling
----------

Simply run the `make` utility. Requires gcc.

Usage
-----

To run a TheLang program, use the provided interpreter:
```
./TheLang <input.the>
```

Contributing
------------

Contributions are welcome. Please fork the repository and submit a pull request.
### Rules to contributors:

1. DO NOT LAUGH AT MY CODE
2. DO NOT SWEAR MY CODE\
breaking rules is punishable by death and segfault in your brain

License
-------
I can't stop you anyway. Do whatever you want.