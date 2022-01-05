import math

dpf = {}
dpg = {}


comb = {}
for i in range(0, 50):
    comb[i] = {}
    comb[i][i] = 1
    comb[i][0] = 1

for i in range(0, 50):
    for j in range(0, i+1):
        if j == i or j == 0:
            continue
        comb[i][j] = comb[i-1][j-1]+comb[i-1][j]

for i in range(0, 50):
  dpf[i] = {}
  dpg[i] = {}
  for j in range(0, 50):
	dpf[i][j] = {}
	dpg[i][j] = {}
	for h in range(0, 50):
	  dpf[i][j][h] = -1
	  dpg[i][j][h] = -1

def g(C, Q, P):
    if dpg[C][Q][P] >= 0:
        return dpg[C][Q][P]
    if Q == 0:
        return 1
    dpg[C][Q][P] = 0
    # sumamos cuando no puedo esquivarlo...
    for i in range(1, Q+1):
        dpg[C][Q][P] += (g(C, Q-i, P-1) * comb[Q][i])
        #print g(C, Q-i, P-1), comb[Q][i]
        #print C, Q, P, dpg[C][Q][P]
    if P > Q:
        dpg[C][Q][P] += g(C, Q, P-1)
    return dpg[C][Q][P]

def Calc(C, N):
    if C == 0:
        return 1
    res = comb[C+N][C] * g(C, C, C)
    return res

def f(N, K, C):
  if dpf[N][K][C] >= 0:
    return dpf[N][K][C];
  if K < N:
    return (C+K) ** (C+N)
  if N == 1:
    return 0
  dpf[N][K][C] = f(N-1, K-1, C+1) + f(N, K-1, 0) * Calc(C, N)
  #print N, K, C, dpf[N][K][C]
  return dpf[N][K][C]

def gcd(a, b):
  if b < a:
    return gcd(b, a)
  if a == 0:
      return b
  return gcd(b%a, a)

def run():
    pos = f(27, 42, 0)
    tot = 42 ** 27
    print pos
    print tot
    v = gcd(pos, tot)
    print pos/v
    print tot/v

#print g(2, 2,2)
run()
