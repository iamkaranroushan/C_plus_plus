#include <iostream>
#include <memory>

//defining a node class for holding values and pointer to the next node.
class Node{
    public:
    int data;
    std::unique_ptr<Node> next;

    Node(const int& data):data(data), next(nullptr){}
};

class L_list{
    std::unique_ptr<Node> head;
    public:

        L_list():head(nullptr){};

        void add_node(int data){

            // check if the head is there and take its raw pointer and if head is not present insert a head.
            auto newNode = std::make_unique<Node>(data);//why auto?

            if(!head){
                head =  std::move(newNode);
            }else{
                Node* temp = head.get();
                while(temp->next){
                    temp = temp->next.get();
                }
                temp->next = std::move(newNode);
            }
        }

        void printList(){
            Node* temp = head.get();
            while(temp){
                std::cout<<temp->data<<"->";
                temp = temp->next.get();
            }
            std::cout<<"nullptr";
        }
};

int main(){
    L_list linked_list;
    linked_list.add_node(1);
    linked_list.add_node(10);
    linked_list.add_node(13);
    linked_list.add_node(24);
    linked_list.add_node(54);
    linked_list.add_node(21);
    linked_list.add_node(50);

    linked_list.printList();
    return 0;
}