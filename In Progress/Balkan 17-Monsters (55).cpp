/*
http://codeforces.com/blog/entry/53122?#comment-372211: "There is a relatively simple O(N^3) algorithm that I'm not sure if it's supposed to get 100 points on the competition, but it did. Our goal is to calculate number of rectangles of 1s containing that field for every field. If we fix lower-right corner of the rectangle, and its width, we can get height of that rectangle in O(1). When we have some rectangle of that type, we will have to update first row of that rectangle with +1, second row with +2, and etc..(Can be shown using some easy maths) Updates of this type can be handled with several cumulative sums over rows/columns, we have O(N^3) such updates, and O(N^2) for calculating sums and calculating the matrix, so the algorithm has O(N^3) complexity. Finally, our solution is number of rectangles before deletion — maximum value of the calculated matrix."
using blocks or rows instead of columns
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
#define int ll
const int MAXN=751, INF=1000000000000000000;
///500,000,000
int N, M, nex[MAXN][MAXN], tot, across[MAXN][MAXN], save[MAXN][MAXN];
pair<int, int> down[MAXN][MAXN];
char grid[MAXN][MAXN];

main() {
    ifstream cin("test.in");
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    ffa cin >> grid[i][j];
    ffi {
        nex[i][M] = M;
        for (int j=M-1; j>=0; j--) {
            if (grid[i][j] == '0') nex[i][j] = j;
            else nex[i][j] = nex[i][j+1];
        }
    }
    ffa if (grid[i][j] == '1') {
        int far = M;
        For (k, i, N) {
            far = min(far, nex[k][j]);
            int x = far-j;
            if (x == 0) continue;
            tot += x;
            down[i][j].a += x;
            down[i][j].b ++;
            down[k+1][j].a -= x;
            down[k+1][j].b --;
            across[i][j+x] --;
            across[k+1][j+x] ++;
        }
        //w<< i+1 s j+1 s ":" s tot<<e;
    }
    //ffi {ffj w<< down[i][j].a <<"," << down[i][j].b << " "; w<<e;}
    //ffi {ffj w<< across[i][j] << " "; w<<e;}
    ffj For (i, 1, N) {
        down[i][j].a += down[i-1][j].a;
        down[i][j].b += down[i-1][j].b;
        across[i][j] += across[i-1][j];
    }
    //ffi {ffj w<< down[i][j].a <<"," << down[i][j].b << " "; w<<e;}
    //ffi {ffj w<< across[i][j] << " "; w<<e;}
    int best = 0;
    ffi {
        int val = 0, cnt = 0;
        ffj {
            val += down[i][j].a;
            save[i][j] = val;
            best = max(best, save[i][j]);
            cnt += down[i][j].b + across[i][j];
            val -= cnt;
        }
    }
    //ffi {ffj w<< save[i][j] << " "; w<<e;}
    w<< tot - best<<e;
}
