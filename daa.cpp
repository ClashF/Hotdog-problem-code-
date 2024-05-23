#include <iostream>
#include<climits>
#include <vector>
using namespace std;
int main() {
    int n,b;  // Number of bricks
    cout<<"number of bricks:";
    cin >> n;
    cout<<"size of boxes:";
    cin>>b;
    // dp[i] represents the minimum number of boxes needed for i bricks
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;  // No boxes needed for no bricks

    // Build up the solution using dynamic programming
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= b; j++) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + 1);  // Try packing j bricks into a box
            }
        }
    }
    cout << dp[n] << endl;  // Print the minimum number of boxes needed

    return 0;
}

