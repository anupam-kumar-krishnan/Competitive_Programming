def armstrong():
    sum=0
    num=int(input('enter number : '))
    temp = num
    while temp > 0:
       digit = temp % 10
       sum += digit ** 3
       temp //= 10
    if (num==sum):
        print(num,'is a Armstrong number')
    else:
        print(num,'is not a Armstrong number')
        
armstrong()
