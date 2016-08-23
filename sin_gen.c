#include <stdio.h>
#include <math.h>


void main(){
	double i = 0.0;
	for(i = 0;i < 256.0;i+=1.0){
		printf("%1.8f,",(sin((M_PI / 128.0) * i)*0.5)+0.5);
	}
}