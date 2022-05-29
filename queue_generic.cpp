#include<iostream>
#define MAX_SIZE 1000
using namespace std;

template <class T>
class Node{
    public: 
        T val;
        Node* next;
        Node(){};
        Node(T value){
            this->val = value;
        };
};

template <class T>
class Queue{
    Node<T>  *head;
    Node<T> *curr;
    public:
        Queue(){
            head = nullptr;
            curr = nullptr;
        };
        void enqueue(T value){
            Node<T> *newNode = new Node<T>(value);
            if(head==nullptr){
                head = curr = newNode;
                return;
            }
            curr->next = newNode;
            curr = newNode;
        };

        T dequeue(){
            if(head==nullptr) return 0;
            Node<T> *temp = head;
            T val = head->val;
            if(head==curr){
                head = curr = nullptr;
            }else{
                head = head->next;
            }
            delete temp;
            return  val;
        };
        T front(){
            if(head==nullptr) return 0 ;
            return head->val;
        };
        bool isEmpty(){
            return head==nullptr;
        };

};

int main(){
    Queue<int> q;
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);

    while(!q.isEmpty()){
        cout<<q.dequeue()<<" ";
    }
    cout<<endl;
}