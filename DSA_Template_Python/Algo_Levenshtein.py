def levenshteinDistance(str1, str2):
    m, n = len(str1), len(str2)  # Lengths of the two strings
    dp = [[0] * (n + 1) for _ in range(m + 1)]  # Initialize DP table

    # Set up the first column and row
    for i in range(m + 1):
        dp[i][0] = i
    for j in range(n + 1):
        dp[0][j] = j

    # Iterate over each character in the strings
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if str1[i - 1] == str2[j - 1]:
                # Characters match, no operation needed
                dp[i][j] = dp[i - 1][j - 1]
            else:
                # Characters do not match, consider all operations
                dp[i][j] = 1 + min(dp[i - 1][j],    # Deletion
                                   dp[i][j - 1],    # Insertion
                                   dp[i - 1][j - 1])# Substitution

    return dp[m][n]  # The Levenshtein distance is in the bottom-right cell
