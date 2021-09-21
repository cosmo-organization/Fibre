unsigned char in8(unsigned short port){
	unsigned char value;
	asm __volatile__ ("inb %1, %0":"=a"(value):"Nd"(port));
	return value;
}
void dealy_t(unsigned long microseconds){
	unsigned long i=0;
	for (i;i<microseconds;++i)
		in8(0x80);
}
kernel_main(){
	char* vram=(char*)0xb8000;
	vram[0]='d';
	delay_t(1000000*5);
	vram[1]=0x07;
	vram[2]='e';
	vram[3]=0x08;
	vram[4]='v';
	vram[5]=0x09;
	vram[6]='i';
	vram[7]=0x0a;
	vram[8]='l';
	vram[9]=0x0b;
	vram[10]='O';
	vram[11]=0x0c;
	vram[12]='S';
	vram[13]=0x0d;
}
