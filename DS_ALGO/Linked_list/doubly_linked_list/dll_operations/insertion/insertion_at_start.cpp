#include <iostream>
#include <memory>

struct Node{
    int data;
    std::unique_ptr<Node> next;
    Node* previous;
    public:
        Node(const int& value):data(value), next(nullptr), previous(nullptr){}
};

class d_linked_list{
    std::unique_ptr <Node> head;
    Node* t_ptr;
    public:
    d_linked_list():head(nullptr), t_ptr(nullptr){}

    void insert_at_front(const int& value){
        auto new_node = std::make_unique<Node>(value);  
        if(!head){
            head = std::move(new_node);
            t_ptr = head.get();
            return;
        }
        new_node->next = std::move(head);
        new_node->next->previous = new_node.get();
        head = std::move(new_node);
    }

    void print_forward(){
        if(!head){
            std::cout<<"list is empty.";
            return;
        }
        Node* raw_ptr = head.get();

        std::cout<<"forward traversal:"<<std::endl;

        std::cout<<"head->";
        while(raw_ptr){
            std::cout<<raw_ptr->data;
            raw_ptr = raw_ptr->next.get();
            if(raw_ptr){
                std::cout<<"<->";
            }
        }
                std::cout<<"<-tail";
        
    }
    void print_backward(){
        if(!t_ptr){
            std::cout<<"list is empty.";
            return;
        }
        std::cout<<"backward traversal:"<<std::endl;

        std::cout<<"tail->";
        while(t_ptr){
            std::cout<<t_ptr->data;
            t_ptr = t_ptr->previous;
            if(t_ptr){
                std::cout<<"<->";
            }
        }
        std::cout<<"<-head"<<std::endl;
        
    }

};
int main(){
    d_linked_list list ;

    list.insert_at_front(10);
    list.insert_at_front(12);
    list.insert_at_front(20);
    list.insert_at_front(30);

    list.print_forward();
    std::cout<<"\n";
    list.print_backward();

}