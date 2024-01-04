def longestCommonSubstring(str1, str2):
    len1, len2 = len(str1), len(str2)
    dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]
    maxLength, endIndex = 0, 0

    for i in range(1, len1 + 1):
        for j in range(1, len2 + 1):
            if str1[i - 1] == str2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
                if dp[i][j] > maxLength:
                    maxLength = dp[i][j]
                    endIndex = i

    longestSubstring = str1[endIndex - maxLength:endIndex]
    return maxLength, longestSubstring

# Main execution
str1 = input("Enter first string: ")
str2 = input("Enter second string: ")
length, substring = longestCommonSubstring(str1, str2)
print("Longest Common Substring Length:", length)
print("Longest Common Substring:", substring)
