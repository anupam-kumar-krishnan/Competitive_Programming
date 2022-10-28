class Solution 
{
    public String largestNumber(int[] nums) 
    {
        int n = nums.length;
        String[] arr = new String[n];
        for(int i=0; i<n; i++)
            arr[i] = String.valueOf(nums[i]);
        Arrays.sort(arr, new Comparator<String>()
        {
            @Override
            public int compare(String s1, String s2)
            {
                String f = s1 + s2;
                String s = s2 + s1;
                int n = f.length();
                for(int i=0; i<n; i++)
                    if(f.charAt(i) != s.charAt(i))
                        return s.charAt(i) - f.charAt(i);
                return 0;
            }
        });
        StringBuilder sb = new StringBuilder();
        for(String s: arr)
            sb.append(s);
        if(sb.charAt(0) == '0')
            return "0";
        return sb.toString();
    }
}
