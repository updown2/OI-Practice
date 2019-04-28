#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, N)
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
const int MAXN = 500000;
//500,000,000 operations
int N;
ll W;
pair<pair<double, int>, pair<int, int> > inp[MAXN];
///        s/q    ind         s    q
multiset<int> vals;
multiset<int>::iterator it1;
set<pair<int, int> > vals2;
set<pair<int, int> >::iterator it2;

main() {
    //ifstream cin ("test.in");
    ios_base::sync_with_stdio; cin.tie(0);
    cin >> N >> W;
    ffi {
        cin >> inp[i].b.a >> inp[i].b.b;
        inp[i].a.b = i+1;
        inp[i].a.a = inp[i].b.a/ (double)inp[i].b.b;
    }
    sort(inp, inp+N);
    ll tot = 0;
    int scnt = 0, sind = -1;
    ll scost = 0;
    ffi {
        vals.insert(inp[i].b.b);
        tot += inp[i].b.b;
        while (inp[i].a.a*tot > W) {
            it1 = vals.end(); it1--;
            tot -= *it1;
            vals.erase(it1);
        }
        //w<< inp[i].a.a s tot<<e;
        if (vals.size() > scnt || (vals.size() == scnt && inp[i].a.a*tot < scost)) {
            scnt = vals.size();
            scost = inp[i].a.a*tot;
            sind = i;
        }
    }

    tot = 0;
    ffi {
        vals2.insert(mp(inp[i].b.b, inp[i].a.b));
        tot += inp[i].b.b;
        while (inp[i].a.a*tot > W) {
            it2 = vals2.end(); it2--;
            tot -= (*it2).a;
            vals2.erase(it2);
        }
        //w<< inp[i].a.a s tot<<e;
        if (sind == i) {
            vals.clear();
            for (auto j: vals2) vals.insert(j.b);
            break;
        }
    }
    w<< scnt<<e;
    for (int i: vals) w<< i<<e;
}
