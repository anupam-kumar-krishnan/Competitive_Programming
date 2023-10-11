class Solution {
    public int minOperations(int[] A) {
        int n = A.length;
        int ans = n;
        HashSet<Integer> hashSet = new HashSet<>();
        for (int x : A) {
            hashSet.add(x);
        }
        int[] unique = new int[hashSet.size()];
        int i = 0;
        
        for (int x : hashSet) {
            unique[i++] = x;
        }
            
        Arrays.sort(unique);
        
        int j = 0;
        int m = unique.length;
        for (i = 0; i < m; i++) {
            while (j < m && unique[j] < unique[i] + n) {
                j++;
            }
            ans = Math.min(ans, n - j + i);
        }
        
        return ans;
    }
}
