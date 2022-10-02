#Read the number of test cases.
T = int(input())
for tc in range(T):
    # Read integers A and B.
    (a, b) = map(int, input().split(' '))
    if(a<b):
        print(a)
    else:
        print(b)