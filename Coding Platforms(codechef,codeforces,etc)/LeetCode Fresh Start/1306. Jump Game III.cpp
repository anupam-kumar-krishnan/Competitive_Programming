class Solution {
public:
    bool canReach(vector<int> arr, int start) {
		return start >= 0 && start < arr.size() && arr[start] >= 0 &&
		(!(arr[start] = -arr[start]) || canReach(arr, start - arr[start]) || canReach(arr, start + arr[start]));
    }
};
