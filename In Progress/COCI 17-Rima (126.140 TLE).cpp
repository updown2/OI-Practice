/*
The length decreases and then increases
for every node, count everything with the same suffix
dp[node] = (increasing sequence) max length sequence starting from this node ( but not counting count[node] or this node )
try every length as the smallest length
answer is max(big1[len]+big2[len]+count[word] where big1 an big2 have the same suffix,
             1 + big1 + big2 + count[word])
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
//#define int ll
const int MAXN=500000, INF=1000000000;
///500,000,000
int N, dp[MAXN], out;
string inp[MAXN], sm[MAXN];
bool vis[MAXN];
map<string, vector<int> > cnt; /// (suffix, vector<index> )

void go(int at) {
    if (vis[at]) return;
    vis[at] = true;
    int siz = cnt[inp[at]].size();
    for (int i: cnt[inp[at]]) {
        go(i);
        dp[at] = max(dp[at], dp[i]+siz);
    }
    //w<< inp[at] s (int)(cnt[inp[at]].size())<<e;
}

main() {
    ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	ffi {
	    cin >> inp[i];
	    sm[i] = inp[i].substr(1);
	    cnt[sm[i]].pb(i);
	}
	ffi go(i);
	//ffi w<< inp[i] c dp[i]<<e;
	ffi vis[i] = false;
	ffi if (!vis[i]) {
        string use = sm[i];
        int big1 = 0, big2 = 0;
        int siz = cnt[use].size();
        for (int j: cnt[use]) {
            big2 = max(big2, dp[j]);
            if (big2 > big1) swap(big2, big1);
            vis[j] = true;
        }
        out = max(out, big1+big2+siz);
        big1 = big2 = 0;
        for (int j: cnt[inp[i]]) {
            big2 = max(big2, dp[j]);
            if (big2 > big1) swap(big2, big1);
        }
        //w<< big1 s big2 s (int)cnt[inp[i]].size()<<e;
        out = max(out, 1+big1+big2+(int)cnt[inp[i]].size());
	}
	w<< out<<e;
}
