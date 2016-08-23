#include <stdio.h>
int main(void){
    char temp[11];
    char res[120];
    int i,n;
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        scanf("%s",temp);
        if(i == 0){
            sprintf(res,"%s",temp);
        }else{
            sprintf(res,"%s_%s",res,temp);
        }
    }
    printf("%s", res);
    return 0;
}
