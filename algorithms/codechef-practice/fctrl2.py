
L = [1]

for i in range(1, 101):
  L += [i * L[i-1]]

t = input ()
for i in range(t):
  n = input ()
  print L[n]