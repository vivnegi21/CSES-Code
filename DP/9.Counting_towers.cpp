#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long long ll;
typedef vector<int> vi;
int MOD = 1e9 + 7;
void solve();

int main() {
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //write code
    int t;
    cin >> t;
    solve();
    while (t--) {
        int q;
        cin >> q;
        cout << (dp[q][0] + dp[q][1]) % MOD << endl;
    }
    return 0;
}

/****************************Functions here*******************************/
long long dp[1000009][2];
void solve() {
    int n = 1000005;
    // vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
    dp[1][0] = 1; dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = (4 * dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - 1][0] + 2 * dp[i - 1][1]) % MOD;

    }

}


/***********************************Properties***************************************/
/*  Modulus Operator
(a+ b) mod m = (a mod m+ b mod m) mod m
(a? b) mod m = (a mod m? b mod m) mod m
(a· b) mod m = (a mod m· b mod m) mod m

*/


