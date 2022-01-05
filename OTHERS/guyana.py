



#######################
# Powershell XOR 2 Files
# xor.py
# Jul 2016
# Website: http://www.Megabeets.net
# Use: ./xor.py file1 file2 outputFile
# Example: ./xor.py C:\a.txt C:\b.txt C:\result.txt
#######################

import sys

# Read two files as byte arrays
input = open('data', 'rb').read()

# Set the length to be the smaller one
size = len(input)

# XOR between the files
s = ""
for i in range(size):
	 s = s+str(int(ord(input[i])))

print s
# Write the XORd bytes to the output file
