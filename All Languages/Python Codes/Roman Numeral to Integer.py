# PROBLEM STATEMENT:
# Roman numbers are represented by seven different symbols: I, V, X, L, C, D and M.
#      SYMBOL         VALUE
#        I              1
#        V              5
#        X             10
#        L             50
#        C            100
#        D            500
#        M           1000
# For example 2 is written as II in roman number system, just adding the two ones together. 12 is written as XII,
# which is simply X + II. The number 27 is written as XXVII, which is simply XX + V + II. However the numeral for 
# 4 is not IIII, rather it is IV, where 1 is subtracted from the 5. Similarly 9 is IX. There are six instances 
# where subtraction can be used. They are:
# I can be placed before V(5) and X(10) to make 4 and 9 respectively.
# X can be placed before L(50) and C(100) to make 40 and 90 respectively.
# C can be placed before D(500) and M(1000) to make 400 and 900 respectively.
# Given a roman numeral convert it to integer.
# Roman numerals for only numbers upto 3888 shall be given.
# 
# EXAMPLE:
# Input1:
# III
# 
# Output1:
# 3
# 
# Input2:
# LVIII
# 
# Output2:
# 58
# 
# Input3:
# MCMXCIV
# 
# Output3:
# 1994


roman = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
line = input()
ans = 0 
for i in range(len(line)-1, -1,-1):
    num = roman[line[i]]
    if (4*num < ans):
        ans = ans - num 
    else:
        ans = ans + num 
print(ans)