# To start debugging - can be done in emacs

$ cd build
$ gdb-multiarch blink.elf
(gdb) target remote localhost:3333
(gdb) monitor reset init
(gdb) b <some-break-point>
(gdb) c
