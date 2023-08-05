#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

//memoization
int solve(int idx, int sm, vector<vector<int>> &dp, vector<int> coins) {
    //base condition
    if (idx == 0) {
        if (sm % coins[idx] == 0) return sm / coins[idx];
        else return 1e9;
    }
    if (dp[idx][sm] != INT_MAX) return dp[idx][sm];

    int take = INT_MAX;
    if (coins[idx] <= sm) {
        take = 1 + solve(idx, sm - coins[idx], dp, coins);
    }

    int notTake = solve(idx - 1, sm, dp, coins);
    return dp[idx][sm] = min(take, notTake);

}

int n, x;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //write code

    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, INT_MAX));

    //base condition
    for (int T = 0; T <= x; T++) {
        if (T % coins[0] == 0) dp[0][T] = T / coins[0];
        else dp[0][T] = 1e9;
    }

    for (int idx = 1; idx < n; idx++) {
        for (int sm = 0; sm <= x; sm++) {
            int take = INT_MAX;
            int notTake = dp[idx - 1][sm];
            if (coins[idx] <= sm) take = 1 + dp[idx][sm - coins[idx]];
            dp[idx][sm] = min(take, notTake);
        }
    }
    int ans = dp[n - 1][x];
    if (ans < 1e9) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}






/****************************Functions here*******************************/



/***********************************Properties***************************************/
/*  Modulus Operator
(a+ b) mod m = (a mod m+ b mod m) mod m
(a? b) mod m = (a mod m? b mod m) mod m
(a· b) mod m = (a mod m· b mod m) mod m

*/


