def is_equivalent(s):
    if len(s) % 2: return s
 
    a = is_equivalent(s[:len(s)//2])
    b = is_equivalent(s[len(s)//2:])
    
    return a + b if a < b else b + a
 
 
a = str(input())
b = str(input())
print('YES' if is_equivalent(a) == is_equivalent(b) else 'NO')