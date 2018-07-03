/*
Binary Search on number of rounds
Move element to location so it will arrive and the correct final location at the end
*/
#include "sorting.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, rounds)
#define ffa ffi ffj
#define s <<" "<<
//#define c <<" : "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int ll
const int MAXN=200000;
int start[MAXN], swi[MAXN][2], curpl[MAXN], curval[MAXN], fin[MAXN], locpl[MAXN], locval[MAXN];

bool works(int rounds, int N) {
    //w<< "trying" s rounds<<e;
    ffi fin[i] = curpl[i] = i, curval[i] = start[i];
    ffi locpl[curpl[i]] = i, locval[curval[i]] = i;
    ffj swap(fin[swi[j][0]], fin[swi[j][1]]);
    //ffi w<< fin[i] << " "; w<<e;
    int at = 0; /// next number to set to the correct location
    ffj {
        /// need to swap plates swi[j][0] and swi[j][1]
        int a = swi[j][0];
        int b = swi[j][1];
        swap (locpl[curpl[a]], locpl[curpl[b]]);
        swap (curpl[a], curpl[b]);
        //w<<j<<e; ffi w<< curpl[i]<<" "; w<<e;
        /// need to swap values swi[j][0] and swi[j][1]
        a = swi[j][0], b = swi[j][1];
        swap (locval[curval[a]], locval[curval[b]]);
        swap (curval[a], curval[b]);
        bool did = false;
        while (!did && at != N) {
            /// we want to end up in location "at" in final
            int pl = fin[at]; /// plate in the correct position
            int ind = locpl[pl]; /// index of the plate currently
            if (locval[at] == ind) {
                /// at is on the correct plate
                at++;
                continue;
            }
            /// need to swap values locval[at] and ind
            int a = locval[at];
            int b = ind;
            //w<< "for:" s at<<e; w<< a s b<<e;
            swap (locval[curval[a]], locval[curval[b]]);
            swap (curval[a], curval[b]);

            did = true, at++;
        }
    }
    bool did = false;
    while (!did && at != N) {
        /// we want to end up in location "at" in final
        int pl = fin[at]; /// plate in the correct position
        int ind = locpl[pl]; /// index of the plate currently
        if (locval[at] == ind) {
            /// at is on the correct plate
            at++;
            continue;
        }
        /// need to swap values locval[at] and ind but can't
        did = true;
    }
    //exit(0);
    //w<< at<<e;
    return at == N;
}

int findSwapPairs(int N, int S[], int M, int X[], int Y[], int P[], int Q[]) {
    ffi start[i] = S[i], swi[i][0] = X[i], swi[i][1] = Y[i];
    int a = 0, b = N;
    while (a != b) {
        int mid = (a+b)/2;
        if (works(mid, N)) b = mid;
        else a = mid+1;
    }
    /// Set P & Q
    int rounds = a;
    int x = 0;
    ffi fin[i] = curpl[i] = i, curval[i] = start[i];
    ffi locpl[curpl[i]] = i, locval[curval[i]] = i;
    ffj swap(fin[swi[j][0]], fin[swi[j][1]]);
    //ffi w<< fin[i] << " "; w<<e;
    int at = 0; /// next number to set to the correct location
    ffj {
        /// need to swap plates swi[j][0] and swi[j][1]
        int a = swi[j][0];
        int b = swi[j][1];
        swap (locpl[curpl[a]], locpl[curpl[b]]);
        swap (curpl[a], curpl[b]);
        //w<<j<<e; ffi w<< curpl[i]<<" "; w<<e;
        /// need to swap values swi[j][0] and swi[j][1]
        a = swi[j][0], b = swi[j][1];
        swap (locval[curval[a]], locval[curval[b]]);
        swap (curval[a], curval[b]);
        bool did = false;
        while (!did && at != N) {
            /// we want to end up in location "at" in final
            int pl = fin[at]; /// plate in the correct position
            int ind = locpl[pl]; /// index of the plate currently
            if (locval[at] == ind) {
                /// at is on the correct plate
                at++;
                continue;
            }
            /// need to swap values locval[at] and ind
            int a = locval[at];
            int b = ind;
            //w<< "for:" s at<<e; w<< a s b<<e;
            swap (locval[curval[a]], locval[curval[b]]);
            swap (curval[a], curval[b]);
            P[x] = a, Q[x] = b; x++;
            did = true, at++;
        }
    }
    while (x < rounds) {P[x] = 0; Q[x] = 0; x++;}


    return a;
}
