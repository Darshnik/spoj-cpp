/*
1436. Is it a tree
ALGO: breadth first search
Input:
3 2
1 2
2 3

Output:
YES
*/

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX 10001

int N, E;
vector< int > G[MAX];
bool flag[MAX];
int pre[MAX];

bool bfs(int s)
{
	int i, u, v, sz;
	queue< int > Q;
	Q.push(s);
	flag[s] = 1;
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		sz = G[u].size();
		for(i=0; i<sz; i++)
		{
			v = G[u][i];
			if(pre[u] != v && flag[v]) 
                return false;
			else if(!flag[v])
			{
				pre[v] = u;
				flag[v] = 1;
				Q.push(v);
			}
		}
	}
	for(i=1; i<=N; i++)
		if(!flag[i])
			return false;
	return true;
}

int main()
{
	int i, u, v, s;
	scanf("%d %d", &N, &E);
	for(i=0; i<E; i++)
	{
		scanf("%d %d", &u, &v);
		s = u;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(E!=N-1) 
        printf("NO\n");
	else
	{
		if(bfs(s)) 
            printf("YES\n");
		else 
            printf("NO\n");
	}
	return 0;
}