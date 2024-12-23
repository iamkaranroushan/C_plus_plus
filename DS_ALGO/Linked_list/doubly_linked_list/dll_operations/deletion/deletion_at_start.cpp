#include <iostream>
#include <memory>


struct Node{
    int data;
    std::unique_ptr<Node> next;
    Node* previous;
    Node(const int& value):data(value), next(nullptr), previous(nullptr){}
};

class d_linked_list{
    std::unique_ptr<Node> head;
    Node* t_ptr;
    public:
        d_linked_list():head(nullptr), t_ptr(nullptr){};
        void insert_at_end(const int& value){
            auto newnode = std::make_unique<Node> (value);
            if(!head){
                head = std::move(newnode);
                t_ptr = head.get();
                return;
            }
            newnode->previous = t_ptr;
            t_ptr->next = std::move(newnode);
            t_ptr = t_ptr->next.get();
        };
        void delete_at_head(){
            if(!head){
                std::cout<<"list empty.\n";
                return;
            }

            if(!head->next){
                head = nullptr;
                t_ptr = nullptr;
                std::cout<<"head deleted. Now list is empty. \n";
                return;
            }
            std::cout<<"head: "<<head->data<<" is deleted. \n";
            head->next->previous = nullptr;
            head = std::move(head->next);
        };
        void print(){
            if(!head){
                std::cout<<"[].\n";
                return;
            }
            Node* current = head.get();
            std::cout<<"head->";
            while (current){
                std::cout<<current->data;
                current =current->next.get();
                if(current){
                    std::cout<<"<->";
                }
            }
                std::cout<<"<-tail. \n";
        };
        ~d_linked_list(){};
};

int main(){
    d_linked_list list;
    list.insert_at_end(12);
    list.insert_at_end(19);
    list.insert_at_end(13);
    list.insert_at_end(11);
    list.print();
    list.delete_at_head();
    list.print();
    list.delete_at_head();
    list.print();
    list.delete_at_head();
    list.print();
    list.delete_at_head();
    list.print();
    list.delete_at_head();
    list.print();
    return 0;
}

