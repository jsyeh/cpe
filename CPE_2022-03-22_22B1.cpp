///CPE_2022-03-22_22B1.cpp
#include <stdio.h>
int main()
{
	int s, out, total;
	while( scanf("%d",&s)==1 ){
		if(s==0) break;

		int sum=0;
		for(int i=1;   ; i++){
			sum += i;
			if(sum>s){
				out=sum-s;
				total = i;
				break;
			}
		}
		printf("%d %d\n", out, total);
		//forget page + total pages
	}
}//�o�D�ݭn�b�ȤW�e�@�U, �K��z���D�ت��N��
// P1, X2 = 1
// X1, P2 = 2
// P1, P2, X3 = 3
// P1, X2, P3 = 4
// X1, P2, P3 = 5
// P1, P2, P3 X4 = 6
//�ҥH�N�O�[�`�� sum > s �K�O����ɨ�, sum-s �K�O forget �����ӼƦr i �O�`����
