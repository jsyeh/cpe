//CPE_2022-03-22_22B5.cpp
#include <stdio.h>
int a[100];//root��{������,��,�N�i�J��{��,���G�O0
//���D����: (x-a0)*(x-a1)*(x-a2) �o���{��
//int C[60]={6,+5,0,3,4};//�@��N���h�������Y��,�ݭn�αƦC�զX,�Ӹѳo�D�C�i��]�P�ʺA�W��DP����
int C[60]={0,-1,0,3,4};//�@��N���h�������Y��,�ݭn�αƦC�զX,�Ӹѳo�D�C�i��]�P�ʺA�W��DP����
void generate(int N)
{
	C[0]=1;
	for(int i=0; i<N; i++) C[0]*=a[i];

}
void output(int i)
{
	if(i==0){//�`�ƶ�,�L�X 0
		if(C[i]==0) printf("+ 0 ");
		if(C[i]>0) printf("+ %d ", C[i]);
		if(C[i]<0) printf("- %d ", -C[i]);
	}else if(i==1){
		if(C[i]>0) printf("+ %dx ", C[i]);
		if(C[i]<0) printf("- %dx ", -C[i]);
	}else{
		if(C[i]>1) printf("+ %dx^%d ", C[i], i);
		if(C[i]==1) printf("+ x^%d ", i);
		if(C[i]==-1) printf("- x^%d ", i);
		if(C[i]<-1) printf("- %dx^%d ", -C[i], i);
	}
}
int main()
{
	int N;
	while( scanf("%d",&N)==1 ){
		for(int i=0; i<N; i++){
			scanf("%d", &a[i] );
		}

		generate(N);

		printf("x^%d ", N);//�̰���
		for(int i=N-1; i>=0; i--){
			output(i);
		}
		printf("= 0\n");
	}
	return 0;
}
