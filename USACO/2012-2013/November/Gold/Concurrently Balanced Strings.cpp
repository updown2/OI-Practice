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
const int MAXN=50000, INF=1000000000000000000;
///500,000,000
int N, M, pre[10][MAXN], out;
char inp[10][MAXN];
set<pair<int, int> > vals[10]; /// (prefix, j)
set<pair<int, int> >::iterator it;
vector<int> store[MAXN];
map<vector<int>, int> cnt;

main() {
    //ifstream cin("test.in");
	ifstream cin("cbs.in"); ofstream cout("cbs.out");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	ffa {
	    cin >> inp[i][j];
	    if (inp[i][j] == '(') pre[i][j] = 1;
	    else pre[i][j] = -1;
	    if (j != 0) pre[i][j] += pre[i][j-1];
	}
	ffj {
        ffi {
            if (inp[i][j] == '(') store[j].pb(pre[i][j]-1);
            else store[j].pb(pre[i][j]);
        }
        cnt[store[j]] = 0;
        //w<< j << ":"; ffi w s pre[i][j]; w<<e;
	}
	ffj {
        bool open = true, close = true;
        ffi {
            if (inp[i][j] == '(') close = false;
            else open = false;
        }
        if (open) {
            cnt[store[j]]++;
            ffi vals[i].insert(mp(pre[i][j], j));
        }
        /// update vals & cnt
        ffi if (inp[i][j] == ')') {
            if (!vals[i].empty()) {it = vals[i].end(); it--;}
            while (!vals[i].empty() && (*it).a > 1+ pre[i][j]) {
                //w<< "i =" s i s "j =" s j c "del" s (*it).b s (*it).a s pre[i][j]<<e;
                /// delete starting point
                int ind = (*it).b;
                For (k, 0, N) vals[k].erase(mp(pre[k][ind], ind));
                cnt[store[ind]] --;

                if (!vals[i].empty()) {it = vals[i].end(); it--;}
            }
        }
        if (close) {
            out += cnt[store[j]];
        }
	}
	w<< out<<e;
}
