/*
max_diff is the distance between nodes 1 and N
first check if there are nodes coming out of nodes 1 and N (not between). All of those nodes can be attached directly to 1 or N we they all have the same abs(a[i]-b[i])
fail1 checks if this is possible
if not, all the nodes are between nodes 1 and N
in both cases, all the nodes between 1 and N are either directly on the path or can be connected directly to a node on the path
for nodes on the path, a[i]+b[i] = max_diff
for all others, a[i]-b[i] = a[j]-b[j] for a node j that's directly the path
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 2, N)
#define ffj For(j, 0, N)
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
const int MAXN=500001;
///500,000,000
int N, a[MAXN], b[MAXN], max_diff;
set<int> pos;
bool fail1, fail2;

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N; ffi cin >> a[i]; ffi cin >> b[i];
	ffi max_diff = max(max_diff, abs(a[i]-b[i]));
	ffi if (abs(a[i]-b[i]) != max_diff && a[i] + b[i] == max_diff) {
	    if (pos.find(a[i]-b[i]) != pos.end()) fail1 = true;
	    pos.insert(a[i]-b[i]);
	}
	if (max_diff == 0) fail1 = true;
	ffi if (abs(a[i]-b[i]) != max_diff && pos.find(a[i]-b[i]) == pos.end()) fail1 = true;
	if (fail1) {
        /// everything is between 1 and N
        max_diff = 10000000;
        pos.clear();
        ffi max_diff = min(max_diff, a[i]+b[i]);
        ffi if (a[i] + b[i] == max_diff) {
            if (pos.find(a[i]-b[i]) != pos.end()) fail2 = true;
            pos.insert(a[i]-b[i]);
        }
        ffi if (pos.find(a[i]-b[i]) == pos.end()) fail2 = true;
	}
	if (fail2) {w<< "NIE"<<e; return 0;}
	w<< "TAK"<<e;
	ffi {
        if (a[i]-b[i] == max_diff) w<< i s N s b[i]<<e;
        else if (b[i] - a[i] == max_diff) w<< i s 1 s a[i]<<e;
	}
    b[1] = a[N] = max_diff;
    vector<pair<int, int> > ord;
    map<int, int> dir;
    For (i, 1, N+1) if (a[i] + b[i] == max_diff) {
        ord.emplace_back(a[i], i);
        dir[a[i]-b[i]] = i;
    }
    sort(ord.begin(), ord.end());
    For (i, 1, ord.size()) w<< ord[i-1].b s ord[i].b s ord[i].a - ord[i-1].a<<e;
    ffi if (a[i] + b[i] != max_diff && abs(a[i] - b[i]) != max_diff) {
        int to = dir[a[i]-b[i]];
        w<< i s to s a[i] - a[to]<<e;
    }
}
