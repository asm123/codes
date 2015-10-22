while True:
    try:
      n = input ()
      needle = raw_input ()
      haystack = raw_input ()
      i = haystack.find (needle)
      while i > 0:
	print i
	i = haystack.find (needle, i+1)
      print
    except:
      break