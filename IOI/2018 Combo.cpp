#include "combo.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i, a, b) for(int i=a; i<b; i++)
#define ffi For(i, 0, N)
#define ffj For(j, 0, K)
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

std::string guess_sequence(int N) {
    string ret = "";
    /// two guesses for first character
    if (press("AB") > 0) {
        if (press("A") > 0) ret += 'A';
        else ret += 'B';
    }
    else {
        if (press("X") > 0) ret += 'X';
        else ret += 'Y';
    }
    char a = ret[0];
    /// 1 guess for each middle character
    For (i, 1, N-1) {
        if (a == 'A') {
            int x = press(ret + 'B' + ret + "XX" + ret + "XY" + ret + "XB");
            if (x == i) ret += 'Y';
            else if (x == i+1) ret += 'B';
            else ret += 'X';
        }
        if (a == 'B') {
            int x = press(ret + 'A' + ret + "XX" + ret + "XY" + ret + "XA");
            if (x == i) ret += 'Y';
            else if (x == i+1) ret += 'A';
            else ret += 'X';
        }
        if (a == 'X') {
            int x = press(ret + 'B' + ret + "AA" + ret + "AY" + ret + "AB");
            if (x == i) ret += 'Y';
            else if (x == i+1) ret += 'B';
            else ret += 'A';
        }
        if (a == 'Y') {
            int x = press(ret + 'B' + ret + "XX" + ret + "XA" + ret + "XB");
            if (x == i) ret += 'A';
            else if (x == i+1) ret += 'B';
            else ret += 'X';
        }
    }
    /// 2 for the last
    if (N != 1) {
        if (press(ret + 'A' + ret + 'B') == N) {
            if (press(ret+'A') == N) ret += 'A';
            else ret += 'B';
        }
        else {
            if (press(ret+'X') == N) ret += 'X';
            else ret += 'Y';
        }
    }
    return ret;
}
