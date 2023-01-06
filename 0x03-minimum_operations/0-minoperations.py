#!/usr/bin/python3
"""
Minimum Operations
"""


def minOperations(n):
    """ Finds minimum operations required by prime factors method """
    if (n <= 1) or (type(n) is not int):
        return 0
    fact = []
    while (n > 1):
        for i in range(2, n + 1):
            if n % i == 0:
                fact.append(i)
                n = int(n / i)
                break
    return sum(fact)
