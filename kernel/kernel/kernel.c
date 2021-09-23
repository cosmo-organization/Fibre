#include <stdio.h>

#include <kernel/tty.h>

void alter_some(){
	
}

void kernel_main(void) {
	terminal_initialize(0x1);
	int c=0;
	while (c<24){
		printf("L                                                                              R");
		c++;
	}
	printf("I                                                                              D");
	printf("M                                                                              D");
	
}
