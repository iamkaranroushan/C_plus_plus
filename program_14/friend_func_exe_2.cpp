#include <iostream>
#include <vector>
#include <string>
#include <set>
class Secret_Vault{
    private:
        std::set<std::string> royal_vault;
    public:
        Secret_Vault(){
            royal_vault.insert("Golden sword");
            royal_vault.insert("Crown of mystery");
            royal_vault.insert("Glistering light of wings");
            royal_vault.insert("Sacred water");
            royal_vault.insert("Golden dust");
        };
        friend void key_holder(Secret_Vault& vault,const std::string& request);
        // friend void key_holder(std::string& treasure);

        void addTreasure(const std::string& treasure){
            royal_vault.insert(treasure);
        }
      
};

void key_holder( Secret_Vault& vault,const std::string& request){
    
    std::cout<<"\nkeyholder opening the vault.\n"<<std::endl;
    
    if(request=="Inventory"){
        //give the inventory overlook.
        std::cout<<"All accessible treasures "<<std::endl;
        std::cout<<"---------------------------- "<<std::endl;

        for(std::string t: vault.royal_vault){
            std::cout<<"---"<<t<<std::endl;
        }
    }else{

        std::cout<<"-------------------------------------------- "<<std::endl;
        std::cout<<"--keyholder is requested the "<<request<<"--"<<std::endl;
        std::cout<<"-------------------------------------------- "<<std::endl;

        if(request == "Golden dust" || request == "Sacred water"){

            for(std::string t: vault.royal_vault){
                
                if(t==request){
                    //give the treasure.
                    std::cout<<t<<" given. "<<std::endl;
                } 
            }
        }else{
            std::cout<<request<<" is a most valuable treasure and cannot be given. \n"<<std::endl;
        }

    }
}
// overloaded friend function to add the treasure to the royal vault too.

void key_holder( Secret_Vault& vault, const std:: string& request, const std::string& treasure){
    
    if(request=="add"){
        vault.addTreasure(treasure);
        std::cout<<"\n"<<treasure<<" added to the royal vault. \n"<<std::endl;
    }
}   

int main(){
    Secret_Vault royalVault;
  
    key_holder(royalVault, "Inventory");
    key_holder(royalVault, "Golden dust");
    key_holder(royalVault, "Crown of mystery");
    key_holder(royalVault, "add", "Mirror of victory");
    
    key_holder(royalVault, "Inventory");

    return 0;
}