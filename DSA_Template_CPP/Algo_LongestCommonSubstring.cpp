#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

pair<int, string> longestCommonSubstring(const string& str1, const string& str2) {
    int len1 = str1.length();
    int len2 = str2.length();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    int maxLength = 0;
    int endIndex = 0;

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i;
                }
            }
        }
    }

    string longestSubstring = str1.substr(endIndex - maxLength, maxLength);
    return make_pair(maxLength, longestSubstring);
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
    
    pair<int, string> result = longestCommonSubstring(str1, str2);
    cout << "Longest Common Substring Length: " << result.first << endl;
    cout << "Longest Common Substring: " << result.second << endl;
    return 0;
}
