#include <stdio.h>
#include <math.h> 

int main(){
	unsigned short a;
	float b;
	int i = 0;
	/*for(;i < 200;i++){
		a = (sin((M_PI/100.0)*i)+1)*127;
		printf("%d,",a);
	}
	for(;i < 256;i++){
		if(i<64){
			a = i+64;
		}else if(i<128){
			a = 128-i+64;
		}else if(i<192){
			a = 128-i+64;
		}else{
			a = i-256+64;
		}
		a *= 32;
		printf("%d,",a);
	}*/
	/*for(;i < 256;i++){
		if(i<128){
			a = 1;
		}else{
			a = 0;
		}
		a *= 4095;
		printf("%d,",a);
	}*/
	/*for(;i < 256;i++){
		if(i<128){
			a = i+128;
		}else{
			a = i-256+128;
		}
		a *= 16;
		printf("%d,",a);
	}*/
	/*for(;i < 200;i++){
		b = sin((M_PI/100.0)*i);
		printf("%lf,",b);
	}*/
	/*for(;i < 200;i++){
		if(i<50){
			b = i;
		}else if(i<100){
			b = 100-i;
		}else if(i<150){
			b = 100-i;
		}else{
			b = i-200;
		}
		b /= 50.0;
		printf("%lf,",b);
	}*/
	/*for(;i < 200;i++){
		if(i<100){
			b = 1;
		}else{
			b = -1;
		}
		printf("%lf,",b);
	}*/
	for(;i < 200;i++){
		if(i<100){
			b = i;
		}else{
			b = i-200;
		}
		b /= 100.0;
		printf("%lf,",b);
	}
	return 0;
}