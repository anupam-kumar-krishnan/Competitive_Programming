public class trapping_rain_water {
    static int trapping(int arr[],int n)
    {
        int res=0;
        // int n=arr.length;
        int lmax[]=new int[n];// create new array
        int rmax[]=new int[n];//create new array
        lmax[0]=arr[0]; //initialize
        for (int i = 1; i < n; i++) {
            lmax[i]=Math.max(arr[i], lmax[i-1]);// puts elements in lmax
        }
        rmax[n-1]=arr[n-1];//initialise max[n-1]
        for (int j = n-2; j >=0; j--) {
            rmax[j]=Math.max(arr[j], rmax[j+1]);// puts elements in rmax
        }
        for (int j2 = 1; j2 < n-1; j2++) {
            res=res+(Math.min(lmax[j2],rmax[j2])-arr[j2]);//total amaount of water
        }
        return res;
    }
    public static void main(String[] args) {
        int arr[]={5,0,6,2,3};
        int n=arr.length;
        System.out.println(trapping(arr, n));
    }
}
