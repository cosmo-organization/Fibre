#include <stdio.h>

#include <kernel/tty.h>
#include <asm/io.h>

/*static void clear_interrupts(){
	asm volatile ("cli");
}

static void enable_interrupts(){
	asm volatile ("sti");
}*/
int digit_count(unsigned int number){
	int counter=0;
	while (number!=0){
		unsigned int rem=number%10;
		number-=rem;
		number/=10;
		counter++;
	}
	return counter;
}
void print_number(unsigned int number){
	char digit_ascii_code[10]={48,49,50,51,52,53,54,55,56,57};
	if (number!=0){
		int ndigits=digit_count(number);
		char buffer[20];//maximum 20 digits
		short track=ndigits-1;
		while (number!=0){
			int digit=number%10;
			number-=digit;
			number/=10;
			buffer[track--]=digit_ascii_code[digit];
		}
		for (int i=0;i<ndigits;i++){
			putchar(buffer[i]);
		}
	}else{
		putchar(digit_ascii_code[0]);
	}
}
void kernel_main(void) {
	terminal_initialize(1);
	while (1){
		unsigned short input_from_kbd=inb(0x64);
		print_number(input_from_kbd);
		new_line();
	}
}
