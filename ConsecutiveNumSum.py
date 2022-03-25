'''
    Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.
'''

int consecutiveNumbersSum(int n) {
    int k = 2;
    int count = 1;
    int sum = 1;
    while (true) {
        sum += k;
        if (n >= sum && (n-sum) % k == 0) {
            ++count;
        } else if (n < sum) {
            break;
        }
        ++k;
    }
    return count;
}
