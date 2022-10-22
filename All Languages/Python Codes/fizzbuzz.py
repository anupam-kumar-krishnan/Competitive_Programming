n = int(input("Enter a number"))
for i in range(n+1):
    if i%3 == 0 :
        if i%5 == 0 :
            print("FizzBuzz")
        else:
            print("Fizz")
    elif i%5==0 :
        print("Buzz")
    else:
        print(i)