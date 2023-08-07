#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
int MOD = 1e9 + 7;

int main() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //write code
    int w, h;
    cin >> w >> h;
    vector<vector<int>> dp(w + 1, vector<int>(h + 1));
    for (int i = 0; i <= w; i++) {
        for (int j = 0; j <= h; j++) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = 1e9;
                for (int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }
                for (int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
            }
        }
    }
    cout << dp[w][h] << endl;
    return 0;
}


/****************************Functions here*******************************/



/***********************************Properties***************************************/
/*  Modulus Operator
(a+ b) mod m = (a mod m+ b mod m) mod m
(a? b) mod m = (a mod m? b mod m) mod m
(a· b) mod m = (a mod m· b mod m) mod m

*/


