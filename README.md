# Introduction and usage

A very simple NASM macro package to incorporate Intel 8080/8085 assembly code
directly into an assembly file. To use it, first include the file as follows:

    %include 'i8080.inc'

Then to switch to the 8080 instruction set, use the following directive:

    code8080

In this mode, the assembler will accept any 8080/8085 instructions, including
undocumented ones. (See
[Intel 8085 opcodes](https://www.pastraiser.com/cpu/i8085/i8085_opcodes.html)
for example). All instructions and register arguments have to be given in lower
case. Then the following directive switches back to 8086 mode:

    code8086

# Caveats and technical details

The `code8080` directive defines several macros to enable 8080/8085
instructions. Since some of the 8080/8085 instruction mnemonics clash with 8086
ones, this means that 8086 instructions should be avoided. However the package
provides no assistance in hiding other 8086 instructions, so technically
8080/8085 and 8086 can be intermixed to some extent. This is however not
recommended.

Most macro definitions are entirely contained in the `code8080` directive
definition, so unless the directive is called, almost no macros will be defined
by default. The `code8086` directive removes these definitions, reverting back
to the original state of the assembler.

While the package has proved useful to the author and has been tested and
checked multiple times, no warranty is provided for its correctness and well
behavior. Use at your own risk!

Note that the Intel 8080/8085 instruction set, while intended to be mostly
compatible with the Intel 8086 (by design of the latter), is very different
in syntax from x86 assembly. Notably, this package will not be useful to anyone
not already familiar with 8080/8085 mnemonics, and makes no attempt to convert
compatible Intel 8086 instructions into their 8080/8085 versions.

