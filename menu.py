# #from set_operation import set
# # set1 = {}

# # size= input(print("Enter the number of the element :"))
# # for i in range(1, size):
# #     el= input(print("Enter the Element : "))
# #     set1.add(el)


# choice = input(print("Enter Your Choice\n"))
# print("***********Menu*************")
# print("x--------------------------x")
# print("|1. Add Element            |")
# print("|2. Remove Element         |")
# print("|3. Contains Element       |")
# print("|4. size                   |")
# print("|5. intersection of set    |")
# print("|6. Uninon of sets         |")
# print("|7. Differnce of sets      |")
# print("|8. Check Subset           |")
# print("|9. Iterator               |")
# print("x--------------------------x\n")

# if choice == 1:
#     addEl=input(print("Enter number to add :"))
#     set1.add(addEl)
#     print(set1, "\n")
# elif choice == 2:
#     removeEl = input(print("Enter the number to delete from set : "))
#     set1.remove(removeEl)
#     print(set1, "\n")



set1 = set()


size = int(input("Enter the number of elements: "))
for i in range(size):
    el = input("Enter the Element: ")
    set1.add(el)

while True:

    print("\n***********Menu*************")
    print("x--------------------------x")
    print("|1. Add Element            |")
    print("|2. Remove Element         |")
    print("|3. Contains Element       |")
    print("|4. Size                   |")
    print("|5. Intersection of sets   |")
    print("|6. Union of sets          |")
    print("|7. Difference of sets     |")
    print("|8. Check Subset           |")
    print("|9. Iterator               |")
    print("|10. Exit                  |")
    print("x--------------------------x\n")
    
    choice = int(input("Enter Your Choice: "))
    
    if choice == 1:
        addEl = input("Enter number to add: ")
        set1.add(addEl)
        print(f"Updated Set: {set1}\n")
    
    elif choice == 2:
        removeEl = input("Enter the number to delete from set: ")
        if removeEl in set1:
            set1.remove(removeEl)
            print(f"Updated Set: {set1}\n")
        else:
            print(f"Element {removeEl} not found in the set.\n")
    
    elif choice == 3:
        element = input("Enter the element to check: ")
        if element in set1:
            print(f"Element {element} is present in the set.\n")
        else:
            print(f"Element {element} is not found in the set.\n")
    
    elif choice == 4:
        print(f"The size of the set is: {len(set1)}\n")
    
    elif choice == 5:
        
        set2 = set(input("Enter the second set (comma-separated): ").split(","))
        print(f"Intersection: {set1 & set2}\n")
    
    elif choice == 6:
       
        set2 = set(input("Enter the second set (comma-separated): ").split(","))
        print(f"Union: {set1 | set2}\n")
    
    elif choice == 7:
        
        set2 = set(input("Enter the second set (comma-separated): ").split(","))
        print(f"Difference: {set1 - set2}\n")
    
    elif choice == 8:
        set2 = set(input("Enter the set to check as subset (comma-separated): ").split(","))
        if set2.issubset(set1):
            print(f"{set2} is a subset of {set1}\n")
        else:
            print(f"{set2} is not a subset of {set1}\n")
    
    elif choice == 9:
        print("Iterating through the set:")
        for item in set1:
            print(item)
    
    elif choice == 10:
        print("Exiting program.")
        break
    
    else:
        print("Invalid choice. Please try again.")
