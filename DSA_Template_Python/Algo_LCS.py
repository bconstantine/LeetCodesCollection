def longestCommonSubsequence(text1, text2):
    m, n = len(text1), len(text2)  # Lengths of the two texts
    dp = [[0] * (n + 1) for _ in range(m + 1)]  # Initialize DP table with all zeros

    # Fill the DP table
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i - 1] == text2[j - 1]:
                # Characters match, increment the diagonal value
                dp[i][j] = 1 + dp[i - 1][j - 1]
            else:
                # Characters do not match, take the max of left and top values
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[m][n]  # LCS length is in the bottom-right cell
