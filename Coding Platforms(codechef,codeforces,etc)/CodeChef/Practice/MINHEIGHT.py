#Read the number of test cases.
T = int(input())
for tc in range(T):
    # Read integers X and H.
    (x, h) = map(int, input().split(' '))
    if(x<h):
        print('NO')
    else:
        print('YES')