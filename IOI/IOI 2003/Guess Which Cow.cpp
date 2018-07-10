/*
BFS. State: Possible traits for each property
Transitions: Different queries
Min-max tree
Unraveled loops to speed up
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
#define e endl
#define pb push_back
#define mp make_pair
#define a first
#define b second
//#define int unsigned long long
//500,000,000 operations
const int MAXN = 50;//, INF = 1000000000000000000;
//Global Variables
int N, P;
int p2[25], prop[MAXN];
char under[1<<24], height[1<<24]; /// max height is 24 (2 queries for each property)

void go(int x) {
    //For (i, 0, 3*P) w<< ((x&p2[i]) > 0);// w c (int)height[x]<<e;
    char ret = 100; /// min of the max heights
        if (__builtin_popcount(prop[0] & x) == P) under[x]++;
        if (__builtin_popcount(prop[1] & x) == P) under[x]++;
        if (__builtin_popcount(prop[2] & x) == P) under[x]++;
        if (__builtin_popcount(prop[3] & x) == P) under[x]++;
        if (__builtin_popcount(prop[4] & x) == P) under[x]++;
        if (__builtin_popcount(prop[5] & x) == P) under[x]++;
        if (__builtin_popcount(prop[6] & x) == P) under[x]++;
        if (__builtin_popcount(prop[7] & x) == P) under[x]++;
        if (__builtin_popcount(prop[8] & x) == P) under[x]++;
        if (__builtin_popcount(prop[9] & x) == P) under[x]++;
        if (__builtin_popcount(prop[10] & x) == P) under[x]++;
        if (__builtin_popcount(prop[11] & x) == P) under[x]++;
        if (__builtin_popcount(prop[12] & x) == P) under[x]++;
        if (__builtin_popcount(prop[13] & x) == P) under[x]++;
        if (__builtin_popcount(prop[14] & x) == P) under[x]++;
        if (__builtin_popcount(prop[15] & x) == P) under[x]++;
        if (__builtin_popcount(prop[16] & x) == P) under[x]++;
        if (__builtin_popcount(prop[17] & x) == P) under[x]++;
        if (__builtin_popcount(prop[18] & x) == P) under[x]++;
        if (__builtin_popcount(prop[19] & x) == P) under[x]++;
        if (__builtin_popcount(prop[20] & x) == P) under[x]++;
        if (__builtin_popcount(prop[21] & x) == P) under[x]++;
        if (__builtin_popcount(prop[22] & x) == P) under[x]++;
        if (__builtin_popcount(prop[23] & x) == P) under[x]++;
        if (__builtin_popcount(prop[24] & x) == P) under[x]++;
        if (__builtin_popcount(prop[25] & x) == P) under[x]++;
        if (__builtin_popcount(prop[26] & x) == P) under[x]++;
        if (__builtin_popcount(prop[27] & x) == P) under[x]++;
        if (__builtin_popcount(prop[28] & x) == P) under[x]++;
        if (__builtin_popcount(prop[29] & x) == P) under[x]++;
        if (__builtin_popcount(prop[30] & x) == P) under[x]++;
        if (__builtin_popcount(prop[31] & x) == P) under[x]++;
        if (__builtin_popcount(prop[32] & x) == P) under[x]++;
        if (__builtin_popcount(prop[33] & x) == P) under[x]++;
        if (__builtin_popcount(prop[34] & x) == P) under[x]++;
        if (__builtin_popcount(prop[35] & x) == P) under[x]++;
        if (__builtin_popcount(prop[36] & x) == P) under[x]++;
        if (__builtin_popcount(prop[37] & x) == P) under[x]++;
        if (__builtin_popcount(prop[38] & x) == P) under[x]++;
        if (__builtin_popcount(prop[39] & x) == P) under[x]++;
        if (__builtin_popcount(prop[40] & x) == P) under[x]++;
        if (__builtin_popcount(prop[41] & x) == P) under[x]++;
        if (__builtin_popcount(prop[42] & x) == P) under[x]++;
        if (__builtin_popcount(prop[43] & x) == P) under[x]++;
        if (__builtin_popcount(prop[44] & x) == P) under[x]++;
        if (__builtin_popcount(prop[45] & x) == P) under[x]++;
        if (__builtin_popcount(prop[46] & x) == P) under[x]++;
        if (__builtin_popcount(prop[47] & x) == P) under[x]++;
        if (__builtin_popcount(prop[48] & x) == P) under[x]++;
        if (__builtin_popcount(prop[49] & x) == P) under[x]++;
    //w c (int)under[x]<<e;
    if (under[x] == 1) {height[x] = 0; return;} /// bc 0 queries to determine the answer
    if (under[x] == 0) {height[x] = -100; return;} /// so that this height is ignored

    //ffj {
        /// j = 0
        /// see which nums are 1
        bool o[3];
        o[0] = o[1] = o[2] = false;
        if (x & p2[0]) o[0] = true;
        if (x & p2[1]) o[1] = true;
        if (x & p2[2]) o[2] = true;

        ///k = 0
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[0] && (o[1] || o[2])) {
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[1]) c1 -= p2[1];
            if (o[2]) c1 -= p2[2];
            /// c2 is no
            c2 -= p2[0];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }
        /// k = 1
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[1] && (o[0] || o[2])){
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[2]) c1 -= p2[2];
            if (o[0]) c1 -= p2[0];
            /// c2 is no
            c2 -= p2[1];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }
        /// k = 2
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[2] && (o[0] || o[1])) {
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[0]) c1 -= p2[0];
            if (o[1]) c1 -= p2[1];
            /// c2 is no
            c2 -= p2[2];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }

        /// j = 1
        /// see which nums are 1
        o[0] = o[1] = o[2] = false;
        if (x & p2[3]) o[0] = true;
        if (x & p2[4]) o[1] = true;
        if (x & p2[5]) o[2] = true;

        ///k = 0
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[0] && (o[1] || o[2])) {
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[1]) c1 -= p2[4];
            if (o[2]) c1 -= p2[5];
            /// c2 is no
            c2 -= p2[3];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }
        /// k = 1
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[1] && (o[0] || o[2])){
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[2]) c1 -= p2[5];
            if (o[0]) c1 -= p2[3];
            /// c2 is no
            c2 -= p2[4];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }
        /// k = 2
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[2] && (o[0] || o[1])) {
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[0]) c1 -= p2[3];
            if (o[1]) c1 -= p2[4];
            /// c2 is no
            c2 -= p2[5];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }

        /// j = 2
        /// see which nums are 1
        o[0] = o[1] = o[2] = false;
        if (x & p2[6]) o[0] = true;
        if (x & p2[7]) o[1] = true;
        if (x & p2[8]) o[2] = true;

        ///k = 0
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[0] && (o[1] || o[2])) {
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[1]) c1 -= p2[7];
            if (o[2]) c1 -= p2[8];
            /// c2 is no
            c2 -= p2[6];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }
        /// k = 1
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[1] && (o[0] || o[2])){
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[2]) c1 -= p2[8];
            if (o[0]) c1 -= p2[6];
            /// c2 is no
            c2 -= p2[7];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }
        /// k = 2
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[2] && (o[0] || o[1])) {
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[0]) c1 -= p2[6];
            if (o[1]) c1 -= p2[7];
            /// c2 is no
            c2 -= p2[8];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }

        /// j = 3
        /// see which nums are 1
        o[0] = o[1] = o[2] = false;
        if (x & p2[9]) o[0] = true;
        if (x & p2[10]) o[1] = true;
        if (x & p2[11]) o[2] = true;

        ///k = 0
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[0] && (o[1] || o[2])) {
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[1]) c1 -= p2[10];
            if (o[2]) c1 -= p2[11];
            /// c2 is no
            c2 -= p2[9];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }
        /// k = 1
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[1] && (o[0] || o[2])){
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[2]) c1 -= p2[11];
            if (o[0]) c1 -= p2[9];
            /// c2 is no
            c2 -= p2[10];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }
        /// k = 2
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[2] && (o[0] || o[1])) {
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[0]) c1 -= p2[9];
            if (o[1]) c1 -= p2[10];
            /// c2 is no
            c2 -= p2[11];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }

        /// j = 4
        /// see which nums are 1
        o[0] = o[1] = o[2] = false;
        if (x & p2[12]) o[0] = true;
        if (x & p2[13]) o[1] = true;
        if (x & p2[14]) o[2] = true;

        ///k = 0
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[0] && (o[1] || o[2])) {
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[1]) c1 -= p2[13];
            if (o[2]) c1 -= p2[14];
            /// c2 is no
            c2 -= p2[12];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }
        /// k = 1
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[1] && (o[0] || o[2])){
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[2]) c1 -= p2[14];
            if (o[0]) c1 -= p2[12];
            /// c2 is no
            c2 -= p2[13];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }
        /// k = 2
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[2] && (o[0] || o[1])) {
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[0]) c1 -= p2[12];
            if (o[1]) c1 -= p2[13];
            /// c2 is no
            c2 -= p2[14];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }

        /// j = 5
        /// see which nums are 1
        o[0] = o[1] = o[2] = false;
        if (x & p2[15]) o[0] = true;
        if (x & p2[16]) o[1] = true;
        if (x & p2[17]) o[2] = true;

        ///k = 0
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[0] && (o[1] || o[2])) {
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[1]) c1 -= p2[16];
            if (o[2]) c1 -= p2[17];
            /// c2 is no
            c2 -= p2[15];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }
        /// k = 1
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[1] && (o[0] || o[2])){
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[2]) c1 -= p2[17];
            if (o[0]) c1 -= p2[15];
            /// c2 is no
            c2 -= p2[16];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }
        /// k = 2
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[2] && (o[0] || o[1])) {
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[0]) c1 -= p2[15];
            if (o[1]) c1 -= p2[16];
            /// c2 is no
            c2 -= p2[17];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }

        /// j = 6
        /// see which nums are 1
        o[0] = o[1] = o[2] = false;
        if (x & p2[18]) o[0] = true;
        if (x & p2[19]) o[1] = true;
        if (x & p2[20]) o[2] = true;

        ///k = 0
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[0] && (o[1] || o[2])) {
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[1]) c1 -= p2[19];
            if (o[2]) c1 -= p2[20];
            /// c2 is no
            c2 -= p2[18];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }
        /// k = 1
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[1] && (o[0] || o[2])){
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[2]) c1 -= p2[20];
            if (o[0]) c1 -= p2[18];
            /// c2 is no
            c2 -= p2[19];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }
        /// k = 2
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[2] && (o[0] || o[1])) {
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[0]) c1 -= p2[18];
            if (o[1]) c1 -= p2[19];
            /// c2 is no
            c2 -= p2[20];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }

        /// j = 7
        /// see which nums are 1
        o[0] = o[1] = o[2] = false;
        if (x & p2[21]) o[0] = true;
        if (x & p2[22]) o[1] = true;
        if (x & p2[23]) o[2] = true;

        ///k = 0
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[0] && (o[1] || o[2])) {
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[1]) c1 -= p2[22];
            if (o[2]) c1 -= p2[23];
            /// c2 is no
            c2 -= p2[21];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }
        /// k = 1
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[1] && (o[0] || o[2])){
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[2]) c1 -= p2[23];
            if (o[0]) c1 -= p2[21];
            /// c2 is no
            c2 -= p2[22];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }
        /// k = 2
        /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
        if (o[2] && (o[0] || o[1])) {
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[0]) c1 -= p2[21];
            if (o[1]) c1 -= p2[22];
            /// c2 is no
            c2 -= p2[23];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[c1] == 100) go(c1);
            if (height[c1] < ret && height[c2] == 100) go(c2);
            ret = min(ret, max(height[c1], height[c2]));
        }
    //}
    height[x] = ret+1;
    //assert(ret+1 < 100);
    //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w c (int)(height[x])<<e;
}

void solve(int x) {
    //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<e;
    if (height[x] == 0) {
        /// found the answer
        //w<< "answer ";For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<e;
        ffi {
            if (__builtin_popcount(prop[i] & x) == P) {
                w<< 'C' s (i+1)<<e;
                exit(0);
            }
        }
        //assert(false);
    }
    ffj {
        /// see which nums are 1
        bool o[3];
        o[0] = o[1] = o[2] = false;
        if (x & p2[j*3]) o[0] = true;
        if (x & p2[j*3+1]) o[1] = true;
        if (x & p2[j*3+2]) o[2] = true;
        For (k, 0, 3) {
            /// see if this query is an option (not a 0 and not the only 1 in the group of 3)
            if (!o[k]) continue;
            if (!o[(k+1)%3] && !o[(k+2)%3]) continue;
            /// Try the query, take the max of the two heights and add 1
            int c1 = x, c2 = x;
            /// c1 is yes
            if (o[(k+1)%3]) c1 -= p2[j*3+(k+1)%3];
            if (o[(k+2)%3]) c1 -= p2[j*3+(k+2)%3];
            /// c2 is no
            c2 -= p2[j*3+k];
            //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w<<" to "; For (i, 0, 3*P) w<< ((c1&(1<<i)) > 0); w<< " and "; For (i, 0, 3*P) w<< ((c2&(1<<i)) > 0); w<<e;
            if (height[x] == 1+ max(height[c1], height[c2])) {
                /// Make this query
                w<< 'Q' s (j+1) s (char)(k+'X')<<endl;
                int a; cin >> a;
                if (a == 0) solve(c2);
                else solve(c1);
                /// should never reach here bc the solve should exit the program
                //assert(false);
            }
        }
    }
    //For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w c (int)(height[x])<<e;
}

main() {
    //ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    p2[0] = 1;
    For (i, 1, 25) p2[i] = 2*p2[i-1];
    cin >> N >> P;
    ffa {char a; cin >> a; int b = a-'X'; prop[i] |= p2[3*j+b];}
    //For (x, 0, p2[3*P]) height[x] = 100;
    memset(height, 100, p2[3*P]*sizeof(char));
    go(p2[3*P] - 1);
    //For (x, 0, 1<<(3*P)) if (under[x] != 0) {For (i, 0, 3*P) w<< ((x&(1<<i)) > 0); w c (int)(under[x])<<e;}
    //w<< (int) height[p2[3*P] - 1]<<e;
    solve(p2[3*P]-1);
}
