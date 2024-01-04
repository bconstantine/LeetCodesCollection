#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int levenshteinDistance(string str1, string str2) {
    int m = str1.size(); // Length of str1
    int n = str2.size(); // Length of str2
    vector<vector<int>> dp(m + 1, vector<int>(n + 1)); // DP matrix

    // Initialize first column and first row of DP table
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    // Compute the distances
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                // Characters match, cost is 0
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Characters do not match, calculate cost
                dp[i][j] = 1 + min({dp[i - 1][j],      // Deletion
                                    dp[i][j - 1],      // Insertion
                                    dp[i - 1][j - 1]});// Substitution
            }
        }
    }
    return dp[m][n]; // The Levenshtein distance is in the bottom-right cell
}
