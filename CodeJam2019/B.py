T = int(input())
for i in range(T):
	N = int(input())
	P = input()

	P_n = P.replace("E", "#")
	P_n = P_n.replace("S", "E")
	P_n = P_n.replace("#", "S")

	print("Case #" + str(i+1) + ": " + P_n)