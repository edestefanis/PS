import warnings
from PIL import Image

im = Image.open('/Users/sony/Documents/GitHub/PS/poke.jpg')
pix = im.load()
warnings.simplefilter('ignore', Image.DecompressionBombWarning)

import os

mat = {}
name = {}
cant = {}
n = {}
c = {}
for i in range(0, 150):
    mat[i] = {}
    name[i] = 'A'
    cant[i] = 0
    n[i] = {}
    c[i] = {}
    for j in range(0, 25):
        mat[i][j] = 0
        n[i][j] = 'A'
        c[i][j] = 0

images = []

for i in range(0, 24):
    for j in range(0, 24):
        print i, j
        im2 = im
        poke = im2.crop((i*400, j*400, (i+1)*400, (j+1)*400))
        print poke.size
        filename = str(i)+"_"+str(j)+".jpg"
        if i == 0 and j == 0:
            images.append((poke, 92))
            name[92] = 'G'
            c[92] = 6
        if i == 0 and j == 1:
            images.append((poke, 82))
            name[82] = 'M'
            c[82] = 8
        if i == 0 and j == 2:
            images.append((poke, 17))
            name[17] = 'P'
            c[17] = 9
        if i == 0 and j == 3:
            images.append((poke, 30))
            name[30] = 'N'
            c[30] = 8
        if i == 0 and j == 4:
            images.append((poke, 26))
            name[26] = 'R'
            c[26] = 6
        if i == 0 and j == 5:
            images.append((poke, 16))
            name[16] = 'P'
            c[16] = 6
        if i == 0 and j == 6:
            images.append((poke, 73))
            name[73] = 'T'
            c[73] = 10
        if i == 0 and j == 7:
            images.append((poke, 12))
            name[12] = 'B'
            c[12] = 10
        if i == 0 and j == 8:
            images.append((poke, 95))
            name[95] = 'O'
            c[95] = 4
        if i == 0 and j == 10:
            images.append((poke, 66))
            name[66] = 'M'
            c[66] = 6
        if i == 0 and j == 11:
            images.append((poke, 32))
            name[32] = 'N'
            c[32] = 7
        if i == 0 and j == 12:
            images.append((poke, 19))
            name[19] = 'R'
            c[19] = 7
        if i == 0 and j == 16:
            images.append((poke, 87))
            name[87] = 'D'
            c[87] = 7
        if i == 0 and j == 20:
            images.append((poke, 28))
            name[28] = 'S'
            c[28] = 9
        if i == 1 and j == 1:
            images.append((poke, 117))
            name[117] = 'S'
            c[117] = 6
        if i == 1 and j == 3:
            images.append((poke, 24))
            name[24] = 'A'
            c[24] = 5
        if i == 1 and j == 4:
            images.append((poke, 13))
            name[13] = 'W'
            c[13] = 6
        if i == 1 and j == 6:
            images.append((poke, 72))
            name[72] = 'T'
            c[72] = 9
        if i == 1 and j == 8:
            images.append((poke, 22))
            name[22] = 'F'
            c[22] = 6
        if i == 1 and j == 9:
            images.append((poke, 10))
            name[10] = 'C'
            c[10] = 8
        if i == 1 and j == 13:
            images.append((poke, 7))
            name[7] = 'S'
            c[7] = 8
        if i == 1 and j == 16:
            images.append((poke, 18))
            name[18] = 'P'
            c[18] = 7
        if i == 1 and j == 17:
            images.append((poke, 27))
            name[27] = 'S'
            c[27] = 9
        if i == 1 and j == 21:
            images.append((poke, 11))
            name[11] = 'M'
            c[11] = 7
        if i == 2 and j == 6:
            images.append((poke, 71))
            name[71] = 'V'
            c[71] = 10
        if i == 2 and j == 10:
            images.append((poke, 79))
            name[79] = 'S'
        if i == 3 and j == 0:
            images.append((poke, 85))
            name[85] = 'D'
        if i == 3 and j == 2:
            images.append((poke, 93))
            name[93] = 'H'
        if i == 3 and j == 4:
            images.append((poke, 8))
            name[8] = 'W'
        if i == 3 and j == 5:
            images.append((poke, 94))
            name[94] = 'G'
        if i == 3 and j == 6:
            images.append((poke, 70))
            name[70] = 'W'
        if i == 4 and j == 1:
            images.append((poke, 25))
            name[25] = 'P'
        if i == 4 and j == 2:
            images.append((poke, 69))
            name[69] = 'B'
        if i == 4 and j == 4:
            images.append((poke, 23))
            name[23] = 'E'
        if i == 4 and j == 7:
            images.append((poke, 9))
            name[9] = 'B'
        if i == 4 and j == 8:
            images.append((poke, 15))
            name[15] = 'B'
        if i == 4 and j == 10:
            images.append((poke, 118))
            name[118] = 'G'
        if i == 4 and j == 22:
            images.append((poke, 50))
            name[50] = 'D'
        if i == 5 and j == 4:
            images.append((poke, 6))
            name[6] = 'C'
        if i == 6 and j == 11:
            images.append((poke, 86 ))
            name[86] = 'S'
        if i == 7 and j == 6:
            images.append((poke, 74))
            name[74] = 'G'
        if i == 8 and j == 3:
            images.append((poke, 29))
            name[29] = 'N'
        if i == 8 and j == 6:
            images.append((poke, 75))
            name[75] = 'G'
        if i == 9 and j == 2:
            images.append((poke, 60))
            name[60] = 'P'
        if i == 9 and j == 6:
            images.append((poke, 76))
            name[76] = 'G'
        if i == 10 and j == 6:
            images.append((poke, 77))
            name[77] = 'P'
        if i == 10 and j == 17:
            images.append((poke, 20))
            name[20] = 'R'
        if i == 11 and j == 3:
            images.append((poke, 81))
            name[81] = 'M'
        if i == 11 and j == 8:
            images.append((poke, 83))
            name[83] = 'F'
        if i == 11 and j == 16:
            images.append((poke, 80))
            name[80] = 'S'
        if i == 12 and j == 14:
            images.append((poke, 21))
            name[21] = 'S'
        if i == 15 and j == 8:
            images.append((poke, 88))
            name[88] = 'G'
        if i == 17 and j == 14:
            images.append((poke, 14))
            name[14] = 'K'
        if i == 18 and j == 3:
            images.append((poke, 54))
            name[54] = 'P'
        if i == 19 and j == 5:
            images.append((poke, 78))
            name[78] = 'R'

        for ima in images:
            if poke == ima[0]:
                mat[j][i] = ima[1]
                n[j][i] = name[ima[1]]

        if os.path.exists(filename):
            os.remove(filename)
        poke.save(filename)

