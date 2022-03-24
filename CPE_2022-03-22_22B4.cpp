///CPE_2022-03-22_22B4.cpp
#include <stdio.h>
#include <string.h>
char table[10][10];
char op[20];
void transpose(int N)
{
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(i>j){
				char t=table[i][j];
				table[i][j]=table[j][i];
				table[j][i]=t;
			}
		}
	}
}
void inc(int N)
{
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			table[i][j] = (table[i][j]+1)%10;
		}
	}
}
void dec(int N)
{
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			table[i][j] = (table[i][j]+9)%10;
		}
	}
}
int main()
{
	int T, N, M, a, b;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%s", table[i]);
			for(int j=0; j<N; j++){
				table[i][j] -= '0';
			}
		}

		scanf("%d", &M);
		for(int i=0; i<M; i++){
			scanf("%s", op);
			if(strcmp(op,"transpose")==0) transpose(N);
			if(strcmp(op,"dec")==0) dec(N);
			if(strcmp(op,"inc")==0) inc(N);
			if(strcmp(op,"row")==0){
				scanf("%d %d", &a, &b);
				for(int i=0; i<N; i++){
					char t=table[a-1][i];
					table[a-1][i]=table[b-1][i];
					table[b-1][i]=t;
				}
			}
			if(strcmp(op,"col")==0){
				scanf("%d %d", &a, &b);
				for(int i=0; i<N; i++){
					char t=table[i][a-1];
					table[i][a-1]=table[i][b-1];
					table[i][b-1]=t;
				}
			}
		}

		printf("Case #%d\n", t);
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				printf("%d", table[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
