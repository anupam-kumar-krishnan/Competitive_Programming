s = input()
count = 0
flag = 0

for i in range(len(s)-1):
    if s[i] == s[i+1]:
        count += 1
        # print(count)
        if count >= 6:
            flag = 1
    else:
        count = 0
        # print(count)

# print(f'flag: {flag}')

if flag == 1:
    print("YES")
elif flag == 0:
    print("NO")
