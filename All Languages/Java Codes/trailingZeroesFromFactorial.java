public class trailingZeroesFromFactorial {


static int CountZero(int x){
    int res=0;
    int i=5;
    while(i<=x){
        res=res+(x/i);
        i=i*i;
    }

    return res;
}

    public static void main(String[] args) {
        System.out.println(CountZero(251));
    }





}
