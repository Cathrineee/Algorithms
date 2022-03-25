'''
    Given a signed 32-bit integer x, return x with its digits reversed. 
    If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

    Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
'''

def reverse(self, x: int) -> int:
    def transfer(n: int) -> List:
        n = -1 * n if n < 0 else n
        lst = []
        while n > 0:
            lst += [n % 10]
            n = n // 10
        return lst
    x_lst = transfer(x)
    # print(x_lst)
    x_l = len(x_lst)
    # print(x_l)
    sign = True if x >= 0 else False
    max_lst = transfer(2**31)
    max_lst.reverse()
    max_l = len(max_lst)
    ret = 0
    hold = True
    if len(x_lst) == 0 or x_l > max_l: return 0
    for i, n in enumerate(x_lst):
        if x_l < max_l:
            ret += n * (10 ** (x_l-i-1))
        elif sign:
            if i == x_l-1 and n < max_lst[i]-1:
                ret += n * (10 ** (x_l-i-1))
                hold = False
            elif i == x_l-1 and n == max_lst[i]-1:
                ret += n * (10 ** (x_l-i-1))
            elif not hold or n < max_lst[i]:
                ret += n * (10 ** (x_l-i-1))
                hold = False
            elif n == max_lst[i]:
                ret += n * (10 ** (x_l-i-1))
            else: return 0 
        else:
            if not hold or n < max_lst[i]:
                ret += n * (10 ** (x_l-i-1))
                hold = False
            elif n == max_lst[i]:
                ret += n * (10 ** (x_l-i-1))
            else: return 0 
    return ret if sign else -1 * ret
