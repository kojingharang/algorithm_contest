try:
	while True:
		s = input().split(" ")
		if len(s)==3:
			a, b, c = map(int, s)
			cab = c-a-b
			ans = "No"
			if 0<cab:
				if a*b*4<cab**2:
					ans = "Yes"
			print(ans)
#			print(a**0.5+b**0.5<c**0.5)
except:
	pass
