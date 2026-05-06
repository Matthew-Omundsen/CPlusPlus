/*
    Name: Matthew Omundsen	
    Date: 9/8/25
    Desc: Homework 3
*/
#include <iostream>

using namespace std;

struct node_t{
    int data;
    node_t* next;
};

// Adds the value on the end of the linked list starting from node.
void push_back(int value, node_t* node){ // should be int instead of int*
    if(!node)return;
    // Walk to end
    while(node->next){
        node = node->next;
    }
    // put a node on the end
    node->next = new node_t;
    node->next->data = value; // should equal value instead of 0
    node->next->next = NULL;
}

// Prints the linked list starting from node.
void print(node_t* node){
    // Walk the list and print
    while(node->next){
        cout << node->data << " ";
        node = node->next;
    }
    cout << node -> data << endl; 
}

// Add value to every element of the linked list.
void add(node_t* node, int value){ // should be int instead of int*
    while(node->next){
        node->data += value; // should be addition not multiplication
        node = node->next;
    }
	node->data += value;
}

// Returns a new linked list, based on one starting with node, but in the reverse
// order.
node_t* reverse(node_t* node){
    if(!node)return NULL;
    // Walk down the good linked list
    node_t* last = NULL;
    while(node != NULL){
        node_t* temp = new node_t;
        temp->data = node->data;
        temp->next = last;
        node = node->next;
        last = temp;
    }
    return last;
}

void freeMem(node_t* node){
    while (node != NULL) {
        node_t* temp = node;
        node = node->next;
        delete temp;
    }
}

bool is_present(node_t* node, int value){ // input: head of list and desired value   output: true or false
	node_t* temp = node; // new node temp to traverse the list
	while (temp->next) {
		if (temp->data == value){
			return true;
		}
		else{
			temp = temp->next;
		}
	}
	if (temp->data == value){
		return true;
	}
	else {
		return false; // returns false if it goes through the whole list and the value is not found
	}
}

void delete_value(node_t* node, int value){
	bool found = is_present(node, value); // creates boolean variable with value of is_present 
	if (found == true){
		node_t* temp = node->next;
		node_t* prev = node;
		if (prev->data==value){ // if first value in list contains value
			node = temp; // sets head equal to second value in lost
			delete prev; // deletes first node
		}
		else {
			bool deleted = false;
			while (temp->next && deleted == false){	
				if (temp->data==value){
					prev->next = temp->next;
					delete temp;
					deleted = true;
				}
				else {
					temp = temp->next;
					prev = prev->next;
				}
			}
			if (temp->data==value && deleted == false){ // if last node in list contains value
				prev->next = temp->next; // prev becomes null
				delete temp; // deletes last item
			}				
					
		}
	}
	else {
		cout << "Value was not found in list, no deletion." << endl;
	}
}

void front(node_t*& node, int value){
	node_t* temp = new node_t; // creates new node not affiliated with list
	temp->data = value;
	temp->next = node; // puts temp at the front of the list
	node = temp;
}
	

int main(){
    node_t* head = new node_t;
    head->data = 1;
    head->next = NULL;
	node_t* temp = head;
    
    push_back(2, temp);
    push_back(3, temp);
    push_back(4, temp);
	temp = head;
    
    cout << "Should be 1 2 3 4 = ";
    print(head);
    
    add(temp, 10);
	temp = head;
    
    cout << "Should be 11 12 13 14 = ";
    print(head);
    
    node_t* rev = reverse(temp);
    cout << "Should be 14 13 12 11 = "; // syntax error
    print(rev);
	
	bool found = is_present(head, 14);
	cout << "\n14 was found: " << ((found==1)?"true":"false") << endl;
	found = is_present(head, 21);
	cout << "\n21 was found: " << ((found==1)?"true":"false") << endl;

	delete_value(head, 13);
	delete_value(head, 14);
	cout << "Should be 11 12: ";
	print(head);
	delete_value(head, 18);
	
	front(head, 10);
	front(head, 9);
	cout << "Should be 9 10 11 12: ";
	print(head);
    
    // Return the memory from the linked lists
    freeMem(head);
	head = NULL;
    freeMem(rev);
	rev = NULL;
}