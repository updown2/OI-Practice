/*
calculate the maximum of gang 1 O(N)
for each next possible cow, calculate the max possible of gang 1 O(M*N^2*log(N))
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(ll i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, M)
#define ffa ffi ffj
#define s <<" "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 100, INF = 1000000000000000000;
//Global Variables
int N, M, cnt[MAXN], out, cc, ccnt;
priority_queue<pair<int, int> > next1;

int calc() {
    while (!next1.empty()) next1.pop();
    For (j, 1, M) if (cnt[j] != 0) next1.push(mp(cnt[j], j));
    int a = cc, b = ccnt;
    while (!next1.empty()) {
        int at = next1.top().b, have = next1.top().a; next1.pop();
        if (have != 1) next1.push(mp(have-1, at));
        if (at == a) b += 1;
        else {
            if (b < 1) {a = at; b = 1;}
            else b -= 1;
        }
        //w<< at s ":" s a s b<<e;
    }
    //w<< a s b<<e;
    if (a == 0) return b+ cnt[0];
    return cnt[0] - b;
}

main() {
    ifstream cin("gangs.in"); ofstream cout("gangs.out");
	//ifstream cin ("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	ffj cin >> cnt[j];
	int out = calc();
	if (out < 1) {w<< "NO"<<e; return 0;}
	w<< "YES"<<e<<out<<e;
	ffi {
	    //w<< i<<e;
        /// for each location
        ffj if (cnt[j] > 0) {
            cnt[j] --;
            int savea = cc, saveb = ccnt;
            if (cc == j) ccnt ++;
            else {
                if (ccnt >= 1) ccnt--;
                else {cc = j; ccnt = 1;}
            }
            //w<< calc()<<e;
            if (calc() == out) {
                w<< j+1<<e;
                break;
            }
            cc = savea, ccnt = saveb;
            cnt[j]++;
        }
	}
}
