def flyod():
    size = int(input("Enter the range:  "))
    print("\nFLOYD'S TRIANGLE with numbers: \n")
    k = 1
    # 2 for loops, one for column looping another for row looping
    # i loop for column looping and j loop for row looping
    for i in range(1, size + 1):
        for j in range(1, i + 1):
            print(k, end=" ")
            k += 1
        print()
    print("\n")
    print("\nFLOYD'S TRIANGLE with *'s: \n")
    for i in range(1, size + 1):
        for j in range(1, i + 1):
            print('*', end=" ")
        print()
    print("\n")
flyod()
