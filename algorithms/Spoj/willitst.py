n = input ()
flag = 0
while n > 1:
  if n % 2 == 0:
    n /= 2
  else:
      print "NIE"
      flag = 1
      break
if flag == 0:
  print "TAK"
