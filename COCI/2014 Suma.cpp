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
#define int ll
//500,000,000 operations
const int MAXN = 700, INF = 1000000000;
//Global Variables
int gcd(int a, int b) {return a==0 ? b:gcd(b%a, a);}
struct Frac {
    int num, dem;
    Frac (int a, int b) {num = a; dem = b; simplify();}
    void simplify() {
        if (num == 0) {dem = 1; return;}
        if (num < 0) {num *= -1; dem *= -1;}
        int x = gcd(num, dem);
        num /= x;
        dem /= x;
    }
    bool eq(Frac b) {
        return num == b.num && dem == b.dem;
    }
};
int N, H[MAXN][MAXN], V[MAXN][MAXN], siz[MAXN][MAXN], out = 1, rsiz[MAXN][MAXN];
pair<int, int> par[MAXN][MAXN], rpar[MAXN][MAXN];
bool perm[MAXN][MAXN];
vector<pair<Frac, pair<pair<int, int>, pair<int, int> > > > edges;
bool comp(pair<Frac, pair<pair<int, int>, pair<int, int> > > a, pair<Frac, pair<pair<int, int>, pair<int, int> > > b) {
    if (a.a.num == b.a.num) return a.a.dem < b.a.dem;
    return a.a.num < b.a.num;
}
set<pair<int, int> > nodes;
pair<int, int> root (int r1, int c1) {
    if (par[r1][c1].a == r1 && par[r1][c1].b == c1) return par[r1][c1];
    return root(par[r1][c1].a, par[r1][c1].b);
}
void join(int r1, int c1, int r2, int c2) {
    pair<int, int> a = root(r1, c1), b = root(r2, c2);
    r1 = a.a, c1 = a.b, r2 = b.a, c2 = b.b;
    nodes.insert(a); nodes.insert(b);
    if (a.a == b.a && a.b == b.b) return;
    if (siz[r1][c1] > siz[r2][c2]) {
        par[r2][c2] = a;
        siz[r1][c1] += siz[r2][c2];
    }
    else {
        par[r1][c1] = b;
        siz[r2][c2] += siz[r1][c1];
    }
}
int ext, big;

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; ffa cin >> H[i][j]; ffa cin >> V[i][j];
    /// edges to the right
    ffa {par[i][j] = mp(i, j); siz[i][j] = 1;}
    ffi For (j, 0, N-1) {
        int num = H[i][j] - H[i][j+1];
        int dem = V[i][j+1] - V[i][j];
        //w<< "right" s i s j s num s dem<<e;
        if (dem == 0 && num == 0) {join(i, j, i, j+1); ext += 2;}
        if (num*dem >= 0 && dem != 0) edges.emplace_back(Frac(num, dem), mp(mp(i, j), mp(i, j+1)));
    }
    /// edges below
    For (i, 0, N-1) ffj {
        int num = H[i][j] - H[i+1][j];
        int dem = V[i+1][j] - V[i][j];
        if (dem == 0 && num == 0) {join(i, j, i+1, j); ext += 2;}
        if (num*dem >= 0 && dem != 0) edges.emplace_back(Frac(num, dem), mp(mp(i, j), mp(i+1, j)));
    }
    ffa {
        rsiz[i][j] = siz[i][j];
        out = max(out, rsiz[i][j]);
        rpar[i][j] = par[i][j];
    }
    sort(edges.begin(), edges.end(), comp);
    int i = 0;
    while (i < edges.size()) {
        int j = i;
        while (j+1 < edges.size() && edges[i].a.eq(edges[j+1].a)) j++;
        //w<< "Looking at" s edges[i].a.num s edges[i].a.dem<<e;
        /// range is i to j
        //w<< "Range" c i s j<<e;
        For (k, i, j+1) {
            //w<< edges[k].a.num s edges[j].a.dem c edges[k].b.a.a s edges[k].b.a.b s edges[k].b.b.a s edges[k].b.b.b<<e;
            nodes.insert(edges[k].b.a); nodes.insert(edges[k].b.b);
            join(edges[k].b.a.a, edges[k].b.a.b, edges[k].b.b.a, edges[k].b.b.b);
        }
        for (auto k: nodes) {
            //w<< k.a s k.b<<e;
            pair<int, int> top = root(k.a, k.b);
            out = max(out, siz[top.a][top.b]);
            //if (siz[top.a][top.b] == out) w<< out c top.a s top.b s rsiz[top.a][top.b]<<e;
        }
        for (auto k: nodes) {
            par[k.a][k.b] = rpar[k.a][k.b];
            siz[k.a][k.b] = rsiz[k.a][k.b];
        }
        //w<< ext s ext + nodes.size()<<e;
        nodes.clear();
        //w<< edges[i].a.num s edges[i].a.dem c out<<e;
        i = j+1;
    }
    w<< out<<e;
}
