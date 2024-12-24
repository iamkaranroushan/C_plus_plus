#include <iostream>
#include <memory>


struct Node{
    int data;
    std::shared_ptr<Node> next;
    Node(const int& value):data(value),next(nullptr){}
};

class C_S_linked_list{
private:
    std::shared_ptr<Node> head;
public:
    C_S_linked_list():head(nullptr){};
    void insert_at_end(const int& value){
        auto newnode = std::make_shared<Node> (value);
        if(!head){
            head = newnode;
            head->next = head;
            return;
        }
        std::shared_ptr<Node> current = head;
        while(current->next != head){
            current = current->next;
        }

        current->next = newnode;
        newnode->next = head;
        
    } 
    void print(){
        if(!head){
            std::cout<<"[null]\n";
            return;
        }
        std::shared_ptr<Node> current = head;
        std::cout<<"head->";
        do{
            std::cout << current->data << "->";
            current = current->next;
        }while (current != head) ;
        
        std::cout<<"head\n";
    }
};

int main(){
    
    C_S_linked_list list;
    
    list.insert_at_end(10);
    list.insert_at_end(12);
    list.insert_at_end(14);
    list.insert_at_end(20);
    
    list.print();
    
    return 0;
}
