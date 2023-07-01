import sys; input = sys.stdin.readline

l, h, w = map(int, input().split())
d = int(input())
volume = l*w*h
radius = d/2

from math import pi

volume2 = radius*radius*pi*h
print(volume-volume2)