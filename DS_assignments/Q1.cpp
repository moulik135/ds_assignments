class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def insert_at_end(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node

    def insert_before_after(self, target, data, before=True):
        if not self.head:
            print("List is empty.")
            return
        
        new_node = Node(data)

        if before and self.head.data == target:
            new_node.next = self.head
            self.head = new_node
            return

        prev = None
        current = self.head

        while current and current.data != target:
            prev = current
            current = current.next

        if current is None:
            print(f"Node with value {target} not found.")
            return
        
        if before:
            prev.next = new_node
            new_node.next = current
        else:
            new_node.next = current.next
            current.next = new_node

    def delete_from_beginning(self):
        if not self.head:
            print("List is empty.")
            return
        self.head = self.head.next

    def delete_from_end(self):
        if not self.head:
            print("List is empty.")
            return
        if not self.head.next:
            self.head = None
            return
        temp = self.head
        while temp.next.next:
            temp = temp.next
        temp.next = None

    def delete_node(self, key):
        if not self.head:
            print("List is empty.")
            return
        
        if self.head.data == key:
            self.head = self.head.next
            return
        
        prev = None
        current = self.head
        while current and current.data != key:
            prev = current
            current = current.next
        
        if current is None:
            print(f"Node with value {key} not found.")
            return
        
        prev.next = current.next

    def search(self, key):
        temp = self.head
        position = 1
        while temp:
            if temp.data == key:
                print(f"Node {key} found at position {position}.")
                return
            temp = temp.next
            position += 1
        print(f"Node {key} not found in the list.")

    def display(self):
        if not self.head:
            print("List is empty.")
            return
        temp = self.head
        print("List nodes:", end=" ")
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("None")

def menu():
    sll = SinglyLinkedList()

    while True:
        print("\nMenu:")
        print("1. Insert at beginning")
        print("2. Insert at end")
        print("3. Insert before/after a node")
        print("4. Delete from beginning")
        print("5. Delete from end")
        print("6. Delete a specific node")
        print("7. Search for a node")
        print("8. Display the list")
        print("9. Exit")

        choice = input("Enter your choice (1-9): ")

        if choice == '1':
            data = int(input("Enter value to insert at beginning: "))
            sll.insert_at_beginning(data)

        elif choice == '2':
            data = int(input("Enter value to insert at end: "))
            sll.insert_at_end(data)

        elif choice == '3':
            target = int(input("Enter the node value to insert before/after: "))
            data = int(input("Enter new node value to insert: "))
            pos_choice = input("Insert before or after? (b/a): ").lower()
            if pos_choice == 'b':
                sll.insert_before_after(target, data, before=True)
            elif pos_choice == 'a':
                sll.insert_before_after(target, data, before=False)
            else:
                print("Invalid choice. Please enter 'b' or 'a'.")

        elif choice == '4':
            sll.delete_from_beginning()

        elif choice == '5':
            sll.delete_from_end()

        elif choice == '6':
            key = int(input("Enter the node value to delete: "))
            sll.delete_node(key)

        elif choice == '7':
            key = int(input("Enter node value to search: "))
            sll.search(key)

        elif choice == '8':
            sll.display()

        elif choice == '9':
            print("Exiting program.")
            break

        else:
            print("Invalid choice! Please enter a number between 1 and 9.")

if __name__ == "__main__":
    menu()
