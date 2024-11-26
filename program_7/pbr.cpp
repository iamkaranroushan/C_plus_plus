#include <iostream>
#include <string>

using namespace std;

// Function prototype for passByRef, which takes a reference to a string as an argument
void passByRef(string &value);

int main() {
    // Declare a string variable 'name' and initialize it to an empty string
    string name = "";
    
    // Call the passByRef function with 'name' as an argument.
    // Since 'name' is passed by reference, changes made in the function will affect 'name' directly
    passByRef(name);
    
    // Output the updated value of 'name' after the function call
    cout << "Name is now updated, and the value is: " << name << endl;
    return 0;
}

// Function definition for passByRef
// This function takes a string reference 'value' and modifies it
void passByRef(string &value) {
    // Concatenate "updated " with the current value of 'value' and store the result back in 'value'
    value = "updated " + value;
    
    // Output the modified value to show the change within the function
    cout << "The updated value inside passByRef is: " << value << endl;
}
