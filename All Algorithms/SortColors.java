
//Dutch National Flag Algorithm
public class SortColors {

    //sort the arrays , have value as 0,1,2
    static void sortcolor(int[] nums) {
        int low = 0;
        int high = nums.length - 1;
        int mid = 0;
        int ans = 0;

        while(mid<=high){
            switch(nums[mid]){
                case 0: {
                    ans = nums[low];
                    nums[low] =nums[mid];
                    nums[mid]=ans;
                    low++ ;  mid++;
                    break;
                }
                case 1: {
                    mid++;
                    break;
                }
                case 2: {
                    ans =  nums[mid];
                    nums[mid]=nums[high];
                    nums[high]=ans;
                    high--;
                    break;
                }
            }
        }
    }

    //for print the array
    static void printArray(int nums[])
    {
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println("");
    }


    public static void main(String[] args) {
        int[] nums = {2,0,2,1,1,0};
        sortcolor(nums);
        printArray(nums);
    }
}
