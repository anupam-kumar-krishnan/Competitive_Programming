def automorphic():
    n = int(input('Enter number: '))
    square = n * n
    while n:
        square_remainder = square%10
        n_remainder = n%10
        if square_remainder != n_remainder:
            return False
        n //= 10
        square //= 10
    return True

def is_automorphic():
    if automorphic():
        print(' AUTOMORPHIC' )
    else:
        print('NOT AUTOMORPHIC')

