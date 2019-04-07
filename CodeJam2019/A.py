T = int(input())
for i in range(T):
	N = input()

	A = B = ""
	for a in N:
		if(a == "4"):
			A += "3"
			B += "1"
		else:
			A += a
			B += "0"

	print("Case #" + str(i+1) + ": " + str(int(A)) + " " + str(int(B)))