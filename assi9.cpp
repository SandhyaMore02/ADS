#include <iostream>
#include <list>
#include <string>
using namespace std;

struct node {
    int key;
    string val;
    node(int key, string &v) : key(key), val(v) {}
};

struct node1 {
    int key;
    string val;
    node1 *next;
    node1(int key, string &v) : key(key), val(v), next(nullptr) {}
};

class HashTable {
private:
    list<node*> table;
    list<node1*> table1;
    int ts;

public:
    HashTable(int size) : ts(size) {}

    int hash(int key) {
        return key % ts;
    }

    void insert(int key, string &val) {
        int i = hash(key);
        node *nn = new node(key, val);
        table.push_back(nn);
    }

    string find(int key) {
        int i = hash(key);
        for (auto it = table.begin(); it != table.end(); ++it) {
            if ((*it)->key == key) {
                return "name:" + (*it)->val;
            }
        }
        return "contact not found ";
    }

    void remove(int key) {
        int i = hash(key);
        for (auto it = table.begin(); it != table.end(); ++it) {
            if ((*it)->key == key) {
                cout << "deleted contact: " << (*it) << endl;
                delete (*it);
                table.erase(it);
                return;
            }
        }
        cout << "contact not found" << endl;
    }

    void display() {
        cout << "Contact List:" << endl;
        int idx = 1;
        for (auto it = table.begin(); it != table.end(); ++it) {
            cout << "Contact- " << idx++ << ": ";
            cout << "[" << (*it)->key << ":" << (*it)->val << "] ";
            cout << endl;
        }
    }

    void insert1(int key, string &val) {
        int i = hash(key);
        node1 *nn = new node1(key, val);
        table1.push_back(nn);
    }

    string find1(int key) {
        int i = hash(key);
        for (auto it = table1.begin(); it != table1.end(); ++it) {
            if ((*it)->key == key) {
                return "value:" + (*it)->val;
            }
        }
        return "key not found";
    }

    void remove1(int key) {
        int i = hash(key);
        for (auto it = table1.begin(); it != table1.end(); ++it) {
            if ((*it)->key == key) {
                cout << "deleted key: " << key << endl;
                delete (*it);
                table1.erase(it);
                return;
            }
        }
        cout << "key not found" << endl;
    }

    void display1() {
        cout << "Hash Table:" << endl;
        int idx = 1;
        for (auto it = table1.begin(); it != table1.end(); ++it) {
            cout << "Index: " << idx++ << ": ";
            node1 *curr = *it;
            while (curr) {
                cout << "[" << curr->key << ":" << curr->val << "]";
                curr = curr->next;
            }
            cout << endl;
        }
    }
};

int main() {
    int ts = 10;
    HashTable ht(ts);
    int key, ch = 0;
    string val;
    do {
        cout << "Phone book using HashTable\n1.Add Contact\n2.Search Contact\n3.DeleteContact\n4.View Contact\nenter your choice : " <<endl;
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "enter the phone.no and name " << endl;
                cin >> key >> val;
                ht.insert(key, val);
                cout << endl;
                ht.insert1(key, val);
                break;
            case 2:
                cout << "Enter contact to search : ";
                cin >> key;
                cout << "Value: " << ht.find(key) << endl;
                cout << "\n\t using separate chaining "<<endl;
                cout<< "Value: " << ht.find1(key) << endl;
                break;
            case 3:
                cout << "Enter contact to delete : ";
                cin >> key;
                ht.remove(key);
                cout << "\n\t using separate chaining "<<endl;
                ht.remove1(key);
                break;
            case 4:
                ht.display();
                cout << "\n";
                cout << "\n\t using separate chaining "<<endl;
                ht.display1();
                cout << "\n";
                break;
        }
    } while (ch <= 4);
    return 0;
}
