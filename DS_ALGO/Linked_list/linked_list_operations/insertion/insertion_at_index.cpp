#include <iostream>
#include <memory>

struct Node{
    int data;
    std::unique_ptr<Node> next;
    Node(const int& value):data(value), next(nullptr){}
};

class Linked_list{
    std::unique_ptr<Node> head;
    public:
        Linked_list():head(nullptr){}
        void insert_at_end(const int& value){
            auto new_node = std::make_unique<Node>(value);
            if(!head){
                head = std::move(new_node);
            }
            Node* raw_ptr = head.get();
            while(raw_ptr->next){
                raw_ptr = raw_ptr->next.get();
            }
            raw_ptr->next = std::move(new_node);
        }
        void insert_at_idx(const int& idx, const int& value){
            auto new_node = std::make_unique<Node>(value);
            
            if(idx == 0){
                new_node->next = std::move(head);   
                head = std::move(new_node);   
                std::cout<<"inserted "<<value<< " at index "<<idx<<std::endl; 
            }
            Node* raw_ptr = head.get();
            int count = 0;
            //first search for desired index
            while(raw_ptr && count != (idx-1)){
                raw_ptr = raw_ptr->next.get();
                count++;
            }
            if(raw_ptr){
                new_node->next = std::move(raw_ptr->next);
                raw_ptr->next = std::move(new_node);
                std::cout<<"inserted "<<value<< " at index "<<idx<<std::endl; 
            }else{
                std::cout<<"index "<<idx<<" is out of bounds. No insertions made."<<std::endl;
            }

        }
        void print(){
            Node* raw_ptr = head.get();
            std::cout<<"----------------------------------"<<std::endl;
            while(raw_ptr){
                std::cout<<raw_ptr->data<<"->";
                raw_ptr = raw_ptr->next.get();
            }
            std::cout<<"nullptr"<<std::endl;
            std::cout<<"----------------------------------"<<std::endl;
            std::cout<<"\n";
        }
};

int main(){
    Linked_list list;
    list.insert_at_end(5);
    list.insert_at_end(10);
    list.insert_at_end(20);
    list.insert_at_end(30);
    list.insert_at_end(40);
    list.print();
    
    list.insert_at_idx(1,21);
    list.print();
    // std::cout<<"\n";
    // list.insert_at_idx(4,13);
    // list.print();
    // std::cout<<"\n";
    // list.insert_at_idx(6,13);
    // list.print();
    // std::cout<<"\n";
    list.insert_at_idx(2,13);
    list.print();
    // std::cout<<"\n";
}