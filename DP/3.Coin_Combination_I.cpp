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
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                dp[i] += dp[i - coins[j]];
            }
          //note instead of MOD (%) operator, we're using this statement bcz it was giving TLE in few Test Cases.
          //using MOD can be costly
            if (dp[i] >= MOD) dp[i] -= MOD;
        }
    }
    cout << dp[x];
    return 0;
}






/****************************Functions here*******************************/



/***********************************Properties***************************************/
/*  Modulus Operator
(a+ b) mod m = (a mod m+ b mod m) mod m
(a? b) mod m = (a mod m? b mod m) mod m
(a· b) mod m = (a mod m· b mod m) mod m

*/


