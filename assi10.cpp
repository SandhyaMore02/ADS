#include <iostream>
#include <list>
using namespace std;

class HashNode {
public:
    int key;
    string value;
    HashNode(int key, string value) {
        this->key = key;
        this->value = value;
    }
};

class Dictionary {
private:
    list<HashNode> *table;
    int capacity;

    // Hash func
    int getHashIndex(int key) {
        int hash = key % capacity;
        cout << "Hash address for key " << key << " is: " << hash << endl;
        return hash;
    }

public:
    Dictionary(int cap = 7) {
        capacity = cap;
        table = new list<HashNode>[capacity];
    }

    void insert(int key, string value) {
        int index = getHashIndex(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                it->value = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    bool find(int key) {
        int index = getHashIndex(key);
        for (auto &node : table[index]) {
            if (node.key == key) {
                cout << "Key: " << node.key << ", Value: " << node.value << endl;
                return true;
            }
        }
        return false;
    }

    void deleteKey(int key) {
        int index = getHashIndex(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                table[index].erase(it);
                return;
            }
        }
    }

    void display() {
        for (int i = 0; i < capacity; ++i) {
            cout << "Index " << i << ": ";
            bool first = true;
            for (auto &node : table[i]) {
                if (!first) {
                    cout << " -> ";
                }
                cout << "(" << node.key << ", " << node.value << ")";
                first = false;
            }
            cout << endl;
        }
    }

    ~Dictionary() {
        delete[] table;
    }
};

int main() {
    Dictionary dict;
    int choice;
    int key;
    string value;
    int cap = 7;
    cout << "\nTable size: " << cap;
    do {
        cout << "\nMenu\n1. Insert a Key\n2. Find a Key\n3. Delete a Key\n4. Display Hash Table\n5. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                dict.insert(key, value);
                break;
            case 2:
                cout << "Enter key to find: ";
                cin >> key;
                if (!dict.find(key))
                    cout << "Key not found." << endl;
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                dict.deleteKey(key);
                cout << "Key deleted successfully." << endl;
                break;
            case 4:
                dict.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (true);
    return 0;
}
