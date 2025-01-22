#include <iostream>
#include <cstring> // For strcpy
using namespace std;

// Node structure representing a part of the book
struct TreeNode {
    char value[50];      // Node value (e.g., "Chapter 1", "Section 1.1")
    TreeNode* child;     // Pointer to the first child
    TreeNode* sibling;   // Pointer to the next sibling

    TreeNode(const char* val) {
        strcpy(value, val);
        child = nullptr;
        sibling = nullptr;
    }
};

// Function to add a child node
TreeNode* addChild(TreeNode* parent, const char* childValue) {
    TreeNode* newChild = new TreeNode(childValue);
    if (parent->child == nullptr) {
        parent->child = newChild;
    } else {
        TreeNode* temp = parent->child;
        while (temp->sibling != nullptr) {
            temp = temp->sibling;
        }
        temp->sibling = newChild;
    }
    return newChild;
}

// Function to print the tree recursively
void printTree(TreeNode* node, int level = 0) {
    if (!node) return;

    // Print the current node with indentation based on the level
    for (int i = 0; i < level; i++) {
        cout << "  ";
    }
    cout << node->value << endl;

    // Recursively print the child and sibling nodes
    printTree(node->child, level + 1);
    printTree(node->sibling, level);
}

// Main function
int main() {
    // Create the root node (Book)
    TreeNode* root = new TreeNode("Book");

    // Add chapters to the book
    TreeNode* chapter1 = addChild(root, "Chapter 1");
    TreeNode* chapter2 = addChild(root, "Chapter 2");

    // Add sections to Chapter 1
    TreeNode* section1_1 = addChild(chapter1, "Section 1.1");
    TreeNode* section1_2 = addChild(chapter1, "Section 1.2");

    // Add subsections to Section 1.1
    addChild(section1_1, "Subsection 1.1.1");
    addChild(section1_1, "Subsection 1.1.2");

    // Print the tree
    cout << "Book Structure:" << endl;
    printTree(root);

    // Cleanup dynamically allocated memory
    // Note: Proper deletion of all nodes is omitted for simplicity

    return 0;
}
