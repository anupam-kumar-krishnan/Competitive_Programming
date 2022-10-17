#include <stdio.h>
#include <math.h>

int main(void) {
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
	    int n,a;
	    scanf("%d",&n);
	    for(int j=0; ;j++){
	        int k=pow(2,j);
	        if(k<=n){
	            continue;
	        }
	        else if(k>n){
	            a=j-1;
	            break;
	        }
	    }
	    int u=0,k,l;
	    for(int j=0; ;j++){
	    	if((a-j)>0){
	        k=pow(2,(a-j));
			}
			else if((a-j)==0){
				k=1;
			}
	        if((n-k)>=0){
	            n=n-k;
	            u++;
	        }
	        else if(n<=0){
	            break;
	        }
	    }
	    printf("%d\n",u-1);
	}
	return 0;
}