import sys

def power (a, b):
  p = 1
  for i in range (b):
    p *= a
  return p
  

t = input ()
for i in range (t):
  a, b = map(int, sys.stdin.readline().split())
  if a == 0:
    print 0
  elif b == 0:
    print 1
  else:
    if b % 4 == 0:
      print (power (a % 10, 4) % 10)
    else:
      print (power (a % 10, b % 4) % 10)