for i in range(0, 24):
    s = ""
    for j in range(0, 24):
        if mat[i][j] < 10:
            s = s + " "
        if mat[i][j] < 100:
            s = s + " "
        s = s + ' ' + str(127-mat[i][j])
    print s
for i in range(0, 25):
    s = ""
    for j in range(0, 25):
        #if mat[i][j] < 10:
        #    s = s + " "
        #if mat[i][j] < 100:
        #    s = s + " "
        if mat[i][j] & 1:
            s = s + str(0)
        else:
            s = s + str(1)
    print s

s = ""
for i in range(0, 25):
    for j in range(0, 25):
        if mat[24-i][24-j] == 0:
            break
        s = s +  str(mat[24-i][24-j])
print
s = ""
for i in range(0, 24):
    for j in range(0, 24):
        if mat[i][j] == 0:
            continue
        s = s + str(unichr(127-mat[i][j]))

print s
print 'iniciales:'
s = ""
for i in range(0, 24):
    for j in range(0, 24):
        if mat[i][j] == 0:
            continue
        s = s + n[i][j]
print s
print 'iniciales:'
s = ""
for i in range(0, 25):
    for j in range(0, 25):
        if mat[24-i][24-j] == 0:
            continue
        s = s + n[24-i][24-j]

print s

for i in range(0, 24):
    s = ""
    for j in range(0, 24):
        if mat[i][j] == 0:
            continue
        s = s + " " + n[i][j]
    print s
