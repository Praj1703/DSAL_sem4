#include <iostream>
#include <string>

using namespace std;

struct Node { 
    string label;
    int ch_count;
    Node* child[10]; 
    Node() : ch_count(0) { 
        for (int i = 0; i < 10; i++) {
            child[i] = nullptr; 
        }
    }
};

class GT { 
public:
    Node* root;

    GT() { 
        root = nullptr;
    }

    void create_tree();
    void display(Node* r1);
};

void GT::create_tree() {
    int tchapters;

    root = new Node; 
    cout << "Enter name of book: ";
    cin.ignore(); 
    getline(cin, root->label);
    
    cout << "Enter number of chapters in book: ";
    cin >> tchapters;
    root->ch_count = tchapters;

    for (int i = 0; i < tchapters; i++) {
        root->child[i] = new Node; 
        cout << "Enter the name of Chapter " << (i + 1) << ": ";
        cin.ignore(); 
        getline(cin, root->child[i]->label);
        
        cout << "Enter number of sections in Chapter " << (i + 1) << ": ";
        cin >> root->child[i]->ch_count;

        for (int j = 0; j < root->child[i]->ch_count; j++) {
            root->child[i]->child[j] = new Node; 
            cout << "Enter name of Section " << (j + 1) << ": ";
            cin.ignore(); 
            getline(cin, root->child[i]->child[j]->label);
        }
    }
}

void GT::display(Node* r1) {
    if (r1 == nullptr) return;

    cout << "Book: " << r1->label << endl;
    for (int i = 0; i < r1->ch_count; i++) {
        cout << "  Chapter " << (i + 1) << ": " << r1->child[i]->label << endl;
        for (int j = 0; j < r1->child[i]->ch_count; j++) {
            cout << "    Section " << (j + 1) << ": " << r1->child[i]->child[j]->label << endl;
        }
    }
}

int main() {
    GT gt;
    int choice;

    while (true) {
        cout<<"x----------------------x"<<endl;
		cout<<"|  BOOK TREE CREATION  |"<<endl;
		cout<<"x----------------------x\n"<<endl;
		cout<<"   1. Insert"<<endl;
		cout<<"   2. Display"<<endl;
		cout<<"   3. Exit"<<endl;
		cout<<"Enter Your Choice : ";
        cin >> choice;
		cout<<"*************************"<<endl;
        switch (choice) {
            case 1:
                gt.create_tree();
                cout<<"*************************"<<endl;
                break;
            case 2:
                gt.display(gt.root);
                cout<<"*************************"<<endl;
                
                break;
            case 3:
                cout << "Thanks for using this program!" << endl;
                cout<<"*************************"<<endl;
                return 0;
            default:
                cout << "Wrong choice!!!" << endl;
                cout<<"*************************"<<endl;
        }
    }

    return 0;
}
