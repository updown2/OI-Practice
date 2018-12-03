#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, Q)
#define ffa ffi ffj
#define s <<" "<<
//#define c <<" : "<<
#define w cout
#define e endl // "/n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
//500,000,000 operations
const int MAXN = 101, INF = 100000000000000;
//Global Variables
int T, sh, N, ep, mh, ma, cval[MAXN], bval[MAXN], caval[MAXN];
vector<pair<int, int> > ch, bl, ac;

/// c[a]val[min energy] = max attack
/// bval[min energy] = max boost

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    For (t, 1, T+1) {
        w<< "Fight #" <<t<<":";
        cin >> sh >> N >> ep >> mh >> ma;
        ac.clear(); bl.clear(); ch.clear();
        ffi {
            int a, b, c; cin >> a >> b >> c;
            if (a == 1) ac.pb(mp(b, c));
            else if (a == 2) bl.pb(mp(b, c));
            else {ch.pb(mp(b, c)); ac.pb(mp(b, c));}
        }
        For (i, 0, MAXN) cval[i] = bval[i] = caval[i] = 0;
        for (auto j: ch) for (int i=MAXN-1; i>=0; i--) if (i+j.b < MAXN) {
            cval[i+j.b] = max(cval[i+j.b], cval[i] + j.a);
        }
        if (cval[ep] >= mh) {
            /// charge and win
            w s "Win"<<e;
            continue;
        }
        for (auto j: bl) for (int i=MAXN-1; i>=0; i--) if (i+j.b < MAXN) {
            bval[i+j.b] = max(bval[i+j.b], bval[i] + j.a);
        }
        if (bval[ep] + sh <= ma) {
            /// lose
            w s "Lose"<<e;
            continue;
        }
        For (i, 0, ep+1) if (bval[i]+sh > ma) {
            ep -= i;
            break;
        }
        for (auto j: ac) for (int i=MAXN-1; i>=0; i--) if (i+j.b < MAXN) {
                caval[i+j.b] = max(caval[i+j.b], caval[i] + j.a);
        }
        //For (i, 0, MAXN) w<< i s caval[i]<<e;
        if (caval[ep] >= mh) w s "Win"<<e;
        else w s "Lose"<<e;
    }
}
