///CPE_2022-03-22_22B2.cpp
#include <stdio.h>
long long int step(int x, int y)
{
	int level=x+y;
	int more=level-y;
	long long int ans = more;
	for(int i=0; i<level; i++){
		ans += (i+1);
	}
	return ans;//problem of overflow

}
int main()
{
	int T, a,b,c,d;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		scanf("%d %d %d %d", &a, &b, &c, &d); //(a,b) to (c,d)
		long long int step1=step(a,b);
		long long int step2=step(c,d);
		long long int ans=step1-step2;
		if(ans<0) ans = -ans;
		printf("Case %d: %lld\n", t, ans);
	}

}
