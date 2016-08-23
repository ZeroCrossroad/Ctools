#include <stdio.h>
#include <math.h> 

void main(){
	double a,b,T,Rt;
	a = 0.0039083;
	b = -0.0000005775;
	T = 0.1;
	for(;T < 500;T += 0.1){
		Rt = 100 * (1 + (a * T) + (b * T * T));
		printf("%lf %lf\n",T,Rt);
	}
	return 0;
}