# set={"A","B","C"}
# print(set)

# to remove the element in the set we can use the functions like remove , discard , pop , del 


# Method 	Shortcut 	Description
# add() 	  	Adds an element to the set
# clear() 	  	Removes all the elements from the set
# copy() 	  	Returns a copy of the set
# difference() 	- 	Returns a set containing the difference between two or more sets
# difference_update() 	-= 	Removes the items in this set that are also included in another, specified set
# discard() 	  	Remove the specified item
# intersection() 	& 	Returns a set, that is the intersection of two other sets
# intersection_update() 	&= 	Removes the items in this set that are not present in other, specified set(s)
# isdisjoint() 	  	Returns whether two sets have a intersection or not
# issubset() 	<= 	Returns whether another set contains this set or not
#   	< 	Returns whether all items in this set is present in other, specified set(s)
# issuperset() 	>= 	Returns whether this set contains another set or not
#   	> 	Returns whether all items in other, specified set(s) is present in this set
# pop() 	  	Removes an element from the set
# remove() 	  	Removes the specified element
# symmetric_difference() 	^ 	Returns a set with the symmetric differences of two sets
# symmetric_difference_update() 	^= 	Inserts the symmetric differences from this set and another
# union() 	| 	Return a set containing the union of sets
# update() 	|= 	Update the set with the union of this set and others

print("Set1 = ")
set1 = {1,2,3,4,5,6}
set1.add(7)

print (set1)
print("Set2 = ")
set2 = {11,12,13,14,15,6}
print(set2)


print("Union of the two sets ")

set3 = set1 | set2
print(set3)
# for x in set3:
#     print(x)

print("Insertion of two sets")
set_intersection = set1 & set2
print(set_intersection)
print("Diffrence of two sets :")
set_diff = set1 - set2
print(set_diff)

print("Sym diff of two sets :")
set_sym_diff = set1^set2 # symmetric_difference()
print(set_sym_diff)

print("Issubset ? ")
set_issubset = set1 <= set2 #set1.issubset(set2)
print(set_issubset)

print("(in) and ( not in ) in the sets ")
print(7 in set3) #{1, 2, 3, 4, 5, 6, 7, 11, 12, 13, 14, 15}
print(6 not in set3) #{1, 2, 3, 4, 5, 6, 7, 11, 12, 13, 14, 15}

print("Operations using iterators")
print("Union of two sets using itrators : ")
union_set = set()

for i in set1:
    union_set.add(i)
for j in set2:
    union_set.add(j)

print(union_set)


print("Intersection of two sets using itrators : ")

intersection_set = set()

for i in set1:
    if i in set2:
        intersection_set.add(i)
print(intersection_set)

print("Difference of two sets using itrators : ")

difference_set = set()

for i in set1:
    if i not in set2:
        difference_set.add(i)
print(difference_set)

print("Symmetric Differnce of two sets using itrators : ")
symmetric_difference = set()
for i in set1:
    if i not in set2:
        symmetric_difference.add(i)
for i in set2:
    if i not in set1:
        symmetric_difference.add(i)
print(symmetric_difference)        

print("Issubset of two sets using itrators : ")
issubset_set = True
for i in set1:
    if i not in set2:
        issubset_set = False
        break
print(issubset_set)