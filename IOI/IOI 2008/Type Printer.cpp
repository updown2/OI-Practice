/*
Use a trie to store the words
Answer by traversing the trie
longest word last so it doesn't have to be deleted
need to optimize memory a little bit
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
//500,000,000 operations
const int MAXN = 25000, MAXM = 500001;//, INF = 1000000000000000000;
//Global Variables
int N, M = 1;
pair<short, string> inp[MAXN];
vector<char> out;

struct trie {
    int go[26];
    bool big[26];
    bool word;
    trie() {
        For (i, 0, 26) go[i] = -1, big[i] = false;
        word = false;
    }
};
vector<trie> tree; /// vector instead of array to optimize memory
void add(string a, int tnode, int aloc) {
    if (aloc == a.length()) {
        tree[tnode].word = true;
        return;
    }
    int nex = a[aloc]-'a';
    if (tree[tnode].go[nex] == -1) {
        tree[tnode].go[nex] = M;
        tree.pb(trie());
        M++;
    }
    add(a, tree[tnode].go[nex], aloc+1);
}

void addbig(string a, int tnode, int aloc) {
    if (aloc == a.length()) {
        tree[tnode].word = true;
        return;
    }
    int nex = a[aloc]-'a';
    if (tree[tnode].go[nex] == -1) {
        tree[tnode].go[nex] = M;
        tree.pb(trie());
        M++;
    }
    tree[tnode].big[nex] = true;
    addbig(a, tree[tnode].go[nex], aloc+1);
}
void traverse (int tnode) {
    trie at = tree[tnode];
    if (at.word) out.pb('P');
    For (i, 0, 26) if (at.go[i] != -1 && !at.big[i]) {
        out.pb((char)(i+'a'));
        traverse(at.go[i]);
        out.pb('-');
    }
    For (i, 0, 26) if (at.go[i] != -1 && at.big[i]) {
        out.pb((char)(i+'a'));
        traverse(at.go[i]);
        out.pb('-');
    }
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ffi {cin >> inp[i].b; inp[i].a = inp[i].b.length();}
    sort(inp, inp+N);
    tree.pb(trie());
    ffi {
        if (i == N-1) addbig(inp[i].b, 0, 0);
        else add(inp[i].b, 0, 0);
    }
    traverse(0);
    while (out.back() == '-') out.pop_back();
    w<< out.size()<<e;
    for (char i: out) w<< i<<e;
}
