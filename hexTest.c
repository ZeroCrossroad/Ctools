#include <stdio.h>

int hexToInt(char string){
    int result = string - 0x30;
    if(result < 10){
        return result;
    }else{
        result -= 7;
        return result;
    }
}

int main(void){
	int i;
	char hex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	for(i = 0;i < 16;i++){
		printf("%d\n",hexToInt(hex[i]));
	}
	return 0;
}