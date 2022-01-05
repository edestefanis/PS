from PIL import Image

im = Image.open('/Users/sony/Documents/GitHub/PS/chino.png')
pix = im.load()

c = 0
previous = ()
s = ""
bits = ""
mi = 200
ma = 1
# 01110000  10010110
# 00111110  01001011
for i in range(1, 1786):
    mi = min(mi, pix[0,i][2])
    ma = max(ma, pix[0,i][2])
    if pix[0,i] == previous:
        c = c+1
    else:
        print previous, c
        if c > 1 and 64+c < 128:
            s = s + str(unichr(64+c))
        for i in range(1,c):
            bits = bits + "0"
        bits += "1"
        previous = pix[0,i]
        c = 1
    #print (pix[c,i][0] - pix[c, i-1][0], pix[c,i][1] - pix[c, i-1][1],pix[c,i][2] - pix[c, i-1][2])

print mi, ma
print bits
print s
