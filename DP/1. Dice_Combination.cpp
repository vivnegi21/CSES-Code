#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int MOD = 1e9 + 7;

int solve(int n, vector<int> &dp) {

    if (dp[n] != 0) return dp[n];

    for (int i = 1; i <= 6; i++) {
        if (n - i >= 0) {
            dp[n] += solve(n - i, dp);
            dp[n] %= MOD;
        }
    }
    return dp[n];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //write code
    int t;
    cin >> t;
    vector<int> dp(t + 1, 0);
    dp[0] = 1;
    cout << solve(t, dp) << endl;

    return 0;
}






/****************************Functions here*******************************/



/***********************************Properties***************************************/
/*  Modulus Operator
(a+ b) mod m = (a mod m+ b mod m) mod m
(a? b) mod m = (a mod m? b mod m) mod m
(a· b) mod m = (a mod m· b mod m) mod m

*/


