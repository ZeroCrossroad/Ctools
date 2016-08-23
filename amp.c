/*#include <stdio.h>

int main(void){
	double x1,y1,y2,x3;
	int r1,r2,r3;
	printf("x1: ");
	scanf("%lf",&x1);
	printf("y1: ");
	scanf("%lf",&y1);
	printf("y2: ");
	scanf("%lf",&y2);
	printf("x3: ");
	scanf("%lf",&x3);
	printf("r3: ");
	scanf("%d",&r3);

	r1 = (10.0 / y2)*r3;
	r2 = ((10 * (x1 - x3)) / ((11 * (x3 - x1)) + (10 * y1))) * r3;
	printf("r1: %d\n",r1);
	printf("r2: %d\n",r2);

	return 0;
}*/

#include <stdio.h>
#include <math.h>

int main(void){
	int r_array[] = {10000,11000,12000,13000,15000,16000,18000,20000,22000,24000,27000,30000,33000,36000,39000,43000,47000,51000,56000,62000,68000,75000,82000,96000,
		100000,110000,120000,130000,150000,160000,180000,200000,220000,240000,270000,300000,330000,360000,390000,430000,470000,510000,560000,620000,680000,750000,820000,960000};
	double y2,x3;
	double ex,ey,es;
	int i,j,k;
	int a,b,c;
	double min_e;
	int length = sizeof(r_array)/sizeof(r_array[0]);
	

	printf("y2: ");
	scanf("%lf",&y2);
	printf("x3: ");
	scanf("%lf",&x3);
	

	for(i = 0;i < length;i++){
		for(j = 0;j < length;j++){
			for(k = 0;k < length;k++){
				ex = (-((10.0*r_array[j]*r_array[k])/(((double)r_array[i]*r_array[j])+((double)r_array[k]*r_array[j])+((double)r_array[i]*r_array[k])))) / x3;
				ey = ((10.0 * r_array[k]) / (double)r_array[i] ) / y2;

				es = fabs(1-ey) + fabs(1-ex);
				
				if(i == 0 && j == 0 && k == 0){
					a = i;
					b = j;
					c = k;
					min_e = es;
				}else if(min_e > es){
					a = i;
					b = j;
					c = k;
					min_e = es;
					printf("%d %d %d %lf %lf\n",r_array[i],r_array[j],r_array[k],ex,ey);
					
				}
			}
		}
	}


	
	printf("r1: %d\n",r_array[a]);
	printf("r2: %d\n",r_array[b]);
	printf("r3: %d\n",r_array[c]);
	printf("me: %lf\n",min_e);

	return 0;
}
