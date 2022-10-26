public class Subtract_the_Product_and_Sum_of_Digits_of_an_Integer {
    public int subtractProductAndSum(int n) {
        int sum=0; int mul=1;
        while(n!=0){
            int rem=n%10;
            sum=sum+rem;
            mul=mul*rem;
            n=n/10;
        }
            return mul-sum; 
        }
}
