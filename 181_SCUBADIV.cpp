//
//  181_ SCUBADIV.cpp
//  
//
//  Created by Haijun Deng on 13-3-14.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 Sample input:
 1
 5 60
 5
 3 36 120
 10 25 129
 5 50 250
 1 45 130
 4 20 119
 
 Sample output:
 249
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1024;
const int INF = 0x3f3f3f3f;

int N, O, n, test, cs;
int nitro[MAX], oxi[MAX], w[MAX];
int dp[MAX][22][80], fl[MAX][22][80];

int solve(int i, int co, int cn) 
{
	if(co >= O && cn >= N) 
        return 0; 
    if(i == n) 
        return INF;
	if(co >= O) 
        co = O; 
    if(cn >= N) 
        cn = N;
	if(fl[i][co][cn] == cs) 
        return dp[i][co][cn]; 
    fl[i][co][cn] = cs;
	return dp[i][co][cn] = min(solve(i+1, co, cn), solve(i+1, co + oxi[i], cn + nitro[i]) + w[i]);
}

int main() 
{
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) 
    {
		scanf("%d %d %d", &O, &N, &n);
		for(int i = 0; i < n; i++) 
            scanf("%d %d %d", &oxi[i], &nitro[i], &w[i]);
		printf("%d\n", solve(0, 0, 0));
	}
	return 0;
}