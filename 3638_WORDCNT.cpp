/* 
3638. Word Counting
 ad-hoc
 Sample Input
 2
 a aa bb cc def ghi
 a a a a a bb bb bb bb c c	
 
 Sample Output
 3
 5
 */
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
	string line, s;
	int t, best, len, prlen, wrdcnt;
	ios::sync_with_stdio(false);
	cin >> t;
	getline(cin, s);
	while(t--) {
		getline(cin, line);
		best = prlen = wrdcnt = 0;
		stringstream ss(line);
		while(ss >> s) 
        {
			len = s.size();
			if(len==prlen) 
                wrdcnt++;
			else 
            {
				if(wrdcnt > best) 
                    best = wrdcnt;
				wrdcnt = 1;
				prlen = len;
			}
		}
		if(wrdcnt > best) 
            best = wrdcnt;
		cout << best << endl;
	}
	return 0;
}