import math
 
a = 2.3
 
# returning the ceil of 2.3 (i.e 3)
print ("The ceil of 2.3 is : ", end="")
print (math.ceil(a))
 
# returning the floor of 2.3 (i.e 2)
print ("The floor of 2.3 is : ", end="")
print (math.floor(a))

#Constants
# Print the value of Euler e (2.718281828459045)
print (math.e)
# Print the value of pi (3.141592653589793)
print (math.pi)
print (math.gcd(b, a))
print (pow(3,4))
# print the square root of 4
print(math.sqrt(4))
a = math.pi/6
b = 30
 
# returning the converted value from radians to degrees
print ("The converted value from radians to degrees is : ", end="")
print (math.degrees(a))
 
# returning the converted value from degrees to radians
print ("The converted value from degrees to radians is : ", end="")
print (math.radians(b))

bin(int)
bin(anyNumber) # Returns binary version of number

divmod(int,int)
divmod(dividend,divisor) # returns tuple like (quotient, remainder)