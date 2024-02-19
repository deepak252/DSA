#include<bits/stdc++.h>
using namespace std;

class Node{
private: Node* links[26];
    bool flag=false;
public:
    bool containsKey(char c){
        return links[c-'a']!=nullptr;
    }
    void put(char c, Node* node){
        links[c-'a'] = node;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(string s){
        Node* node = root;
        for(char c: s){
            if(!node->containsKey(c)){
                node->put(c, new Node());
            }
            node = node->get(c);
        }
        node->setEnd();
    }

    bool search(string s){
        Node* node = root;
        for(char c: s){
            node = node->get(c);
            if(!node) return false;
        }
        return node->isEnd();
    }
    
    bool startsWith(string s){
        Node* node = root;
        for(char c: s){
            if(!node->containsKey(c)){
                return false;
            }
            node = node->get(c);
        }
        return true;
    }
};

int main(){
    
    Trie trie = Trie();
    string s1 = "hello";
    string s2 = "hii";
    string s3 = "hell";
    trie.insert(s1);
    cout<<"TRIE CONTAINS - "<<endl;
    cout<<s1<<": "<<trie.search(s1)<<endl;
    cout<<s2<<": "<<trie.search(s2)<<endl;
    cout<<s3<<": "<<trie.search(s3)<<endl;
    cout<<"TRIE STARTS WITH - "<<endl;
    cout<<s1<<": "<<trie.startsWith(s1)<<endl;
    cout<<s2<<": "<<trie.startsWith(s2)<<endl;
    cout<<s3<<": "<<trie.startsWith(s3)<<endl;
}