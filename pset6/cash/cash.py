userchange = -0.01

while(userchange < 0.00):
    userchange = float(input("Change owed: "))

# Turn float into an int
userchange *= 100
change = int(userchange)

# Declare counter variable
counter = 0

while(change >= 25):
    change -= 25
    counter += 1
while(change >= 10):
    change -= 10
    counter += 1
while(change >= 5):
    change -= 5
    counter += 1
while(change >= 1):
    change -= 1
    counter += 1

print(counter)