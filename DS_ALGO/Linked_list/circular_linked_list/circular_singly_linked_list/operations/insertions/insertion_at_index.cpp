#include <iostream>
#include <memory>


struct Node{
    int data;
    std::shared_ptr<Node> next;
    Node (const int& value):data(value), next(nullptr){};
};
class c_s_linked_list{
    std::shared_ptr<Node> head;
    public:
        c_s_linked_list():head(nullptr){};
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
        void insert_at_index(const int& index, const int& value){
            auto newnode = std::make_shared<Node>(value);
            
            if(!head){
                std::cout<<"list is empty. cannot insert the element. \n";
                return;
            }

            int counter = 0;
            std::shared_ptr<Node> current = head;

            //insert at the head node.  
            if(counter == index){
                //traverser through the whole list and then put the newnode at the head position.
                while(current->next != head){
                    current = current->next;
                }
                newnode->next = current->next;
                head = newnode;
                current->next = head;
                std::cout<<value<<" inserted at index "<<index<<std::endl;
                return;
            }
            
            //traverse the list to find the index-1;and insert after the current ;
            while(current->next != head && counter != (index-1)){
                current = current->next;
                counter++;
                std::cout<< counter <<"\n";
            }
            if(current->next == head){
                std::cout<<"index "<<index<<" out of bounds. cannot insert the element. \n";
                return;
            }
            //middle insertion
            newnode->next = current->next;
            current->next = newnode;
            std::cout<<value<<" inserted at index "<<index<<std::endl;

        }
        
        void print(){
            if(!head){
                std::cout<<"list is empty.\n";
                return;
            }
            std::shared_ptr<Node> current = head;
            std::cout<<"head->";
            do
            {
                std::cout<<current->data<<"->";
                current = current->next;
            } while(current != head);
            std::cout<<"head \n";
        }

};

int main(){
    c_s_linked_list list;
    list.print();
    list.insert_at_end(23);
    list.insert_at_end(32);
    list.insert_at_end(76);
    list.insert_at_end(12);
    list.print();
    std::cout<<"\n";
    list.insert_at_index(0,45);
    list.print();
    std::cout<<"\n";
    list.insert_at_index(4,21);
    list.print();
    std::cout<<"\n";
    list.insert_at_index(6,32);
    list.print();
    std::cout<<"\n";
    list.insert_at_index(10,10);
    list.print();
    std::cout<<"\n";
}
