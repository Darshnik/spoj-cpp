//
//  4564_ANARC05H.cpp
//  
//
//  Created by Haijun Deng on 13-3-23.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

int len, cs, dp[32][256];
char num[32];

int solve(int pos, int prev) 
{
	if(pos == len) return 1;
	int &ret = dp[pos][prev];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = pos, sum = 0; i < len; i++) 
    {
		sum += num[i]-'0';
		if(sum >= prev) 
        {
			ret += solve(i + 1, sum);
		}
	}
	return ret;
}

int main() {
	cs = 1;
	while(scanf("%s", num)==1 && isdigit(num[0])) 
    {
		memset(dp, -1, sizeof dp);
		len = strlen(num);
		printf("%d. %d\n", cs++, solve(0, 0));
	}
	return 0;
}