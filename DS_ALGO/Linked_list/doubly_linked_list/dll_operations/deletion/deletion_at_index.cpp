#include <iostream>
#include <memory>

struct Node{
    int data;
    std::unique_ptr <Node> next;
    Node* previous;
    Node(const int& value):data(value), next(nullptr), previous(nullptr){};
};
class d_linked_list{
    std::unique_ptr<Node> head;
    Node* t_ptr;
    public:
        d_linked_list():head(nullptr), t_ptr(nullptr){}

        void insert_at_start(const int& value){
            auto newnode = std::make_unique<Node> (value);
            if(!head){
                head = std::move(newnode);
                t_ptr = head.get();
                return;
            }else{
                Node* current_ptr = head.get();
                newnode->next = std::move(head);
                newnode->next->previous = newnode.get();
                head = std::move(newnode);
            }
        }
        void delete_at_index(const int& index){
            if(!head){
                std::cout<<"list is empty. no deletions occurred. \n";
                return;
            }

            // case 1: head node deletion.
            if(index == 0 ){
                std::cout<<head->data<<" is the head and being deleted. \n";
                if(head->next){
                    head->next->previous = nullptr;
                    head = std::move(head->next);
                }else{
                    head = nullptr;
                    t_ptr = nullptr;
                }
            return;
            }

            int counter = 0;
            Node* current_ptr = head.get();
            while(current_ptr && counter!=(index)){

                std::cout<<current_ptr->data<<"\n";
                current_ptr = current_ptr->next.get();
                counter++;
            }

            //case 2: list exhausted, index not found.
            if(!current_ptr){
                // std::cout<<current_ptr->data;
                std::cout<<"out of bounds. Index not found. no deletions. \n";
                return;
            }

            //case 3: last element , deletion at the end.
            if(!current_ptr->next){
                std::cout<<current_ptr->data<<" is being deleted and is the last element\n";
                t_ptr = current_ptr->previous;
                t_ptr->next = nullptr;//updated code.
                return;
            }else{ //case 4: deletion happening in the middle.

                std::cout<<current_ptr->data<<" is being deleted in the middle\n";
                current_ptr->previous->next = std::move(current_ptr->next); //
                current_ptr->previous->next->previous = current_ptr->previous;
            }
        }
        //printing the list forward
        void print(){
            if(!head){
                std::cout<<"list is empty. \n";
                return; 
            }
            Node* current_ptr = head.get();
            std::cout<<"forward traversal \n";
            std::cout<<"head->";
            while(current_ptr){
                std::cout<<current_ptr->data;
                current_ptr = current_ptr->next.get();
                if(current_ptr){
                    std::cout<<"<->";
                }
            }
            std::cout<<"<-tail \n";
        }
};
int main(){
    d_linked_list list;
    list.insert_at_start(10);
    list.insert_at_start(20);
    list.insert_at_start(30);
    list.insert_at_start(40);
    list.insert_at_start(50);
    list.print();
    list.delete_at_index(0);
    list.print();
    list.delete_at_index(1);
    list.print();
    list.delete_at_index(2);
    list.print();
}