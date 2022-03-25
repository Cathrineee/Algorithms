## Given a string s, return the longest palindromic substring in s.

def longestPalindrome(self, s: str) -> str:
    length = len(s)
    p = [[-1 for c in range(length)] for r in range(length)]
    def checkPalindrome(i: int, j: int):
        if s[i] == s[j]:
            if i+1 <= j-1:
                if p[i+1][j-1] == -1:
                    checkPalindrome(i+1, j-1)
                p[i][j] = p[i+1][j-1]
            else:
                p[i][j] = 1
        else:
            p[i][j] = 0
    for i in range(length):
        for j in range(length-1, i-1, -1):
            if p[i][j] < 0: 
                checkPalindrome(i, j)
            # print(i, j, p[i][j])
    # print("p finish")
    for l in range(length, 0, -1):
        for i in range(length):
            # print(l, i)
            if i+l-1 < length and p[i][i+l-1] == 1:
                return s[i:i+l]

