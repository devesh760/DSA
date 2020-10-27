#include <iostream>
using namespace std;

class hashTable{
private:
    struct Node{
        string strData;
        int data;
        Node *next;
        Node(string val1,int val2):strData(val1),data(val2),next(nullptr){}
    };
    Node *arr[10];
public:
    hashTable(){
        for(int i=0;i<10;++i)
            arr[i] = nullptr;
    }
    void set(string,int);
    int get(string);
    int getHashKey(string);
    Node* operator[](int);
};

int hashTable::getHashKey(string str)
{
    int sum = 0;
    for (int i = 0; i < str.size(); ++i){
        sum += str[i];
    }
    return sum % 10;
}
void hashTable::set(string key,int data){
    int index = getHashKey(key);
    Node *newNode  = new Node(key,data);
    if(arr[index]==nullptr)
        arr[index] = newNode;
    else{
        Node *temp=arr[index];
        while(temp->next!=nullptr)
            temp=temp->next;
        temp->next = newNode;
    }
}
int hashTable::get(string key){
    int index = getHashKey(key);
    Node * temp = arr[index];
    while(temp!=nullptr && temp->strData != key)
        temp = temp->next;
    if(temp==nullptr)
        return -1;
    else
        return temp->data;
}
int main(){
    hashTable obj;
    obj.set("abc",23);
    obj.set("cba",24);
    obj.set("bca",22);
    cout << obj.get("abc");
    cout << obj.get("bca");
    cout <<  obj.get("cba");
       return 0;
}