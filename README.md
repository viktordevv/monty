# Monty Interpreter 🤖

A language interpreter made in the C programming language to manage stacks and queues (LIFO and FIFO). The aim is to interpret Monty bytecodes files. [Monty](http://montyscoconut.github.io/) is a language that aims to close the gap between scripting and programming languages.

# Compilation.

To compile this project, you can use the following command:

```
$ make
```

# Option Codes.

## Push opcode

The opcode `push` pushes an element to the stack.

**Usage:** `push <int>`, where *int* is an integer.

## Pall opcode

The opcode `pall` prints all the values on the stack, starting from the top of the stack.

**Usage:** `pall`. If the stack is empty, `pall` don’t print anything.

```
$ amonkeyprogrammer@ubuntu:~/monty$ cat -e bytecodes/push_pall_0.m
push 1$
push 2$
push 3$
pall$
$ amonkeyprogrammer@ubuntu:~/monty$ ./monty.run bytecodes/push_pall_0.m
3
2
1
$ amonkeyprogrammer@ubuntu:~/monty$
```

## Pint opcode

The opcode `pint` prints the value at the top of the stack, followed by a new line.

**Usage:** `pint`. If the stack is empty, `pint` print an error message.

```
$ amonkeyprogrammer@ubuntu:~/monty$ cat -e bytecodes/pint.m
push 1$
pint$
push 2$
pint$
push 3$
pint$
$ amonkeyprogrammer@ubuntu:~/monty$ ./monty.run bytecodes/pint.m
1
2
3
$ amonkeyprogrammer@ubuntu:~/monty$
```

## Pop opcode

The opcode `pop` removes the top element of the stack.

**Usage:** `pop`. If the stack is empty, `pop` print an error message.

```
$ amonkeyprogrammer@ubuntu:~/monty$ cat -e bytecodes/pop.m
push 1$
push 2$
push 3$
pall$
pop$
pall$
pop$
pall$
pop$
pall$
$ amonkeyprogrammer@ubuntu:~/monty$ ./monty.run bytecodes/pop.m
3
2
1
2
1
1
$ amonkeyprogrammer@ubuntu:~/monty$
```

## Swap opcode

The opcode `swap` swaps the top two elements of the stack.

**Usage:** `swap`. If the stack contains less than two elements, `swap` print an error message.

```
$ amonkeyprogrammer@ubuntu:~/monty$ cat -e bytecodes/swap.m
push 1$
push 2$
push 3$
pall$
swap$
pall$
$ amonkeyprogrammer@ubuntu:~/monty$ ./monty.run bytecodes/swap.m
3
2
1
2
3
1
$ amonkeyprogrammer@ubuntu:~/monty$
```

## Add opcode

The opcode `add` adds the top two elements of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

* The top element of the stack contains the result.
* The stack is one element shorter.

**Usage:** `add`. If the stack contains less than two elements, `add` print an error message.

```
$ amonkeyprogrammer@ubuntu:~/monty$ cat -e bytecodes/add.m
push 1$
push 2$
push 3$
pall$
add$
pall$
$ amonkeyprogrammer@ubuntu:~/monty$ ./monty.run bytecodes/swap.m
3
2
1
5
1
$ amonkeyprogrammer@ubuntu:~/monty$
```

## Nop opcode

The opcode `nop` doesn’t do anything.

**Usage:** `nop`.

```
$ amonkeyprogrammer@ubuntu:~/monty$ cat -e bytecodes/nop.m
nop$
push 1$
nop$
push 2$
nop$
push 3$
nop$
pall$
nop$
pall$
$ amonkeyprogrammer@ubuntu:~/monty$ ./monty.run bytecodes/nop.m
3
2
1
3
2
1
$ amonkeyprogrammer@ubuntu:~/monty$
```
