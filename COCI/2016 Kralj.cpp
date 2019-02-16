/*
https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2017/contest1_solutions/solutions.pdf
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
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 500000;
//Global Variables
int N, A[MAXN], P[MAXN], have[MAXN], st, out;
vector<int> vals[MAXN];
multiset<int> opt;
multiset<int>::iterator it;

main() {
	//ifstream cin ("test.in");
	ios_base::sync_with_stdio; cin.tie(0);
	cin >> N; ffi cin >> A[i]; ffi cin >> P[i];
	ffi {int a; cin >> a; vals[A[i]-1].pb(a);}
	int curr = 0;
	ffi {
        curr += vals[i].size(); have[i] = curr;
        curr = max(curr-1, (ll)0);
        //w<< i c have[i]<<e;
	}
	ffi if (have[i] == 0) st = (i+1)%N;
	//w<< st+1<<e;
	for (int i=st, j=0; i != st || j == 0; i=(i+1)%N, j = 1) {
        //w<< "i:" s i<<e;
        for (int k: vals[i]) opt.insert(k);
        assert(!opt.empty());
        it = opt.lower_bound(P[i]);
        if (it == opt.end()) it = opt.begin();
        else out++;
        //w<< (*it)<<e;
        opt.erase(it);
	}
	w<< out<<e;
}
