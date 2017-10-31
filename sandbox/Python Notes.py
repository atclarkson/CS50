# Lists

nums = [1, 2, 3, 4]

#  List comprehension
num = [x for x in range(500)]
# Basically what is we are using a for list to generate a list of numbers for us.
# would end up being >>> [0, 1, 2, ... 498, 499]

nums = list()  # Same as creating blank empty list
nums.append(5)  # adds 5 to the end of our list

# >>>  [1, 2, 3, 4, 5]

nums.insert(4,5)  #  This would be the same thing as the last append example,
#  Insert a 5 in the 4th position.

nums[len(nums):] = [5]   # Same thing again.

# This time it calculates the length of the string.
# and combines to the two lists - [5] is a new list
# The colon operater means it will place the new string at the end.
# If the colon had been before len(nums) it would have put the new string at the begining


## Tuples  ##

#  Ordered immutable set of Data

#  Basically we have a set of things that we will never change but the order matters
#  Kind of like a structure in C

#  You can have a list of Tuples

presidents = [
    ("George Washington", 1789),
    ("John Adams", 1797),
    ("Thomas Jefferson", 1801),
    ("James Madison", 1809)
]

#  This is a list of 4 tuples.
#  Each tuple will never change.

# You can iterate over the list

for prez, year in presidents:
    print("In {1}, {0} took office".format(prez, year))


## Dictionaries  ##

# Close in spirit to a hash table
# allows us to associate indexes with keys
# Associate elements of the dictionary with keywords

pizzas = {
    "cheese": 9,
    "pepperoni": 10,
    "vegetable": 11,
    "buffalo chicken": 12
}

# Note the style of brakcets.  In lists we had [] brackets.  Now in Dictionaries we have {} brakcets.
# Use a colon to seperate the key/value pair.

####     KEY:VALUE

# You can change the value of different key/value pairs in the dictionary
pizzas["cheese"] = 8

# You can do logic on them
if pizza["vegetables"] < 12:
    # do something

# You can easilly add a new pair
pizzas["bacon"] = 14

#Loops (redux)

# The for loop in Python is extremly flexible!

for pie in pizzas:
    # use pie in here as a stand-in for "i"
    print(pie)

#>>>cheese
#>>>vegetable
#>>>buffalo chicken
#>>>pepperoni

for pie, price in pizzas.items():
    print(price)

#>>>12
#>>>10
#>>>9
#>>>11

for pie, price in pizzas.items():
    print("A whole {} pizza costs ${}".format(pie, price))

#>>>A whole buffalo chicken pizza costs $12
#>>>A whole pepperoni pizza costs $10
#>>>A whole cheese pizza costs $9
#>>>A whole vegetable pizza costs $11

# NOT ORDERED, May be random order

print("A whole " + pie + " pizza costs $" + str(price))

# Same output as above.


## Functions ##

def square(x):
    return x * x

def square(x):
    return X ** 2

def square(x):
    result = 0
    for i in range(0, x):
        result += x
    return result

#  All three of those functions are essentially the same
#  Don't forget we don't really care how the function works as long as when it's called it performs as expected
#  All three should produce the following when called

print(square(5))  #  The function can be a black box.

#>>>25

## OBJECTS ##

# Python is an object-oriented programming language.
# An object is sort of analogous to a C structure

# C structures contain a number of fields, wich we might also call properties
    # But the properties themselves can not ever stand on their own.

struct car
{
    int year;
    char *model;
}

struct car herbie;
herbie.year = 1963;
herbie.model = beatle;

## As in C the "fields" or properties are tied to the Struct.  You can't just name a year
struct car herbie;
year = 1963;
model = beatle;
#this would not be legal.


#  Object, meanwhile, have properties but also methods, or functions that are inherent
#  to the object, and mean nothing outside of it. You define the methods inside the objuct also.
    # Thus, properties and methods don't ever stand on their own.

object.method()

# You define a type of object using the class keyword in python

class Student():

    def __init__(self, name, id):
        self.name = name
        self.id = id

    def changID(self, id):
        self.id = id

    def print(self):
        print("{} - {}".format(self.name, self.id))


jane = Student("Jane", 10)
jane.print()
jane.changeID(11)
jane.print()

#>>>Jane - 10
#>>>Jane - 11








