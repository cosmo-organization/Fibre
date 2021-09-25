#include <asm/io.h>
void outb(short port,unsigned char val){
	asm volatile ("outb %0, %1": : "a"(val) , "Nd"(port));
}
unsigned char inb(short port){
	unsigned char ret;
	asm volatile ("inb %1,%0" :"=a"(ret):"Nd"(port));
	return ret;
}
