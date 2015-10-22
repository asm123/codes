def negabinary(i):
    digits = ''
    if not i:
        digits = '0'
    else:
        while i != 0:
	    print i
            i, remainder = divmod(i, -2)
            if remainder < 0:
                i, remainder = i + 1, remainder + 2
            digits = str(remainder)+ digits
    print digits
  
n = input()
negabinary(n)