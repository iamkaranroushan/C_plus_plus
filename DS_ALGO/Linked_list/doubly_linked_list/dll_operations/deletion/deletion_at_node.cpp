#include <iostream>
#include <memory>



struct Node{
    int data;
    std::unique_ptr<Node> next;
    Node* previous;

    Node(const int& value): data(value), next(nullptr), previous(nullptr){}
};

class d_linked_list{
    std::unique_ptr<Node> head;
    Node* t_ptr;
    public:
       
        d_linked_list():head(nullptr), t_ptr(nullptr){}
        
       
        void delete_at_node(const int& node_value){
            if(!head){
                std::cout<<"list is empty. \n ";
                return;
            }

            //case 1: value at head. delete head.
            if(head->data == node_value){
                //only one node exists.
                if(!head->next){
                    head = nullptr;
                    t_ptr = nullptr;
                    std::cout<<"node "<<node_value<<" deleted.\n";
                }else{//more than one node exists.
                    head->next->previous = nullptr;
                    head = std::move(head->next);
                    std::cout<<"node "<<node_value<<" deleted.\n";
                }
                return;
            }

            Node* current = head.get();
            while(current && current->data != node_value){
                current = current->next.get();
            }
            //case 2: current is null , end of the list.
            if(!current){
                std::cout<<"Node "<<node_value<<" not found. Deletion not occurred.\n";
                return;
            }
            // case 3: last index of the node. 
            if(!current->next){
                t_ptr = current->previous;
                t_ptr->next = nullptr; 
                std::cout<<"node "<<node_value<<" deleted.\n";
                return;
            }
            //case 4: deletion in the middle of node
            current->previous->next = std::move(current->next);
            current->previous->next->previous = current->previous;
            std::cout<<"node "<<node_value<<" deleted.\n";
        }
        void insert_at_end(const int& value){
            auto newnode = std::make_unique<Node>(value);
            //no head make the newnode new head and t_ptr points to head;
            if(!head){
                head = std::move(newnode);
                t_ptr = head.get(); 
                return;
            }
            newnode->previous = t_ptr;
            t_ptr->next = std::move(newnode);
            t_ptr = t_ptr->next.get();
        }
        void print(){
            if(!head){
                std::cout<<"list is empty. \n";
                return;
            }
            Node* current_ptr = head.get();
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
    list.insert_at_end(12);
    list.insert_at_end(42);
    list.insert_at_end(14);
    list.insert_at_end(20);
    list.insert_at_end(25);
    list.insert_at_end(100);
    list.insert_at_end(9);
    list.print();
    std::cout<<"\n";
    list.delete_at_node(43);
    list.print();
    std::cout<<"\n";
    list.delete_at_node(42);
    list.print();
    std::cout<<"\n";
    list.delete_at_node(25);
    list.print();
}