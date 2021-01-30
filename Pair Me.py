# cook your dish here
t=int(input())

for x in range (t):
    a,b,c=map(int,input().split())
    
    if(a+b==c or b+c==a or a+c==b):
        print("YES")
    else:
        print("NO")
    
