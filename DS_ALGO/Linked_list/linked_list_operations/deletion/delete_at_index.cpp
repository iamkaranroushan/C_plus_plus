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
  
        void delete_at_idx(const int& index){
            if(index < 0 || !head){
                std::cout<<"list is empty or invalid position"<<std::endl;
            }
            Node* raw_ptr = head.get();

            //deletion at start.
            if(raw_ptr && index == 0){
                head = std::move(raw_ptr->next);
                return;
            }
            //index > 0 ;
            int count = 0;
            while(raw_ptr && count != (index-1)){
                raw_ptr = raw_ptr->next.get();
                count++;
            }
            if(!raw_ptr){
                std::cout<<index<<" is not a valid index. Deletion not occurred."<<std::endl;
                return;
            }
            raw_ptr->next = std::move(raw_ptr->next->next);
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
    list.print();//5->10->20->30->40->nullptr

    list.delete_at_idx(3);
    list.print();//5->10->20->40->nullptr

    list.delete_at_idx(0);
    list.print();//10->20->40->nullptr

    list.delete_at_idx(7);
    list.print();// 7 is not a valid index. Deletion not occurred. 10->20->40->NULL
    
    list.delete_at_idx(2);
    list.print();//10->20->NULL
}