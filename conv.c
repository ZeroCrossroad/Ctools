#include <stdio.h>
#include <math.h> 


#define AMOUNT 6

float x[AMOUNT];
float y[AMOUNT];
float z[AMOUNT];

float origin_x[AMOUNT];
float origin_y[AMOUNT];
float origin_z[AMOUNT];

float base_x[AMOUNT];
float base_y[AMOUNT];
float base_z[AMOUNT];

float length[AMOUNT];
float angle[AMOUNT];
float absAngle[AMOUNT];
float zangle[AMOUNT];

int output[6000];

float phy_x;
float phy_y;
float phy_z;
float offset_x;
float offset_y;
float heab;
float BASE_R = 176.235;
float TOP_R = 110.795;

void calc(void);
void setup(void);

float radians(float deg){
	return (deg * M_PI / 180.0);
}

float magnitude(float x,float y,float z) {
	return pow( x*x + y*y + z*z, 0.5 );
}
int main(){
	int i,j;

	setup();
	for(i = 0;i < 1000;i++){
		heab = sin(radians((i%40)*9))*20;
		calc();
		for(j = 0;j < 6;j++){
			//printf("%d",(int)((length[j]*100)-26053)-2500);
			output[(j*1000)+i] = (int)((length[j]*100)-26053)-2500;
		}
	}
		//printf("%lf\n",radians(10.0) );
    printf("tP\n");
    for(i = 0;i < 6000;i++){
        printf("%d\n",output[i] );
    }
	return 0;
}
void calc(){
	int i;

	for (i = 0; i < AMOUNT; i++) {
		// 回転行列の計算(X-axis)
		x[i] = origin_x[i];
		y[i] = 0 + (origin_y[i] * cos(radians(phy_x))) + (origin_z[i] * -sin(radians(phy_x)));
		z[i] = 0 + (origin_y[i] * sin(radians(phy_x))) + (origin_z[i] * cos(radians(phy_x)));

		// 回転行列の計算(Y-axis)
		x[i] = (x[i] * cos(radians(phy_y))) + 0 + (z[i] * sin(radians(phy_y)));
		y[i] = y[i];
		z[i] = (x[i] * -sin(radians(phy_y))) + 0 + (z[i] * cos(radians(phy_y)));

		// 回転行列の計算(Z-axis)
		x[i] = (x[i] * cos(radians(phy_z))) + (y[i] * -sin(radians(phy_z))) + 0;
		y[i] = (x[i] * sin(radians(phy_z))) + (y[i] * cos(radians(phy_z))) + 0;
		z[i] = z[i];

        //ヒーブの加算
        z[i] += heab;
        x[i] += offset_x;
        y[i] += offset_y;

		//大きさを求める
		length[i] = pow( (x[i]-base_x[i])*(x[i]-base_x[i]) + (y[i]-base_y[i])*(y[i]-base_y[i]) + (z[i]-base_z[i])*(z[i]-base_z[i]), 0.5 );
		//内積から角度を求める
        //angle[i] = getAngle(i);
		//angle[i] = getYAngle(i);
        //絶対角を求める
        //absAngle[i] = getAbsAngle(i);
        //absAngle[i] = getXAngle(i);

        //zangle[i] = getZAngle(i);
	}
}
void setup() {
	int i;
	for (i = 0; i < AMOUNT; i++) {
    	origin_z[i] = 0;
    }

    origin_x[0] = sin(radians(5.765))*TOP_R;
    origin_y[0] = cos(radians(5.765))*TOP_R;
    origin_x[1] = -sin(radians(5.765))*TOP_R;
    origin_y[1] = cos(radians(5.765))*TOP_R;
    origin_x[2] = -cos(radians(24.235))*TOP_R;
    origin_y[2] = -sin(radians(24.235))*TOP_R;
    origin_x[3] = -cos(radians(35.765))*TOP_R;
    origin_y[3] = -sin(radians(35.765))*TOP_R;
    origin_x[4] = cos(radians(35.765))*TOP_R;
    origin_y[4] = -sin(radians(35.765))*TOP_R;
    origin_x[5] = cos(radians(24.235))*TOP_R;
    origin_y[5] = -sin(radians(24.235))*TOP_R;

	for (i = 0; i < AMOUNT; i++) {
    	base_z[i] = -255.98;
    }

    base_x[0] = sin(radians(51.355))*BASE_R;
    base_y[0] = cos(radians(51.355))*BASE_R;
    base_x[1] = -sin(radians(51.355))*BASE_R;
    base_y[1] = cos(radians(51.355))*BASE_R;
    base_x[2] = -cos(radians(-21.355))*BASE_R;
    base_y[2] = -sin(radians(-21.355))*BASE_R;
    base_x[3] = -cos(radians(81.355))*BASE_R;
    base_y[3] = -sin(radians(81.355))*BASE_R;
    base_x[4] = cos(radians(81.355))*BASE_R;
    base_y[4] = -sin(radians(81.355))*BASE_R;
    base_x[5] = cos(radians(-21.355))*BASE_R;
    base_y[5] = -sin(radians(-21.355))*BASE_R;

    phy_x = 0.0;
    phy_y = 0.0;
    phy_z = 0.0;
    offset_x = 0.0;
    offset_y = 0.0;
    heab = 0.0;
}