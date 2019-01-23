/*
https://ivaniscoding.wordpress.com/2018/08/25/communication-2-navigation/
*/
/// Anna.cpp
#include "Annalib.h"
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
vector<int> adj[MAXN];
bool vis[MAXN];
int vals[MAXN];

void go(int at) {
    if (vis[at]) return;
    vis[at] = true;
    for (int i: adj[at]) if (!vis[i]) {
        int x = vals[at];
        if (at < i) x++;
        vals[i] = (x%2);
        go(i);
    }
}

void Anna(int K, int N, int T, int A[], int B[]) {
  for (int i=0; i<N-1; i++) {A[i]--; B[i]--; adj[A[i]].push_back(B[i]); adj[B[i]].push_back(A[i]);}
  go (T-1);
  for (int i=0; i<N; i++) Flag(i+1, vals[i]);
}


/// Bruno.cpp
#include "Brunolib.h"
void Bruno(int K, int S, int F, int L, int P[], int Q[]) {
  for (int i=0; i<L; i++) if ( (F+Q[i] + (S < P[i] ? 1 : 0) ) % 2 == 1) {
    Answer(P[i]);
    return;
  }
  Answer(S);
}
