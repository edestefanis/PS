modulus = 62674694810582163977646464092292439405182466161502960359408571447710174165909
q = 57248512388615138300979959427360676128469
p = 1094782941871623486260250734009229761
r =  (p-1) * (q-1)
e = 65537

def elev(n, e, mod):
    if e == 0:
        return 1
    if e == 1:
        return n
    res = elev(n, e/2, mod)
    res = (res * res) % mod
    if e&1:
        res = (res * n) % mod
    return res


def xgcd(b, a):
    x0, x1, y0, y1 = 1, 0, 0, 1
    while a != 0:
        q, b, a = b // a, a, b % a
        x0, x1 = x1, x0 - q * x1
        y0, y1 = y1, y0 - q * y1
    return  b, x0, y0

g, d, k  = xgcd(e, r)

print d
dd = (d * d * e)%r
print dd
print dd * e % r

import sys

# Read two files as byte arrays

print hex(modulus)
print hex(e)
print hex(dd)

if e * dd % r != 1:
    print "IMPOSSIBLE"
if (p-1) * (q-1) != r:
    print "IMPOSSIBLE"
if p*q != modulus:
    print "IMPOSSIBLE"

print "Start"

lista = ['a', 'b', 'c', 'd', 'e', 'f'];
def transform(n):
    if n  < 10:
        return str(n)
    return lista[n-10]

data = bytearray(open('data', 'rb').read())
print data

import binascii
hexa = binascii.hexlify(data)

print hexa
dec = int(hexa, 16)
res = elev(dec, dd, modulus)
print res
resh = hex(res).rstrip("L").lstrip("0x")
print resh
resh =  resh
resa = bytes(bytearray.fromhex(resh))
output = open('output', 'wb')
for c in resa :
    output.write(c)
output.close()

ress = resh.decode("hex")
print ress
print resa
