///CPE_2022-03-22_22B3.cpp
#include <stdio.h>
char color[]="MYCRBGV";
char line[100002];
int main()
{
	int T, M,Y,C;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d %d %d %s", &M,&Y,&C, line);
		for(int i=0; line[i]!=0; i++){
			if(line[i]=='C') C--;
			if(line[i]=='M') M--;
			if(line[i]=='Y') Y--;
			if(line[i]=='G'){ Y--; C--; }
			if(line[i]=='V'){ M--; C--; }
			if(line[i]=='R'){ M--; Y--; }
			if(line[i]=='B'){ M--; C--; Y--; }
		}
		if(M>=0 && Y>=0 && C>=0) printf("YES %d %d %d\n", M,Y,C);
		else printf("NO\n");
	}
	return 0;
}
