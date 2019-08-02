def maxSubProd(B):
	maxUntilNow = -999999;
	n = len(B)

	for i in range(0,n):
		prod = 1
		for j in range(i,n):
			prod *= B[j]

			if(maxUntilNow < prod):
				maxUntilNow = prod

	return maxUntilNow;

while True:
    try:
        B = [int(b) for b in input().split(" ")]; B = B[:-1];
        print(maxSubProd(B))

    except EOFError:
        break
