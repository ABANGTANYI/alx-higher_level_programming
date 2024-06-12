#!/usr/bin/python3
"""
Module 0-add_integer
contains one method and accepts two values of int or float type
casts them to int before adding
Returns an int sum
"""

def add_integer(a, b=98):
    """
    Adds two integers.

    Args:
        a (int or float): The first integer.
        b (int or float): The second integer. Defaults to 98.

    Returns:
        int: The addition of `a` and `b`.

    Raises:
        TypeError: If `a` is not an integer or float.
        TypeError: If `b` is not an integer or float.

    Examples:
        >>> add_integer(1, 2)
        3
        >>> add_integer(100, -2)
        98
        >>> add_integer(2)
        100
        >>> add_integer(100.3, -2)
        98
        >>> add_integer(4, "School")
        Traceback (most recent call last):
          ...
        TypeError: b must be an integer
        >>> add_integer(None)
        Traceback (most recent call last):
          ...
        TypeError: a must be an integer
    """

    if type(a) not in (int, float):
        raise TypeError("a must be an integer or float")
    elif type(b) not in (int, float):
        raise TypeError("b must be an integer or float")

    if type(a) is float:
        a = int(a)
    if type(b) is float:
        b = int(b)

    return a + b
