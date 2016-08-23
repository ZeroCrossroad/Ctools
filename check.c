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
	int r_array[] = {
		1000,1100,1200,1300,1500,1600,1800,2000,2200,2400,2700,3000,3300,3600,3900,4300,4700,5100,5600,6200,6800,7500,8200,9600,
		10000,11000,12000,13000,15000,16000,18000,20000,22000,24000,27000,30000,33000,36000,39000,43000,47000,51000,56000,62000,68000,75000,82000,96000,
		100000,110000,120000,130000,150000,160000,180000,200000,220000,240000,270000,300000,330000,360000,390000,430000,470000,510000,560000,620000,680000,750000,820000,960000};
	double x1,y1,y2,x3;
	double r1,r2,r3;
	int i,j,k,per,min_per;
	int a,b,c,min_a,min_b,min_c;
	double e1,e2,es;
	double min_e,min,a_y2,min_y2;
	double min_x,max_x,_min_x,_max_x;
	int length = sizeof(r_array)/sizeof(r_array[0]);
	

	printf("y1: ");
	scanf("%lf",&y1);

	for(per = 10;per < 20;per++){

		x1 = 0.3 + (0.3 * per / 100.0);
		x3 = 0.0 - (0.3 * per / 100.0);
		y2 = (fabs(x3) / (fabs(x1) + fabs(x3)))*y1;

		r1 = (10.0 / y2);
		r2 = ((10.0 * (x1 - x3)) / ((11.0 * (x3 - x1)) + (10.0 * y1)));

		

		for(i = 0;i < length;i++){
			for(j = 0;j < length;j++){
				for(k = 0;k < length;k++){
					e1 = (((double)r_array[i]) / ((double)r_array[k]))/r1;
					e2 = (((double)r_array[j]) / ((double)r_array[k]))/r2;

					es = fabs(1-e1) + fabs(1-e2);
					
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
					}
				}
			}
		}


		min_x = (-((10.0*r_array[b]*r_array[c])/(((double)r_array[a]*r_array[b])+((double)r_array[b]*r_array[c])+((double)r_array[c]*r_array[a]))));
		max_x = ((r_array[a]*y1*r_array[b]) - (10.0*r_array[b]*r_array[c]) )/(((double)r_array[a]*r_array[b])+((double)r_array[b]*r_array[c])+((double)r_array[c]*r_array[a]));
		a_y2 = ((double)10.0*r_array[c])/(double)r_array[a];
		printf("r1: %d ",r_array[a]);
		printf("r2: %d ",r_array[b]);
		printf("r3: %d ",r_array[c]);
		printf("min: %lf ",min_x);
		
		if(per == 10){
			min = min_e;
			min_a = a;
			min_b = b;
			min_c = c;
			_min_x = min_x;
			_max_x = max_x;
			min_per = per;
			min_y2 = a_y2;
		}else if(min > min_e ){
			min = min_e;
			min_a = a;
			min_b = b;
			min_c = c;
			_min_x = min_x;
			_max_x = max_x;
			min_per = per;
			min_y2 = a_y2;

		}
		printf("max: %lf\n",max_x);
	}

	printf("per: %d ",min_per);
	printf("r1: %d ",r_array[min_a]);
	printf("r2: %d ",r_array[min_b]);
	printf("r3: %d ",r_array[min_c]);
	printf("y2: %lf ",min_y2);
	printf("e: %lf ",min);
	printf("mix: %lf ",_min_x);
	printf("max: %lf\n",_max_x);


	return 0;
}
