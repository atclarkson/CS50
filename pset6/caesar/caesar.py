# Cipher key program, takes a compand line input as the key and
# converts a plain text input from user to ciphertext via shifting
# letters by key value.
import sys

if len(sys.argv) != 2:
    print("Error: None or more than one command-line argument entered")

k = int(sys.argv[1])
p = input("plaintext: ")

cipher = ""

for i in range(len(p)):
    offset = 0
    if(p[i] >= 'A' and p[i] <= 'Z'):
        offset = 65
    elif(p[i] >= 'a' and p[i] <= 'z'):
        offset = 97
    else:
        cipher += p[i]
    if(offset != 0):
        letter = ((ord(p[i]) - offset) + k) % 26
        c = letter + offset
        cipher += chr(c)
print(f"ciphertext: {cipher}")