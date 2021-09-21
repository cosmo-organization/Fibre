nasm -f elf32 boot.S -o boot.o
gcc -m32 -c kernel.c -o kc.o
ld -m elf_i386 -T linker.ld -o kernel.bin boot.o kc.o
grub-file --is-x86-multiboot kernel.bin
mkdir -p isodir/boot/grub
cp kernel.bin isodir/boot/kernel.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o testbuild.iso isodir
qemu-system-x86_64 -cdrom testbuild.iso
