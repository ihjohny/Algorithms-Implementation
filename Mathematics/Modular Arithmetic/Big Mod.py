def bigMod(b,p,m):
	if p == 0:
		return 1
	if p % 2 == 0:
		res = bigMod(b, int(p/2), m)
		return ((res%m) * (res%m) %m)
	else:
		return ((b%m) * (bigMod(b,p-1,m)) %m)

# b^(m-2) = a^-1 (mod m) m should be prime
def modInverse(b,p,m):
	return bigMod(b,m-2,m)
	
while True:
	
	b = int(input())
	p = int(input())
	m = int(input())
	
	print(bigMod(b,p,m))
	print(modInverse(b,p,m))
	
