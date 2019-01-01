/*
https://github.com/nikolapesic2802/Programming-Practice/blob/master/Schools/main.cpp
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
const int MAXN=300000, INF=1000000000000;
///500,000,000
int N, M, S, inp[MAXN][2], out;
bool del[MAXN];
set<pair<int, int> > a, b; /// (-a[i], i)
multiset<int> ba; /// (a[i] - b[i]) (-b[i])
set<pair<int, int> >::iterator it1, it3;
multiset<int>::iterator it2;

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> S;
	a.insert(mp(INF, INF)); ba.insert(INF); b.insert(mp(INF, INF));
	ffi {cin >> inp[i][0] >> inp[i][1]; a.insert(mp(-inp[i][0], i));}
	ffj {
	    it1 = a.begin();
	    int ind = (*it1).b;
	    out -= (*it1).a;
	    a.erase(it1);
	    del[ind] = true;
	    ba.insert(inp[ind][0] - inp[ind][1]);
	    //w<< "took a" s out<<e;
	}
	ffi if (!del[i]) b.insert(mp(-inp[i][1], i));
	For (i, 0, S) {
	    it1 = a.begin(), it2 = ba.begin(), it3 = b.begin();
	    if ((*it1).a + (*it2) < (*it3).a) {
            out -= (*it1).a + (*it2);
            ba.erase(it2);
            int ind = (*it1).b;
            a.erase(it1);
            ba.insert(inp[ind][0] - inp[ind][1]);
            b.erase(mp(-inp[ind][1], ind));
            //w<< "moved a to b" s out<<e;
	    }
	    else {
            out -= (*it3).a;
            int ind = (*it3).b;
            a.erase(mp(-inp[ind][0], ind));
            b.erase(it3);
            //w<< "took b" s out<<e;
	    }
	}
	w<< out<<e;
}
