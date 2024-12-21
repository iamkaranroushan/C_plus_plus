#include <iostream>
#include <memory>


struct Node{
    //Node attributes
    int data;
    std::unique_ptr <Node> next;
    Node* previous;
    //Node constructor 
    Node(const int& value):data(value), next(nullptr), previous(nullptr){}
};

class d_linked_list{
    std::unique_ptr<Node> head;
    Node* t_ptr;
    public:
        d_linked_list():head(nullptr), t_ptr(nullptr){}
        
        void insert_at_end(const int& value){
            auto newnode = std::make_unique<Node>(value);
            if(!head){
                head = std::move(newnode);
                t_ptr = head.get();
                return;
            }
            newnode->previous = t_ptr;
            t_ptr->next = std::move(newnode);
            t_ptr = t_ptr->next.get();
        }
        
        void insert_after_node(const int& node, const int& value){
            auto newnode = std::make_unique<Node>(value);
            if(!head){
                head = std::move(newnode);
                t_ptr = head.get();
                return;
            }
            Node* current_ptr = head.get();
            
            while(current_ptr && current_ptr->data != node){
                current_ptr = current_ptr->next.get();
            }
            if(!current_ptr){
                std::cout<<"node not found. Nod insertions occurred. \n";
                return;
            }
            if(!current_ptr->next){
                newnode->previous =  t_ptr;
                t_ptr->next = std::move(newnode);
                t_ptr = newnode.get();
            }else{
                current_ptr->next->previous = newnode.get();
                newnode->next = std::move(current_ptr->next);
                current_ptr->next = std::move(newnode);
                current_ptr->next->previous = current_ptr;
            }

        }
       //forward traversal
        void print(){

            if(!head){
                std::cout<<"list is empty. \n";
                return;
            }

            Node* current_node = head.get();
            
            std::cout<<"forward traversal \n";
            std::cout<<"head->";
            while(current_node){
                std::cout<<current_node->data;
                current_node = current_node->next.get();
                if(current_node){
                    std::cout<<"<->";
                }
            }
            std::cout<<"<-tail \n";
        }
};

int main(){
    d_linked_list list ;
    list.insert_at_end(10);
    list.insert_at_end(20);
    list.insert_at_end(30);
    list.insert_at_end(40);
    list.insert_at_end(50);
    list.print();
    std::cout<<"\n";
    list.insert_after_node(20, 12);
    list.insert_after_node(12, 12);
    list.insert_after_node(10, 12);
    list.print();
    return 0; 
}