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

    void insert_at_index(const int& value, const int& index){
        auto new_node = std::make_unique<Node>(value);  
        int count = 0;
        if(count == index){//insert at head;
            new_node->next = std::move(head);
            if(new_node->next){//do this if there is a node exists. 
                new_node->next->previous = new_node.get();
            }else{//if inserted node is the only node. update the tail pointer. 
                t_ptr = new_node.get();
            }
            head = std::move(new_node);
            return;
        }
        Node* current = head.get();
        
        while(current && count!=(index-1)){
            current = current->next.get();
            count++;
        }
        if(!current){
            std::cout<<"index "<< index<<" is out of range. No insertion occurred."<<std::endl;
            return;
        }

        //insert at the end.
        if(!current->next){
            new_node->previous = t_ptr;
            t_ptr->next = std::move(new_node);
            t_ptr = t_ptr->next.get();
            return;
        }

        //insert at the middle.
        current->next->previous = new_node.get();//10->20->previous = new_node(non_owning reference) (15<-20)
        new_node->next = std::move(current->next);//(15->20); so far (15<->20)
        current->next = std::move(new_node);//10->next = new_node(ownership)=(10->15<->20)
        current->next->previous = current;//10->next = 15->previous = current =10 ,so far (10 <->15 <->20)
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

};
int main(){
    d_linked_list list ;
    list.insert_at_index(10,0);
    list.insert_at_index(12,1);
    list.insert_at_index(20,2);
    list.insert_at_index(30,3);
    list.insert_at_index(78,4);


    list.print_forward();
    std::cout<<"\n";
    list.print_backward();

    list.insert_at_index(65,11);

    list.print_forward();
    std::cout<<"\n";
    list.print_backward();
}