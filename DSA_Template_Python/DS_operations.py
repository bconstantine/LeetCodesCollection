** map(fun, iter) **
#fun : It is a function to which map passes each element of given iterable.
#iter : It is a iterable which is to be mapped.

** zip(list,list) **
for elem1,elem2 in zip(firstList,secondList):
	# will merge both lists and produce tuples with both elements
	# Tuples will stop at shortest list (in case of both lists having different len)
#Example
'''
a = ("John", "Charles", "Mike")
b = ("Jenny", "Christy", "Monica")

x = zip(a, b)

#use the tuple() function to display a readable version of the result:

print(tuple(x))
o/p: (('John', 'Jenny'), ('Charles', 'Christy'), ('Mike', 'Monica'))
'''

** any(list) ** [ OPPOSITE IS => ** all() ** ]
any(someList) # returns true if ANY element in list is true [any string, all numbers except 0 also count as true]

** enumerate(list|tuple) ** 
# [when you need to attach indexes to lists or tuples ]
enumerate(anyList) # ['a','b','c'] => [(0, 'a'), (1, 'b'), (2, 'c')]

** filter(function|list) **
filter(myFunction,list) # returns list with elements that returned true when passed in function

***************** import bisect ***********************

** bisect.bisect(list,number,begin,end) ** O(log(n))
# [ returns the index where the element should be inserted 
#		such that sorting order is maintained ]
a = [1,2,4]
bisect.bisect(a,3,0,4) # [1,2,4] => 2 coz '3' should be inserted in 2nd index to maintain sorting order

# Other variants of this functions are => bisect.bisect_left() | bisect.bisect_right()
# they have same arguments. Suppose the element we want to insert is already present
# in the sorting list, the bisect_left() will return index left of the existing number
# and the bisect_right() or bisect() will return index right to the existing number

# ** bisect.insort(list,number,begin,end)       ** O(n) to insert
# ** bisect.insort_right(list,number,begin,end) ** 
# ** bisect.insort_left(list,number,begin,end)  ** 

The above 3 functions are exact same of bisect.bisect(), the only difference
is that they return the sorted list after inserting and not the index. The
left() right() logic is also same as above.