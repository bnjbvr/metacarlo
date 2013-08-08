meta-montecarlo
===============

They told me templates are Turing complete, but I only believe in what my compiler can compile.


wat
===

This program computes the value of Pi at runtime, using a Monte-Carlo method.


shut up and take my money
=========================

- `make`
- `./meta-montecarlo`


it segfaults when I try to compile
==================================

I know, right? g++ and clang++ have some trouble compiling it. Bugs on their bug trackers should be open soon.

On my computer, some events can make it easier to compile or not:

- change the value of the seed.
- increase / decrease the number of iterations (don't forget to change the value of the template recursiveness in the Makefile too).
- time of the day. Indeed, if you retry several times in a row, it may compile at some point.


why
===

Because I can.


but templates are awful
=======================

You've nothing to do here, go back to your PHP.

