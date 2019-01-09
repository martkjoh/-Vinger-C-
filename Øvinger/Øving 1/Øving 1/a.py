def isFibonacciNumber(n):
    a = 0
    b = 1
    while b < n:
        temp = b
        b += a
        a = temp
    return b == n
print(isFibonacciNumber(8git))