#include <iostream>
#include <memory>

struct Node{
    int data;
    std::shared_ptr<Node> next;
    Node(const int& value):data(value),next(nullptr){};
};

class c_s_linked_list{
    std::shared_ptr<Node> head;
    public:
        c_s_linked_list():head(nullptr){};
        void insert_at_end(const int& value){
            auto newnode = std::make_shared<Node> (value);
            if(!head){
                head = newnode;
                newnode->next = head;
                std::cout<<value<<" inserted at head.\n";
                return;
            }
            auto current = head;
            while(current->next != head){
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
            std::cout<<value<<" inserted at the back.\n";
        }
        
        void delete_at_index(const int& index){
            if(!head){
                std::cout<<" list is empty. deletion not occurred. \n";
                return;
            }

            int counter = 0;
            auto current = head;

            //deletion at the head.
            if(counter == index){        
                if(current->next == head){
                    head = nullptr;
                    std::cout<<"deleted at the head. \n";
                }else {
                    while(current->next != head){
                        current = current->next;
                    }
                    head = current->next->next;
                    current->next = head;
                    std::cout<<"deleted at the head. \n";
                }
                return;
            }

            while(current->next != head && counter != (index-1)){
                current = current->next;
                counter++;
            }

            //out of bound.
            if(current->next == head ||  counter != (index - 1)){
                std::cout<< "Index "<<index <<" out of bounds, deletion not occurred. \n";
                return;
            }
            //deletion in the middle.
            std::cout<<current->next->data<<" deleted at "<<index<<" \n";
            current->next = current->next->next;

        };
        void print(){
            if(!head){
                std::cout<<"list is empty. \n";
                return;
            }
            auto current = head;
            std::cout<<"head->";
            do{
                std::cout<<current->data<<"->";
                current = current->next;
            }while(current != head);
            std::cout<<"head\n";
        }
};

int main(){
    c_s_linked_list list;
    list.insert_at_end(12);
    list.insert_at_end(11);
    list.insert_at_end(16);
    list.insert_at_end(13);
    list.insert_at_end(14);
    list.print();
    list.delete_at_index(2);
    list.print();
    list.delete_at_index(6);
    list.print();
    list.delete_at_index(0);
    list.print();
    list.delete_at_index(2);
    list.print();
    list.delete_at_index(1);
    list.print();
    list.delete_at_index(10);
    list.print();
    list.delete_at_index(0);
    list.print();
    // list.insert_at_end(13);
    // list.print();
    // list.insert_at_end(11);
    // list.print();
    // list.insert_at_end(12);
    // list.print();
    return 0;
}