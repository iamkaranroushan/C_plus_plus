#include <iostream>
#include <memory>


struct Node{
    int data;
    std::shared_ptr<Node> next;
    Node(const int& value):data(value), next(nullptr){};
};

class c_s_linked_list{
    std::shared_ptr<Node> head;
    public:
        c_s_linked_list():head(nullptr){}

        void insert_after_node(const int& node, const int& value){
            auto newnode = std::make_shared<Node> (value);
            if(!head){
                std::cout<<"list is empty,cannot insert \n";
                return;
            }
            std::shared_ptr<Node> current = head;
            
            //middle case
            while(current->next != head && current->data != node ){
                current = current->next;
            }
            if(current->next == head && current->data != node ){
                std::cout<<"node "<<node<<" not found\n";
                return;
            }
            // start node is the value node and next nodes exists.
            if(current->next != head ){
                std::cout<<"node "<<value<<" inserted after " <<current->data<<"\n";
                newnode->next = current->next;
                current->next = newnode;
            }//only node exists 
            else{
                std::cout<<"node "<<value<<" inserted after " <<current->data<<"\n";
                current->next = newnode;
                newnode->next = head;
            }
        }
        void insert_at_end(const int& value){
            auto newnode = std::make_shared<Node>(value);
            if(!head){
                head = newnode;
                head->next = head;
                return;
            }
            std::shared_ptr<Node> current= head;
            while(current->next != head){
                current= current->next;
            }
            current->next = newnode;
            newnode->next = head;
        }
        void print(){
            if(!head){
                std::cout<<"list is empty.\n";
                return;
            }
            std::shared_ptr<Node> current = head;
            std::cout<<"head->";
            do
            {
                std::cout<<current->data<<"->";
                current = current->next;
            } while(current != head);
            std::cout<<"head \n";
        }
};
int main(){
    
    c_s_linked_list list;
    // list.insert_at_end(20);
    // list.insert_at_end(40);
    // list.insert_at_end(12);
    // list.insert_at_end(14);
    // list.print();
    list.insert_after_node(20,10);
    list.print();
    list.insert_after_node(14,20);
    list.print();
    list.insert_after_node(13,20);
    list.print();
    
    return 0;
}