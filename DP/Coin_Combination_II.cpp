#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
int MOD = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //write code
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int &i : coins) cin >> i;
    vector<vector<int>> dp(n + 1, vector<int> (x + 1, 0));

    //base condition
    //when at 0th index, either wt is divisible then its 1 otherwise not possible
    for (int wt = 0; wt <= x; wt++) {
        dp[0][wt] = (wt % coins[0] == 0);
    }
    //using if statement instead of MOD operator to avoid TLE.
    for (int i = 1; i < n; i++) {
        for (int wt = 0; wt <= x; wt++) {
            dp[i][wt] = dp[i - 1][wt];
            if (dp[i][wt] >= MOD) dp[i][wt] -= MOD;
            if (coins[i] <= wt) {
                dp[i][wt] += dp[i][wt - coins[i]];
                if (dp[i][wt] >= MOD) dp[i][wt] -= MOD;
            }
        }
    }
    cout << dp[n - 1][x];
    return 0;
}






/****************************Functions here*******************************/



/***********************************Properties***************************************/
/*  Modulus Operator
(a+ b) mod m = (a mod m+ b mod m) mod m
(a? b) mod m = (a mod m? b mod m) mod m
(a· b) mod m = (a mod m· b mod m) mod m

*/


