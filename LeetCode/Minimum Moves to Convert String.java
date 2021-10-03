class Solution {
    public int minimumMoves(String str) {
        char [] ar = str.toCharArray();
        int count = 0;
        int n = str.length();
        
        for(int i = 0; i < n-2; ) {
            if(ar[i] == 'X') {
                ar[i] = 'O';
                ar[i+1] = 'O';
                ar[i+2] = 'O';
                i=i+3;
                count++;
            }
            else{
                i++;
            }
        }

        for(int i=n-2; i<n; i++){
            if(ar[i] == 'X'){
                count++;
                break;
            }
        }
        return count;
    }
}
