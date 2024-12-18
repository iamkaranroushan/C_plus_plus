#include <iostream>
#include <memory>

//node formation.
struct Node{
    int data;
    std::unique_ptr <Node> next;
    Node(const int& value):data(value), next(nullptr){};
};

class Linked_list{
    std::unique_ptr<Node> head;
    public:
        Linked_list():head(nullptr){};
        
        void insert_at_begining(const int& value){
            auto newNode = std::make_unique<Node>(value);
            newNode->next = std::move(head);
            head = std::move(newNode);
        }
        void print(){
            Node* raw_ptr = head.get();
            while(raw_ptr){
                std::cout<<raw_ptr->data<<"->";
                raw_ptr = raw_ptr->next.get();
            }
            std::cout<<"nullptr";
        }
};

int main(){
    Linked_list list;
    list.insert_at_begining(50);
    list.insert_at_begining(40);
    list.insert_at_begining(30);
    list.insert_at_begining(20);
    list.insert_at_begining(10);
    list.print();
    return 0;
}