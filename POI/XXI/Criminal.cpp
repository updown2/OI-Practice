/*
Try every color as starting house
For every house, save the earliest location the robbers will end in if they start in that house
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
const int MAXN=1000001, INF=1000000000;
///500,000,000
int N, K, inp[MAXN], S1, S2, s1[MAXN], s2[MAXN], ind[MAXN], reach1[MAXN], reach2[MAXN], far[MAXN], dp[MAXN][2], ol= INF, oR = -1;
set<int> out;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    ffi {cin >> inp[i]; reach1[i] = reach2[i] = -1;}
    cin >> S1 >> S2;
    For (i, 0, S1) cin >> s1[i];
    For (i, 0, S2) cin >> s2[i];
    reverse(s1, s1+S1);
    reverse(s2, s2+S2);
    /// 1st robber
    For (i, 1, K+1) ind[i] = dp[i][1] = -1, dp[i][0] = N;
    For (i, 0, S1) ind[s1[i]] = i, far[i] = -1;
    for (int i=N-1; i>= 0; i--) {
        /// update far
        int loc = ind[inp[i]]; /// loc is the index in s1
        if (loc != -1) {
            if (loc == 0) far[0] = i;
            else far[loc] = far[loc-1];
            //w<< i s loc s far[loc]<<e;
        }
        /// update reach
        if (far[S1-1] != -1) reach1[i] = far[S1-1];
    }
    //ffi w<< reach1[i]<<e;
    /// 2nd robber
    For (i, 1, K+1) ind[i] = -1;
    For (i, 0, S2) ind[s2[i]] = i, far[i] = -1;
    ffi {
        /// update far
        int loc = ind[inp[i]]; /// loc is the index in s2
        if (loc != -1) {
            if (loc == 0) far[0] = i;
            else far[loc] = far[loc-1];
            //w<< i s loc s far[loc]<<e;
        }
        /// update reach
        if (far[S2-1] != -1) reach2[i] = far[S2-1];
    }
    //ffi w<< reach2[i]<<e;
    ffi {
        int j = inp[i]; /// color
        dp[j][0] = min(dp[j][0], i); dp[j][1] = i;
    }
    For (i, 1, K+1) { /// For every color
        if (dp[i][1] == -1) continue;
        int l = reach1[dp[i][0]+1], r = reach2[dp[i][1]-1]; /// skip the starting house
        //w<< "starting" s i c dp[i][0] s dp[i][1]<<e;
        if (l > r || l == -1 || r == -1) continue;
        //w<< i c l s r<<e;
        ol = min(ol, l); oR = max(oR, r);
        //w<< i c l s r<<e;
    }
    For (i, ol, oR+1) if (inp[i] == s1[0]) out.insert(i);
    w<< out.size() <<e;
    for (int i: out) w<<i+1<< " ";
    if (out.size() != 0) w<<e;
}
