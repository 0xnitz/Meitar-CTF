import random
import timeout_decorator
import sys

import socket
import signal

from _thread import *
import threading 

@timeout_decorator.timeout(0.25)
def rabinMiller(num):
    # Returns True if num is a prime number.

    s = num - 1
    t = 0
    while s % 2 == 0:
        # keep halving s while it is even (and use t
        # to count how many times we halve s)
        s = s // 2
        t += 1

    for trials in range(5): # try to falsify num's primality 5 times
        a = random.randrange(2, num - 1)
        v = pow(a, s, num)
        if v != 1: # this test does not apply if v is 1.
            i = 0
            while v != (num - 1):
                if i == t - 1:
                    return False
                else:
                    i = i + 1
                    v = (v ** 2) % num
    return True

def isPrime(num):
    try:
        return rabinMiller(num)
    except:
        return False

def isPrime2(num):
    for x in range(2, num):
        if num % x == 0:
            return False

    return True

g = lambda : int(input('> '))

if True:
    try:
        num = g()

        while True:
            if isPrime(num):
                print('Yes')
            else:
                print('No')

            num = g()
    except KeyboardInterrupt:
        pass
else:
    try:
        gen = lambda : int(''.join([random.choice('0123456789') for x in range(50)]))
        f = open('primes', 'a+')

        while True:
            x = gen()
            while (isPrime(x)):
                x = gen()

            print(x)
            f.write(str(x) + "\n")
    except KeyboardInterrupt:
        pass
    finally:
        f.close()

