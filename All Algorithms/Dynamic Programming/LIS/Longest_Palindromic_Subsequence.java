public class LongestPalindromicSubsequence {
    public static int findLPSLength(String str) {
        int n = str.length();
        
        // Create a 2D array to store the length of the LPS for subproblems.
        int[][] dp = new int[n][n];
        
        // All substrings of length 1 are palindromes.
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        // Loop through the string, starting from substrings of length 2.
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                // If the characters at both ends of the substring match, 
                // increment the LPS length by 2 and consider the LPS of the
                // remaining substring.
                if (str.charAt(i) == str.charAt(j)) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    // If the characters don't match, take the maximum of two cases:
                    // 1. Exclude the first character and consider the LPS of the rest.
                    // 2. Exclude the last character and consider the LPS of the rest.
                    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // The LPS of the entire string is stored in dp[0][n-1].
        return dp[0][n - 1];
    }

    public static void main(String[] args) {
        String str = "bbabcbcab";
        int lpsLength = findLPSLength(str);
        System.out.println("Length of Longest Palindromic Subsequence: " + lpsLength);
    }
}
