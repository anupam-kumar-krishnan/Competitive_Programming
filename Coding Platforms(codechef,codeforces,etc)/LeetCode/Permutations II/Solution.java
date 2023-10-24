class Solution {
    public static List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        if (nums == null || nums.length == 0) return result;
        int n = nums.length;
        int[] visited = new int[n];
        Arrays.sort(nums);
        helper(nums, visited, new ArrayList<>(), result);
        return result;
    }

    public static void helper(int[] nums, int[] visited, List<Integer> curlist, List<List<Integer>> result) {
        if (curlist.size() == nums.length) {
            result.add(new ArrayList<>(curlist));
        }
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1] && visited[i-1]==0) continue;
            if (visited[i] == 0) {
                visited[i] = 1;
                curlist.add(nums[i]);
                helper(nums, visited, curlist, result);
                visited[i] = 0;
                curlist.remove(curlist.size() - 1);
            }
        }
    }
               }
