class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n>0 and (n&(n-1))==0 and n&0b1010101010101010101010101010101==n:
            return True
        return False