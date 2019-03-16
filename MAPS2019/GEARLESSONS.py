from fractions import Fraction

F, B = [int(a) for a in input().split()]

F_i = [int(a) for a in input().split()]
B_i = [int(a) for a in input().split()]

G = []
for f in F_i:
	for b in B_i:
		G.append([f, b, Fraction(f,b)])

G.sort(key=lambda x: (x[2], x[0]))

for g in G:
	print("("+str(g[0])+","+str(g[1])+")")