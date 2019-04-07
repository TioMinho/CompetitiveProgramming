import itertools

def sieveErastophenes(n):
	A = [True] * (n+1)
	for i in range(2, int((n+1) ** 0.5)):
		if A[i] is True:
			k = 0; j = i**2
			while(j <= n):
				A[j] = False

				j = i**2 + k*i; k += 1
	return [i for i in range(2, n+1) if A[i]]

T = int(input())
for i in range(0,T):
	N, T = [int(x) for x in input().split(" ")]
	text = [int(n) for n in input().split(" ")]

	primes = sieveErastophenes(N)

	sub_primes = set()
	for a in text:
		for m in range(0,len(primes)):
			for n in range(m,len(primes)):
				if(primes[m]*primes[n] == a):
					sub_primes.add(primes[m]); 
					sub_primes.add(primes[n])

		if(len(sub_primes) == 26): break
			
	cypher = cypher_r = {}
	for sp, a in zip(sorted(sub_primes), "ABCDEFGHIJKLMNOPQRSTUVWXYZ"):
		cypher[sp] = a
		cypher_r[a] = sp

	real_text = ""; leave = False
	for a1 in sub_primes:
		for a2 in sub_primes:
			if(a1*a2 == text[0]):
				real_text += cypher[a1] + cypher[a2]
				leave = True
				break
		if(leave) : break

	
	for j in range(1, len(text)):
		for k in sub_primes:
			if(cypher_r[real_text[j]] * k == text[j]):
				real_text += cypher[k]
				break

	print("Case #" + str(i+1) + ":", real_text)