public class LongestCommonSubstring {
    public static String findLongestCommonSubstring(String str1, String str2) {
        int m = str1.length();
        int n = str2.length();
        
        // Create a 2D table to store the lengths of common substrings
        int[][] dp = new int[m + 1][n + 1];
        
        // To store the length of the longest common substring found so far
        int maxLength = 0;
        
        // To store the ending position of the longest common substring found so far
        int endIndex = 0;
        
        // Fill the dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] > maxLength) {
                        maxLength = dp[i][j];
                        endIndex = i;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        // Extract the longest common substring using endIndex and maxLength
        String longestCommonSubstring = str1.substring(endIndex - maxLength, endIndex);
        return longestCommonSubstring;
    }
    
    public static void main(String[] args) {
        String str1 = "ABABC";
        String str2 = "BABC";
        
        String lcs = findLongestCommonSubstring(str1, str2);
        System.out.println("Longest Common Substring: " + lcs); // Output: "BABC"
    }
}
