#include <stdio.h>

int main(void){
	int data[2][3] = {{4,2,5},{3,2,1}};
    printf("%d",(data[0][0] > data[0][1])?((data[0][1] > data[0][2])?data[0][1]:((data[0][2] < data[0][0])?data[0][2]:data[0][0])):((data[0][1] < data[0][2])?data[0][1]:data[0][2]));
	return 0;
}