#include <iostream>
#include <memory>

//doubly linked list have three parts.
//data.
//pointer to previous node.
//pointer to next node. 
struct Node{
    int data;
    std::unique_ptr<Node> next;
    Node* previous;
    //node constructor.
    Node(const int& value):data(value), previous(nullptr), next(nullptr){}
};
class D_linked_list{
    std::unique_ptr<Node> head;
    Node* t_ptr;//this is the tail node.
    public:
        D_linked_list():head(nullptr), t_ptr(nullptr){};

        void insert_at_begining(const int& value){
            auto new_node = std::make_unique<Node>(value);
            // Node* raw_ptr = head.get();
            if(!head){
                head = std::move(new_node);
                t_ptr = head.get();
                return;
            }else{
                //head reference(tail)
                new_node->previous = t_ptr;

                //put newnode at the next position of the head (tail->next)
                t_ptr->next = std::move(new_node);
                //keep the reference of new node in the tail (new_node <- tail)
                t_ptr = t_ptr->next.get();
            }
        }
        void print_backward(){
            if(!t_ptr){
                std::cout<<"empty list.";
                return;
            }
            std::cout<<"list backwards.\n";
            Node* tail_ptr = t_ptr;
            std::cout<<"tail->";
            while(tail_ptr){
                std::cout<<tail_ptr->data;
                tail_ptr = tail_ptr->previous;
                if(tail_ptr){
                    std::cout<<"<->";
                }
            }
            std::cout<<"<-head"<<std::endl;
        }
        void print_forward(){
            if(!head){
                std::cout<<"empty list.";
                return;
            }
            std::cout<<"list forward.\n";
            std::cout<<"head->";
            Node* raw_ptr = head.get();
            while(raw_ptr){
                std::cout<<raw_ptr->data;
                raw_ptr = raw_ptr->next.get();
                if(raw_ptr){
                    std::cout<<"<->";
                }
            }
            std::cout<<"<-tail";
        }
};
int main(){
    D_linked_list list;

    list.insert_at_begining(0);
    list.insert_at_begining(10);
    list.insert_at_begining(20);
    list.insert_at_begining(30);
    // list.insert_at_begining(40);
    list.print_forward();
    std::cout<<std::endl;
    list.print_backward();

    
    return 0; 
}