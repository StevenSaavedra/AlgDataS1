#include <iostream>
#include <vector>
using namespace std;
class HashTable {
 vector<int> table;
 int capacity;
 int size;
public:
 HashTable(int cap = 7) {
 capacity = cap;
 size = 0;
 table.assign(capacity, -1); // -1 = empty
 }
 int hashFunction(int key) {
 return key % capacity;
 }
 void insert(int key){
    int index = hashFunction(key);
    double loadFactor = (double)size / capacity;
    if(loadFactor > 0.7){
        rehash();
    }
    while(true){
        if(table[index]!=-1){
            int k = key+1;
            index = hashFunction(k)%capacity;
        } else{
            table[index] = key;
            break;
        }
    }
    table[index] = key;
    size++;

 }

 bool search(int key) {

    int index = hashFunction(key);
    if(table[index] == key){
        cout << "Found key: " << key << " at index: " << index << endl;
        return true;
    }
    return false;
}
    void rehash(){
        capacity = capacity * 2;
        vector<int> oldTable = table;
        table.clear();
        table.assign(capacity, -1);
        size = 0;
        for(int key : oldTable){
            if(key != -1){
                insert(key);
            }
        }
    }

    void display(){
        for(int i = 0;i<capacity;i++){
            cout << i << " : " << table[i] << endl;
        }
    }
};
int main() {
 cout << "Steven Saavedra"<<endl;
 HashTable ht(7);
 ht.insert(15);
 ht.insert(25);
 ht.insert(35);
 ht.display();
  return 0;
}