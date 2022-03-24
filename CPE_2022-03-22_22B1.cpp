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
}//這題需要在紙上畫一下, 便能理解題目的意思
// P1, X2 = 1
// X1, P2 = 2
// P1, P2, X3 = 3
// P1, X2, P3 = 4
// X1, P2, P3 = 5
// P1, P2, P3 X4 = 6
//所以就是加總後 sum > s 便是關鍵時刻, sum-s 便是 forget 的那個數字 i 是總頁數
