from set_operations import SetOperations

def main():
    set1 = SetOperations()
    set2 = SetOperations()

    print("Enter elements for Set 1 (comma-separated): ")
    set1.add_multiple(input().split(','))

    print("Enter elements for Set 2 (comma-separated): ")
    set2.add_multiple(input().split(','))

    while True:
        print("\nMenu:")
        print("1. Display Sets")
        print("2. Add Element to Set")
        print("3. Remove Element from Set")
        print("4. Union of Sets")
        print("5. Intersection of Sets")
        print("6. Difference of Sets")
        print("7. Symmetric Difference of Sets")
        print("8. Check Subset")
        print("9. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            print("Set 1:", set1.get_elements())
            print("Set 2:", set2.get_elements())
        elif choice == 2:
            set_choice = int(input("Add to Set 1 or Set 2? (1/2): "))
            element = input("Enter element to add: ")
            if set_choice == 1:
                set1.add(element)
            else:
                set2.add(element)
        elif choice == 3:
            set_choice = int(input("Remove from Set 1 or Set 2? (1/2): "))
            element = input("Enter element to remove: ")
            if set_choice == 1:
                set1.remove(element)
            else:
                set2.remove(element)
        elif choice == 4:
            print("Union:", set1.union(set2))
        elif choice == 5:
            print("Intersection:", set1.intersection(set2))
        elif choice == 6:
            print("Difference (Set1 - Set2):", set1.difference(set2))
        elif choice == 7:
            print("Symmetric Difference:", set1.symmetric_difference(set2))
        elif choice == 8:
            print("Is Set1 a subset of Set2?", set1.is_subset(set2))
        elif choice == 9:
            print("Exiting...")
            break
        else:
            print("Invalid choice! Please try again.")

if __name__ == "__main__":
    main()



class SetOperations:
    def __init__(self):
        self.set_data = set()

    def add(self, element):
        self.set_data.add(element)

    def add_multiple(self, elements):
        for element in elements:
            self.set_data.add(element.strip())  # Remove any leading/trailing spaces

    def remove(self, element):
        if element in self.set_data:
            self.set_data.remove(element)
        else:
            print(f"Element {element} not found in set.")

    def get_elements(self):
        return self.set_data

    def union(self, other_set):
        result = set(self.set_data)  # Create a copy of current set
        for element in other_set.get_elements():
            result.add(element)
        return result

    def intersection(self, other_set):
        result = set()
        for element in self.set_data:
            if element in other_set.get_elements():
                result.add(element)
        return result

    def difference(self, other_set):
        result = set()
        for element in self.set_data:
            if element not in other_set.get_elements():
                result.add(element)
        return result

    def symmetric_difference(self, other_set):
        result = set()
        for element in self.set_data:
            if element not in other_set.get_elements():
                result.add(element)
        for element in other_set.get_elements():
            if element not in self.set_data:
                result.add(element)
        return result

    def is_subset(self, other_set):
        for element in self.set_data:
            if element not in other_set.get_elements():
                return False
        return True




############################################################################################


from set_operations import SetOperations

def main():
    set1 = SetOperations()
    set2 = SetOperations()

    print("Enter elements for Set 1 (comma-separated): ")
    set1.add_multiple(input().split(','))

    print("Enter elements for Set 2 (comma-separated): ")
    set2.add_multiple(input().split(','))

    while True:
        print("\nMenu:")
        print("1. Display Sets")
        print("2. Add Element to Set")
        print("3. Remove Element from Set")
        print("4. Union of Sets")
        print("5. Intersection of Sets")
        print("6. Difference of Sets")
        print("7. Symmetric Difference of Sets")
        print("8. Check Subset")
        print("9. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            print("Set 1:", set1.get_elements())
            print("Set 2:", set2.get_elements())
        elif choice == 2:
            set_choice = int(input("Add to Set 1 or Set 2? (1/2): "))
            element = input("Enter element to add: ")
            if set_choice == 1:
                set1.add(element)
            else:
                set2.add(element)
        elif choice == 3:
            set_choice = int(input("Remove from Set 1 or Set 2? (1/2): "))
            element = input("Enter element to remove: ")
            if set_choice == 1:
                set1.remove(element)
            else:
                set2.remove(element)
        elif choice == 4:
            print("Union:", set1.union(set2))
        elif choice == 5:
            print("Intersection:", set1.intersection(set2))
        elif choice == 6:
            print("Difference (Set1 - Set2):", set1.difference(set2))
        elif choice == 7:
            print("Symmetric Difference:", set1.symmetric_difference(set2))
        elif choice == 8:
            print("Is Set1 a subset of Set2?", set1.is_subset(set2))
        elif choice == 9:
            print("Exiting...")
            break
        else:
            print("Invalid choice! Please try again.")

if __name__ == "__main__":
    main()




class SetOperations:
    def __init__(self):
        self.set_data = set()

    def add(self, element):
        self.set_data.add(element)

    def add_multiple(self, elements):
        self.set_data.update(elements)

    def remove(self, element):
        if element in self.set_data:
            self.set_data.remove(element)
        else:
            print(f"Element {element} not found in set.")

    def get_elements(self):
        return self.set_data

    def union(self, other_set):
        return self.set_data | other_set.get_elements()

    def intersection(self, other_set):
        return self.set_data & other_set.get_elements()

    def difference(self, other_set):
        return self.set_data - other_set.get_elements()

    def symmetric_difference(self, other_set):
        return self.set_data ^ other_set.get_elements()

    def is_subset(self, other_set):
        return self.set_data <= other_set.get_elements()
