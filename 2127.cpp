//
//  2127.cpp
//  
//
//  Created by Haijun Deng on 13-1-10.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*s[i] = (78901 + 31*s[i-1]) mod  699037
t[i] = (23456 + 64*t[i-1]) mod 2097151
The output of the i-th step is the number

a[i]=(s[i] mod 100 + 1) * (t[i] mod 100 + 1)
 Input file:
 1
 123456 123456 10 10000
 
 Output file:
 2
*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <valarray>
#include <complex>
using namespace std;

const int dr[]={0,-1,0,1,-1,1, 1,-1};
const int dc[]={1,0,-1,0, 1,1,-1,-1};
const double eps=1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<double, double> pdd;
typedef vector<pdd> vpdd;
typedef complex<double> pnt;
typedef vector<pnt> vpnt;
typedef vector<vector<pair<int, long long> > > Graph;

#define fr(i,a,b) for(int i(a),_b(b);i<=_b;++i)
#define frd(i,a,b) for(int i(a),_b(b);i>=_b;--i)
#define rep(i,n) for(int i(0),_n(n);i<_n;++i)
#define repd(i,n) for(int i((n)-1);i>=0;--i)
#define reps(i,a) fr(i,0,sz(a)-1)
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define fore(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define maximum(a) (*max_element(all(a)))
#define minimum(a) (*min_element(all(a)))
#define clr(x,a) memset(x,a,sizeof(x))
#define findx(a,x) (find(all(a),x)-a.begin())
#define two(X) (1LL<<(X))
#define contain(S,X) (((S)&two(X))!=0)

template<class T> void print(T const &x) {ostringstream os; os<<x; cout<<os.str()<<endl;}
template<class T> void print(vector<T> const &v) {ostringstream os; for(int i=0; i<v.size(); ++i){if(i)os<<' ';os<<v[i];} cout<<os.str()<<endl;}
template<class T> void print(vector<vector<T> > const &v){ostringstream os; for(int i=0;i<v.size();++i) {for(int j=0;j<v[i].size();++j){if(j)os<<' ';os<<v[i][j];}os<<endl;}cout<<os.str()<<endl;}
template<class T> void print(valarray<T> const &v) {ostringstream os; for(int i=0; i<v.size(); ++i){if(i)os<<' ';os<<v[i];} cout<<os.str()<<endl;}
template<class T> int sz(const T&c){return (int)c.size();}
template<class T> void srt(T&c){std::sort(c.begin(),c.end());}
template<class T> void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> T sqr(T x){return x*x;}
template<class T, class U> T cast (U x) { ostringstream os; os<<x; T res; istringstream is(os.str()); is>>res; return res; }
template<class T> vector<T> split(string s, string x=" ") {vector<T> res; for(int i=0;i<s.size();i++){string a; while(i<(int)s.size()&&x.find(s[i])==string::npos)a+=s[i++]; if(!a.empty())res.push_back(cast<T>(a));} return res;}
template<class T> T inside(T r,T c,T R, T C){return r>=0 && r<R && c>=0 && c<C;}

int s[2000000],t[2000000],a[2000000];

int main( int argc, char* argv[] ) {
	ios::sync_with_stdio(false);
	//freopen("input.txt","r",stdin);

	int testCases;
	scanf("%d", &testCases);
	for(int testCase=1;testCase<=testCases;testCase++){
		int n,m;
		scanf("%d%d", &s[0],&t[0]);
		scanf("%d%d", &n,&m);
		int res=n,L=1,R=0;
		ll sum=0;
		fr(i,1,n){
			s[i] = (78901 + 31LL*s[i-1]) % 699037;
			t[i] = (23456 + 64LL*t[i-1]) % 2097151;
			a[i] = (s[i] % 100 + 1) * (t[i] % 100 + 1);			
			sum+=a[i];
			while(sum>m){
				sum-=a[L];
				L++;
				checkmin(res,i-L+1);
			}			
		}
		checkmin(res,n-L+1);
		printf("%d\n", res);
	}

	return 0;
}

