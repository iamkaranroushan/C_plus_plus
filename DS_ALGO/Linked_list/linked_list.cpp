#include <iostream>
#include <memory>

//this is a node data type(user defined data type.)
//we connect one node to another.
struct Node{
    //stored data
    int data;
    //pointer to next node
    std::unique_ptr <Node> next;
    //initially when the node is made it has a value and the next pointer points to a nullptr.
    Node(const int& data): data(data), next(nullptr){}
};

// now we try to connect the nodes. 
// 1. from the end:
class Linkedlist{
    std::unique_ptr<Node> head;
    public:
        Linkedlist():head(nullptr){};
        void insert_at_end(const int& value){
            //we make a node;
            auto newNode = std::make_unique <Node>(value);

            //we try to find the end of the head :
            //case 1:
            //if the head is originally empty, means it is the only node and it points to null
            //so we check if there is no value in the head; we make the newnode head.

            if(!head){
                head = std::move(newNode);
            }

            //case 2:
            //if the head is already have value and maybe it has many nodes in that case,
            //we check if the next node is null or not if it is null then we make the next of our head newnode 
            //for that we use a raw pointer to access the values at the node.

            Node* raw_ptr = head.get();

            while(raw_ptr->next){
                raw_ptr = raw_ptr->next.get();
            }
            //after the loop ends we are sure that the next points to a nullptr means we got the last node 
            //so we insert our newNode at that node
            raw_ptr->next = std::move(newNode);
        }
        void print(){
            //printing the  node if it has a valid head.
            Node* raw_ptr = head.get();
            while(raw_ptr){
                std::cout<<raw_ptr->data<<"->";
                raw_ptr = raw_ptr->next.get();
            }
            std::cout<<"nullptr";
        }
};


int main(){
    Linkedlist list;
    list.insert_at_end(1);
    list.insert_at_end(3);
    list.insert_at_end(7);
    list.insert_at_end(8);
    list.insert_at_end(2);
    list.print();
}
