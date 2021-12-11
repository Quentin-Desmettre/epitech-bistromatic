# epitech-bistromatic

Epitech bistromatic Project. Made with Noa Trachez and Clément Vandeville.
The goal of this project was to create an infinite calculator, which is able to compute mathematical operations in any given base and with any given operator set.

As a bonus, we handled exponents and floating point numbers on every operator - including floating point exponents.
Also, I made a graphical calculator (using CPP and Qt5) to encapsulate all of this.

## How to build and use

First of all, clone the repo and cd into it.

### Epitech bistromatic:

Build:  
>> $ make official

Usage:  
>> $ echo what_you_want_to_compute | ./calc base operators size_to_read

Example:
>> $ echo "2+5\*8" | ./calc "0123456789" "()+-\*/%" 5  
>> \>\> 42

### Easy bistromatic:

Build:
>> $ make easy

Usage:
>> $ ./calc what_you_want_to_compute

Example:
>> $ ./calc "2+5\*8"  
>> \>\> 42

### Graphic bistromatic:

To use the graphical version of the bistromatic, you need Qt5 installed on your computer.

Build:
>> $ make graphical

Usage:
>> $ ./graphic

## General considerations

Epitech students, beware of -84/-42 if you copy/paste this repository !
