#include <stdio.h>

typedef struct {
	int Null_X;
	int Null_Y;
	int Gain_X;
	int Gain_Y;
	double slope;
	double intercept;
}null_gain_param_t;

void linear_init(null_gain_param_t* param){
	int NX = param->Null_X;
	int NY = param->Null_Y;
	int GX = param->Gain_X;
	int GY = param->Gain_Y;

	double a = ((double)(GY - NY))/((double)(GX - NX));
	double b = GY - (GX * a);

	param->slope = a;
	param->intercept = b;
}

int linear(null_gain_param_t param,int input){
	if(input <= param.Null_X){
		return 0;
	}else{
		return (int)((param.slope * input) + param.intercept);
	}
}

int main(void){
	null_gain_param_t null_gain[2];
	int i;
	for(i = 0;i < 2;i++){
		null_gain[i].Null_X = 0;
		null_gain[i].Null_Y = 0;
		null_gain[i].Gain_X = 10000;
		null_gain[i].Gain_Y = 10000;
		linear_init(&null_gain[i]);
		printf("a:%lf b:%lf\n",null_gain[i].slope,null_gain[i].intercept);
	}

	printf("%d\n",linear(null_gain[0],0));
	printf("%d\n",linear(null_gain[1],0));

	return 0;
}