/*
https://translate.google.com/translate?sl=auto&tl=en&u=https%3A%2F%2Fwww.ioi-jp.org%2Fcamp%2F2017%2F2017-sp-tasks%2F2017-sp-d1-port_facility-review.pdf
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, P)
#define ffa ffi ffj
#define s <<" "<<
#define c <<" : "<<
#define w cout
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
//500,000,000 operations
const int MAXN = 2000001, MOD = 1000000007;
//Global Variables
int N, inp[MAXN][2], out = 1, color[MAXN], indst[4*MAXN+1], indend[4*MAXN+1];
pair<int, int> onend[MAXN], onst[MAXN];
vector<pair<int, int> > treest[4*MAXN+1], treeend[4*MAXN+1];
bool del[MAXN];
queue<int> next1;

void build (int ind, int L, int R) {
    if (L == R) {
        if (onst[L].a  != MOD) treest[ind].pb(onst[L]);
        if (onend[L].a != MOD) treeend[ind].pb(onend[L]);
        indst[ind] = treest[ind].size()-1;
        indend[ind] = treeend[ind].size()-1;
        return;
    }
    build(ind*2, L, (L+R)/2); build(ind*2+1, (L+R)/2+1, R);
    int a = 0, b = 0;
    For (i, 0, treest[ind*2].size() + treest[ind*2+1].size()) {
        int x = MOD, y = MOD;
        if (treest[ind*2].size() != a) x = treest[ind*2][a].a;
        if (treest[ind*2+1].size() != b) y = treest[ind*2+1][b].a;
        if (x < y) {
            treest[ind].pb(treest[ind*2][a]);
            a++;
        }
        else {
            treest[ind].pb(treest[ind*2+1][b]);
            b++;
        }
    }
    a = 0, b = 0;
    For (i, 0, treeend[ind*2].size() + treeend[ind*2+1].size()) {
        int x = -1, y = -1;
        if (treeend[ind*2].size() != a) x = treeend[ind*2][a].a;
        if (treeend[ind*2+1].size() != b) y = treeend[ind*2+1][b].a;
        if (x > y) {
            treeend[ind].pb(treeend[ind*2][a]);
            a++;
        }
        else {
            treeend[ind].pb(treeend[ind*2+1][b]);
            b++;
        }
    }
    indst[ind] = treest[ind].size()-1; indend[ind] = treeend[ind].size()-1;
}
void queryst(int ind, int L, int R, int oL, int oR, int v, int x) {
    if (oR < L || R < oL) return;
    if (oL <= L && R <= oR) {
        while (indst[ind] != -1 && treest[ind][indst[ind]].a > v) {
            int i = treest[ind][indst[ind]].b;
            if (!del[i]) {
                del[i] = true;
                color[i] = x;
                //w<< "set" s i s x<<e;
                next1.push(i);
            }
            else if (color[i] != x) {
                //w<< "bad" s i c x s color[i]<<e;
                w<< 0<<e;
                exit(0);
            }
            indst[ind] --;
        }
        return;
    }
    queryst(ind*2, L, (L+R)/2, oL, oR, v, x); queryst(ind*2+1, (L+R)/2+1, R, oL, oR, v, x);
}
void queryend(int ind, int L, int R, int oL, int oR, int v, int x) {
    if (oR < L || R < oL) return;
    if (oL <= L && R <= oR) {
        while (indend[ind] != -1 && treeend[ind][indend[ind]].a < v) {
            int i = treeend[ind][indend[ind]].b;
            if (!del[i]) {
                del[i] = true;
                color[i] = x;
                //w<< "set" s i s x<<e;
                next1.push(i);
            }
            else if (color[i] != x) {
                //w<< "bad" s i c x s color[i]<<e;
                w<< 0<<e;
                exit(0);
            }
            indend[ind] --;
        }
        return;
    }
    queryend(ind*2, L, (L+R)/2, oL, oR, v, x); queryend(ind*2+1, (L+R)/2+1, R, oL, oR, v, x);
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    //For (i, 0, MAXN) tree[i] = mp(MOD, MOD);
    ffi {
        cin >> inp[i][0] >> inp[i][1];
        onst[inp[i][0]] = mp(inp[i][1], i);  /// tree[st] = end
        onst[inp[i][1]] = mp(MOD, -1);
        onend[inp[i][1]] = mp(inp[i][0], i); /// tree[end] = st
        onend[inp[i][0]] = mp(MOD, -1);
        color[i] = 2;
    }
    build(1, 1, 2*N);
    ffi if (!del[i]) {
        /// bfs
        //w<< "set" s i s 1<<e;
        color[i] = 1;
        out *= 2;
        out %= MOD;
        del[i] = true;
        next1.push(i);
        //w<< "going at" s i+1<<e;
        while (!next1.empty()) {
            int a = next1.front(); next1.pop();
            //w<< "at" s a+1<<e;
            /// guaranteed not deleted, but del[a] = false
            queryst(1, 1, 2*N, inp[a][0], inp[a][1], inp[a][1], 1-color[a]);
            queryend(1, 1, 2*N, inp[a][0], inp[a][1], inp[a][0], 1-color[a]);
        }
    }
    w<< out<<e;
}
