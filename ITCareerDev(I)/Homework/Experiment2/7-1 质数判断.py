import math

def isPrime(n):
    if n < 2 : return False
    if n == 2 :return True
    for i in range(2,math.sqrt(n)+1):
        if n%i == 0: return False
    return True

num=int(input())
if isPrime(num):
    print('yes')
else:
    print('no')