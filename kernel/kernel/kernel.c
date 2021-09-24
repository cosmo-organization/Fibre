#include <stdio.h>

#include <kernel/tty.h>

void alter_some(){
	
}

void kernel_main(void) {
	terminal_initialize(1);
	printf("Welcome to FibreOS-i386");
	new_line();
	printf("$/root>");
	new_line();
	new_line();
	for(size_t i=0;i<100;i=0){
		printf("L                                                                              R");
		printf("D                                                                              R");
		printf("S                                                                              R");
		printf("F                                                                              R");
		printf("M                                                                              R");
		new_line();
	}
	printf("Something went wrong!!");
	new_line();
	printf("Updating meta channel!");
	new_line();
	printf("L                                                                              R");
	printf("D                                                                              R");
	printf("S                                                                              R");
	printf("F                                                                              R");
	printf("M                                                                              R");
	
	
}
