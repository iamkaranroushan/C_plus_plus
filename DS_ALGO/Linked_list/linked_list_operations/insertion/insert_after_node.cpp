#include <iostream>
#include <memory>

//node formation.
struct Node{
    int data;
    std::unique_ptr <Node> next;
    Node(const int& value):data(value), next(nullptr){};
};

class Linked_list{
    public:
        std::unique_ptr<Node> head;

        Linked_list():head(nullptr){};

        void insert_at_begining(const int& value){
            auto newNode = std::make_unique<Node>(value);
            newNode->next = std::move(head);
            head = std::move(newNode);
        }
        
        void insert_after_node(const int& target, const int& value){
            //given a target ; we first find the target exists in the list.
            //we take the raw pointer of head
            Node* raw_ptr = head.get();
            while (raw_ptr && raw_ptr->data != target){
                raw_ptr = raw_ptr->next.get();
            }

            if(raw_ptr){
                auto newnode = std::make_unique<Node>(value);
                newnode->next = std::move(raw_ptr->next);
                raw_ptr->next = std::move(newnode);
            }else{
                std::cout<<"target node doesnot exist.";
            }
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
    list.insert_at_begining(40);
    list.insert_at_begining(30);
    list.insert_at_begining(20);
    list.insert_at_begining(10);
    list.print();

    std::cout<<std::endl;
    list.insert_after_node(30, 50);
    list.print();

    return 0;
}