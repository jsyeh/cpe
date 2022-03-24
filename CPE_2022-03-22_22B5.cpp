//CPE_2022-03-22_22B5.cpp
#include <stdio.h>
long long int a[60];//root��{������,��,�N�i�J��{��,���G�O0
//���D����: (x-a0)*(x-a1)*(x-a2) �o���{��
long long int C[60];//�@��N���h�������Y��,�ݭn�αƦC�զX,�Ӹѳo�D, �P�ʺA�W��DP����
long long int TABLE[60][60];//TABLE[p][i] ��ܥ[�J��p�Ӯڮ�,��{�����Y�� x^i
void generate(int N)
{
	for(int i=0; i<60; i++){
		for(int j=0; j<60; j++){
			TABLE[i][j]=0;
		}
	}
	TABLE[0][0] = -a[0];//�Ĥ@�� x-a[0] �� -a[0]
	TABLE[0][1] = 1; //�Ĥ@���� x
	for(int p=1; p<N; p++){
		for(int i=p+1; i>0; i--){
			TABLE[p][i]=TABLE[p-1][i-1];
		}
		for(int i=p; i>=0; i--){
			TABLE[p][i]+= -a[p] * TABLE[p-1][i];
		}
	}
	for(int i=0; i<=N; i++){
		C[i]=TABLE[N-1][i];
	}
}
void output(int i)
{
	if(i==0){//�`�ƶ�,�L�X 0
		if(C[i]==0) printf("+ 0 ");
		if(C[i]>0) printf("+ %lld ", C[i]);
		if(C[i]<0) printf("- %lld ", -C[i]);
	}else if(i==1){
		if(C[i]>1) printf("+ %lldx ", C[i]);
		if(C[i]==1) printf("+ x ");
		if(C[i]==-1) printf("- x ");
		if(C[i]<-1) printf("- %lldx ", -C[i]);
	}else{
		if(C[i]>1) printf("+ %lldx^%d ", C[i], i);
		if(C[i]==1) printf("+ x^%d ", i);
		if(C[i]==-1) printf("- x^%d ", i);
		if(C[i]<-1) printf("- %lldx^%d ", -C[i], i);
	}
}
int main()
{
	int N;
	while( scanf("%d",&N)==1 ){
		for(int i=0; i<N; i++){
			scanf("%lld", &a[i] );
		}

		generate(N);

		if(N==1) printf("x ");
		else printf("x^%d ", N);//�̰���

		for(int i=N-1; i>=0; i--){
			output(i);
		}
		printf("= 0\n");
	}
	return 0;
}
