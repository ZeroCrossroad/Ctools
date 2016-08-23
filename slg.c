#include <stdio.h>
char map[100][100];
char patern[10][10];
int ch(int x,int y,int a,int b){
	if(map[x+a][y+b] == patern[a][b]){
		return 1;
	}else{
		return 0;
	}
}
int all(int x,int y,int m){
	int i,j,res=0;
	for(i = 0;i < m;i++){
		for(j = 0;j < m;j++){
			res += ch(x,y,i,j);
		}
	}
	return (res==(m*m))?1:0;
}
int main(void){
	int i,j,n,m;
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			scanf("%d",&map[i][j]);
		}
	}
	scanf("%d",&m);
	for(i = 0;i < m;i++){
		for(j = 0;j < m;j++){
			scanf("%d",&patern[i][j]);
		}
	}
	for(i = 0;i < (n-m+1);i++){
		for(j = 0;j < (n-m+1);j++){
			if(all(i,j,m) == 1){
				printf("%d %d\n",i,j);
			}
		}
	}
    return 0;
}