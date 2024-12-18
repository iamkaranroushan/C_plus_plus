#include <iostream>
#include <memory>


struct Node{
    int data;
    std::unique_ptr<Node> next;
    Node(const int& value):data(value){};
};

class Linked_list{
    std::unique_ptr <Node> head;
    public:
        Linked_list():head(nullptr){};

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
  
        void delete_at_end(){

            if(!head){
                std::cout<<"list is empty."<<std::endl;
                return;
            }
            if(!head->next){
                head = nullptr;
                return;
            }
            Node* raw_ptr = head.get();
            while(raw_ptr->next->next){
                raw_ptr = raw_ptr->next.get();
            }
            
            raw_ptr->next = nullptr;
            // raw_ptr->next->next = nullptr;
        }
    
        void print(){
            Node* raw_ptr = head.get();
                std::cout<<"----------------------------------"<<std::endl;
            while(raw_ptr){
                if(raw_ptr){
                    std::cout<<raw_ptr->data<<"->";
                    raw_ptr = raw_ptr->next.get();
                }
                if(!raw_ptr){
                    std::cout<<"NULL \n";
                    std::cout<<"----------------------------------"<<std::endl;
                    std::cout<<"\n";
                }
            }
        
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
    list.delete_at_end();//removes 40
    list.print();
    list.delete_at_end();//removes 30
    list.print();
    list.delete_at_end();//removes 20
    list.print();
    list.delete_at_end();//removes 10
    list.print();
    list.delete_at_end();//removes 5
    list.print();
    list.delete_at_end();
    list.print();
    list.delete_at_end();
    list.print();
    
}