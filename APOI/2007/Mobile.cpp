/*
divide and conquer because mobiles cant be switched with arbitrary mobiles,
they have to be exchanged with a mobile on the same "side"
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
const int MAXN = 100000, INF = 1000000000000000000;
//Global Variables
int N, lef[MAXN], rig[MAXN], de[MAXN], da, db, cnt[MAXN][2], out;
set<int> dep;

void getdep(int at, int d) {
    de[at] = d;
    d++;
    //w<< at+1 s de[at]<<e;
    if (lef[at] == -2) dep.insert(d);
    else getdep(lef[at], d);
    if (rig[at] == -2) dep.insert(d);
    else getdep(rig[at], d);
}
void go(int at) {
    int d = de[at]+1;
    if (lef[at] == -2) {
        if (da == d) cnt[at][0]++;
        else cnt[at][1]++;
    }
    else {
        go(lef[at]);
        cnt[at][0] += cnt[lef[at]][0];
        cnt[at][1] += cnt[lef[at]][1];
    }
    if (rig[at] == -2) {
        if (da == d) cnt[at][0]++;
        else cnt[at][1]++;
    }
    else {
        go(rig[at]);
        cnt[at][0] += cnt[rig[at]][0];
        cnt[at][1] += cnt[rig[at]][1];
    }

    if (lef[at] == -2 && rig[at] == -2) return;
    //w<< at+1 s ":" s out<<e;
    if (lef[at] == -2) {
        if (d == da) {
            //w<< at+1 s ":" s out<<e;
            /// cnt[...][0], needs to go to the right
            /// check if a switch is needed
            if (cnt[rig[at]][1] > 0) out++;
            //w<< out<<e;
        }
        /// don't need to switch if item belongs at location
        return;
    }
    else if (rig[at] == -2) {
        if (d == db) {
            /// cnt[...][1] needs to move left
            if (cnt[lef[at]][0] > 0) out++;
        }
        return;
    }

    bool l1 = cnt[lef[at]][0]>0, h1 = cnt[lef[at]][1]>0, l2 = cnt[rig[at]][0]>0, h2 = cnt[rig[at]][1]>0;
    /// 9 cases
    if (h1 && l1) {
        /// high low - high low: no solution
        if (h2 && l2) {w<<-1<<e; exit(0);}
        /// high low - high: out++
        if (h2) out++;
        /// high low - low: done
    }
    else if (h1) {
        /// high - high low: done
        /// high - high: done
        /// high - low: done
    }
    else {
        /// low - high low: out++
        if (h2 && l2) out++;
        /// low - high: out++
        else if (h2) out++;
        /// low - low: done
    }
    //w<< out<<e;
}


main() {
	//ifstream cin ("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	ffi {cin >> lef[i] >> rig[i]; lef[i]--; rig[i]--;}
	getdep(0, 0);
	//w<< dep.size()<<e; for (int i: dep) w<< i<<e;
	if (dep.size() > 2) {w<< -1<<e; return 0;}
	if (dep.size() == 1) {w<< 0 <<e; return 0;}
	else {da = *(dep.begin()); dep.erase(dep.begin()); db = *(dep.begin());}
	if (db != da+1) {w<<-1<<e; return 0;}
	//w<< da s db<<e;
	go(0);
	//ffi w<<i+1 s ":" s cnt[i][0] s cnt[i][1]<<e;
	w<< out<<e;
}
