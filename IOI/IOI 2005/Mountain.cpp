/*
use an implicit segment. for each node, store the total difference in height between the
start and the end and store the maximum height anywhere in the segment
We can use int instead of long long because of input constraints
*/
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
#define e endl//"\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
const int MAXN=200000;
///500,000,000
int N;
struct node {
    int l=-1, r=-1, lazy = 0, m=0, t=0;
    bool on = false;
};
vector<node> tree;

void expand(int x, int L, int R) {
    if (L == R || tree[x].l != -1) return;
    node use;
    tree[x].l = tree.size(); tree.pb(use);
    tree[x].r = tree.size(); tree.pb(use);
}
void push(int x, int L, int R) {
    if (!tree[x].on) return;
    tree[x].m = tree[x].t = tree[x].lazy*(R-L+1);
    //w<< x s L s R c tree[x].lazy c tree[x].m s tree[x].t<<e;
    if (L != R) {
        expand(x, L, R);
        tree[tree[x].l].lazy = tree[tree[x].r].lazy = tree[x].lazy;
        tree[tree[x].l].on = tree[tree[x].r].on = true;
    }
    tree[x].on = false;
}
int query(int x, int L, int R, int v) {
    //w<< x s L s R<<e;
    push(x, L, R);
    if (L == R) return L - 1;
    expand(x, L, R);
    push(tree[x].l, L, (L+R)/2);

    if (tree[tree[x].l].m > v) return query(tree[x].l, L, (L+R)/2, v);
    return query(tree[x].r, (L+R)/2+1, R, v-tree[tree[x].l].t);
}
void update(int x, int L, int R, int oL, int oR, int d) {
    push(x, L, R);
    if (oL <= L && R <= oR) {
        tree[x].lazy = d;
        tree[x].on = true;
        push(x, L, R);
        return;
    }
    if (R < oL || oR < L) return;
    expand(x, L, R);
    update(tree[x].l, L, (L+R)/2, oL, oR, d); update(tree[x].r, (L+R)/2+1, R, oL, oR, d);
    tree[x].t = tree[tree[x].l].t + tree[tree[x].r].t;
    tree[x].m = max(tree[tree[x].l].m, tree[tree[x].l].t+tree[tree[x].r].m);
    //w<< x s L s R c tree[x].m s tree[x].t<<e;
}

main() {
    //ifstream cin("test.in");
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	node use;
	tree.pb(use);
	char a; cin >> a;
	while (a != 'E') {
        //w<< "new query"<<e;
        int x, y, z;
        cin >> x;
        if (a == 'I') {
            cin >> y >> z;
            update(0, 1, N+1, x, y, z);
        }
        else w<< query(0, 1, N+1, x)<<e;
        cin >> a;
	}
}
