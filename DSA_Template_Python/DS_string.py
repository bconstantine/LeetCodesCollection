# ** split Function **
#The split() method breaks up a string at the specified separator and returns a list of strings.
text = 'Python is a fun programming language'

# split the text from space
print(text.split(' '))

#convert string to list
s="abcd"
s=list(s)

# Output: ['Python', 'is', 'a', 'fun', 'programming', 'language']

# ** count Function **
#The count() method returns the number of occurrences of a substring in the given string.
#Example
message = 'python is popular programming language'
# number of occurrence of 'p'
print('Number of occurrence of p:', message.count('p')) # Output: Number of occurrence of p: 4

#The isnumeric() method returns True if all characters in a string are numeric characters. If not, it returns False.
s = '1242323'
print(s.isnumeric()) #Output: True

#The find() method returns the index of first occurrence of the substring (if found). If not found, it returns -1.
# check the index of 'fun'
print(message.find('fun')) # Output: 12

#The isalnum() method returns True if all characters in the string are alphanumeric (either alphabets or numbers). If not, it returns False.

name = "M3onica Gell22er "
print(name.isalnum()) # Output : False

#The isalpha() method returns True if all characters in the string are alphabets. If not, it returns False
name = "Monica"
print(name.isalpha()) #output true

#other imp functions
string.strip([chars]) #The strip() method returns a copy of the string by removing both the leading and the trailing characters (based on the string argument passed).
string.upper() #he upper() method converts all lowercase characters in a string into uppercase characters and returns it.
string.lower() #The lower() method converts all uppercase characters in a string into lowercase characters and returns it.
string.islower()
string.isdigit()
string.isupper()