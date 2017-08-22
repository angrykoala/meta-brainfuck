Meta Brainfuck
==============

A brainfuck programming language that generates code of itself

## Usage

1. Compile using `make` (requires g++)
2. Execute `./bin/meta_brainfuck`


* Execute `make astyle` to beautify code (requires astyle)
* Execute `make clean` to remove compiled files

## What is this?

_meta-brainfuck_ is a proof of concept of a programming language which execution generates source code of itself. You may even think of it as a transpiler from language A to language A.

The most practical application (if any) I could think of this idea, is to implement programs that, by the language design, will maintain its execution state and data, even if it is stopped or it crashes, whithout any extra implementation needed, as the meta-language is designed that way.

Another (weirder) application may be to modify the code of a meta-program while it is executing from a 3rd program.

## How does it works?

For this proof of concept, the meta language was based on [brainfuck](https://esolangs.org/wiki/Brainfuck) as it is easy to implement an interpreter for it.

A plain _brainfuck_ program consists on 3 parts:

* A _brainfuck_ code: `++++.`.
* A vector of bytes, acting as _memory_.
* A pointer to that memory.

So, the following code in plain brainfuck:
```bf
++>++.
```
_brainfuck code_

Will result in the vector `[2,2]` and will print `2` by the stdout.

In meta-brainfuck, all the elements used by the interpreter, which usually only exists during the execution (memory and pointers) are also specified in the code, the following implementation of meta-brainfuck is the mirror of the previous one:

```
{0} {0}{0}
++>++.
```
_metabf-1_

However, when firing the interpreter, instead of executing all the commands (or steps), it will only execute one, and will dump all the data in a new file:

```
{1} {0}{1}
++>++.
```
_metabf-2_

This, is valid meta-brainfuck code, which can be executed again by the interpreter:
* The first number `{1}` is the current command, because we already executed the first step (`+`) this number is incremented by 1, this tells the interpreter _where_ in the code to continue its execution.
* The second number `{0}` is the _memory pointer_, it indicates where is the pointer in the memory, currently at 0
* The third number `{1}` is actually a list, which represent the memory of the brainfuck program.

If we feed _metabf-2_ to the interpreter again, it will execute the next command (`+`):
```
{2} {0}{2}
++>++.
```
_metabf-3_

Executing again:

```
{3} {1}{2 0}
++>++.
```
_metabf-4_

This time, you can see how the memory vector increased by 1 value (`0`), and the memory pointer increased by one, now pointing to the newly created element.

Executing twice:
```
{4} {1}{2 1}
++>++.
```
_metabf-5_

```
{5} {1}{2 2}
++>++.
```
_metabf-6_

Finally, we execute the last step:

```
{6} {1}{2 2}
++>++.
```
_metabf-7_

This step didn't change any of the internal state (except the code pointer) because `.` will only print the number `2` on the screen.

As you can see, this behaves exactly like the original brainfuck program, but each step is executed separately (like a debugger would) and will generate or replace the code file for another valid code.

Any of the previous codes is a valid meta-brainfuck code that can be directly be feed to the interpreter, without worrying about initial conditions. With an interpreter working like this, it is trivial to make it iteratively feed of a source file and replacing it in each step, allowing you to easily rollback to the previous step in case something goes wrong by re-executing the last stored file, without any lost.

All this behaviour is automatically made by the interpreter, as any brainfuck code can be easily turned to meta-brainfcuk by simply appending the default initial conditions (`{0} {0}{0}`).

This concept can be implemented on different languages, and with other ways of storing the source code such as databases.
