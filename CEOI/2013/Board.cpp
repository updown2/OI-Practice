/*
structure looks like:
  _
 / \
/   \
and answer can't be more than slightly more than 200,000 (I'm using current best answer). Calculate from top to bottom
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, at1)
#define ffj For(j, 0, at2)
#define ffa ffi ffj
#define s <<" "<<
#define w cout
#define e "\n"
#define pb push_back
#define mp make_pair
#define a first
#define b second
#define int ll
const int MAXN=100001, INF=1000000000000000000;
///500,000,000
string str1, str2;
int loc1[MAXN], loc2[MAXN], at1, at2, curr, out = INF, rig;

void fix1(int i) {
    if (loc1[i] > 1) {
        loc1[i-1] += loc1[i]/2;
        loc1[i] %= 2;
    }
    if (loc1[i] < 0) {
        loc1[i-1] += (loc1[i]-1)/2;
        loc1[i] = (loc1[i]+INF)%2;
    }
}
void fix2(int i) {
    if (loc2[i] > 1) {
        loc2[i-1] += loc2[i]/2;
        loc2[i] %= 2;
    }
    if (loc2[i] < 0) {
        loc2[i-1] += (loc2[i]-1)/2;
        loc2[i] = (loc2[i]+INF)%2;
    }
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> str1 >> str2;
    loc1[0] = loc2[0] = 1;
    for (char i: str1) {
        if (i == '1') {at1++; loc1[at1] = 0;}
        if (i == '2') {at1++; loc1[at1] = 1;}
        if (i == 'L') {loc1[at1]--;}
        if (i == 'R') {loc1[at1]++;}
        if (i == 'U') {fix1(at1); at1--;}
    }
    for (int i=at1; i>=1; i--) fix1(i);
    assert(loc1[0] == 1);
    at1++;
    //ffi w<< loc1[i]; w<<e;
    for (char i: str2) {
        if (i == '1') {at2++; loc2[at2] = 0;}
        if (i == '2') {at2++; loc2[at2] = 1;}
        if (i == 'L') {loc2[at2]--;}
        if (i == 'R') {loc2[at2]++;}
        if (i == 'U') {fix2(at2); at2--;}
    }
    for (int i=at2; i>=1; i--) fix2(i);
    assert(loc1[0] == 1);
    at2++;
    //ffj w<< loc2[j]; w<<e;
    For (i, 0, min(at1, at2)) {
        if (rig == 0 && loc1[i] != loc2[i]) {
            if (loc1[i] < loc2[i]) rig = 2;
            else rig = 1;
        }
        curr *= 2;
        if (rig == 1) curr += loc1[i] - loc2[i];
        if (rig == 2) curr += loc2[i] - loc1[i];
        out = min(out, curr + at1 - i - 1 + at2 - i - 1);
        if (curr > out) break;
    }
    w<< out<<e;
}
