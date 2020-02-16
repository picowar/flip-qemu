# QEMU-flip

Testing utility to cause determinstic and composable bit flips in CPU registers, flags, memory and binaries.

A bitflip is represented by the tuple: **< *pc*, *L*, *M*, *i* >**

***pc***: Program counter @ which flip is to be triggered</br>
***L***: target register, or memory address</br>
***M***: mask to xor *L* with, allows flipping multiple bits</br>
***i***: Iteration number at which PC hits that value (helps prevent FLIP from triggering flip each time the virtual CPU hits that PC value)

## Building
(Verified to work with Ubuntu 18.04 LTS)
```
mkdir build
cd build
../configure --disable-kvm --enable-debug --target-list="x86_64-linux-user"
make
```

## Example
  
Altering the value of variable `a` in asmexample.c

**Without bitflips:**
```
$ qemu-x86_64 asmexample
Value of A is 6
```
**With bitflips:**
```
$ qemu-x86_64 -bitflips ex-asm-mem.txt asmexample
Read following 1 bitflip(s):
Bitflip 0:
pc = 40000006c8,
mem_ptr = 4001a0243c,
mask = 2,
itr = 1.
Value of A is 8
```

## Creating your own bitflips

To create your own bitflips, you need to know the instruction pointer that you are targeting, and the memory address.
You can find these using GDB.
You will need to open two terminals, and remotely attach GDB.

For instance, in order to find possible bitflip targets for `asmexample.c`, in one terminal run `$ qemu-x86_64 -g 12345 asmexample` and in the another, `$ gdb asmexample`, followed by `(gdb) target remote localhost:12345`, and then proceed normally.

Note that the IP (or program counter) you need points to the instruction that is exactly after the instruction you are targeting, because the QEMU translation of instructions adds bitflips immediately before the next instruction is executed.
