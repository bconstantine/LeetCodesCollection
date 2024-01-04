#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(); // Length of text1
    int n = text2.size(); // Length of text2
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // DP matrix

    // Building the DP matrix
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                // Characters match, increase the count
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                // Characters do not match, take the max from left or top cell
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n]; // Length of LCS is in the bottom-right cell
}
