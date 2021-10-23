s=input()
fre={}
count=0
c=0
for i in s:
    if i in fre:
        fre[i]+=1
    else:
        fre[i]=1
#print(fre)
x=fre.values()
for i in x:
    if i==1:
        count+=1
    else:
        c+=1
f=(count+c)
if(f%2==0):
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")

    
