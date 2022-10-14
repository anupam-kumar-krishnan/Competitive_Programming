public class Solution {
    public int rob(int[] num) {
        if (num.length == 0)
            return 0;
        else if (num.length == 1)
            return num[0];
        else
            return Math.max(robRange(num, 0, num.length - 2), robRange(num, 1, num.length -1));
    }
    private int robRange(int[] num, int start, int end){
        int with = num[start];
        int without = 0;
        for (int i = start + 1; i <= end; i ++){
            int newWith = without + num[i];
            int newWithout = Math.max(with, without);
            with = newWith;
            without = newWithout;
        }
        return Math.max(with, without);
    }
}
