# simple shell

# simple shell

This repository contains the final project of the first trimester at Holberton school, is about building a program as similar as possible to the unix shell using the programming language C.

# Table of Contents 

1. [Authors](#Authors)
2. [How Use](#How-Use)
3. .[explanation](#Explanation)

# Authors

 👤 **Andres Bayona**

- Twitter: [@AndresBayMon](https://twitter.com/AndresBayMon)
- Github:  [@AndrewB4y](https://github.com/AndrewB4y)

👤 **Luis Enrique Sanjuan Melo**

- Twitter: [@lsanjuan92](https://twitter.com/lsanjuan92)
- Github: [@luiscode92](https://github.com/luicode92)

For more information check this post on Medium.
(https://medium.com/@luiscode92/how-to-code-simple-shell-in-c-312ee5dbe154)

# How Use

## How to compile

### Requirements

- All your files will be compiled on Ubuntu 14.04 LTS
- Your C programs and functions will be compiled with gcc 4.8.4
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- No more than 5 functions per file

### Flags to compile

`$ gcc -Wall -Werror -Wextra -pedantic *.c`

## Explanation

## Non interactive

pass the commands in the stdin but no prints the prompt.

`$ echo "ls" | ./hsh`

## interactive

the program is execute and the prompt is print, and wait for the user.

`$ ./hsh`
`($)`

