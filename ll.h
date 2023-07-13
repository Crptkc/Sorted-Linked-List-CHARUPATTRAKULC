#include <iostream>
#include <iomanip>

using namespace std;

#include "node.h"

class LL {
  NodePtr hol;
  int size;

public:
  LL();
  int deletes(int value);
  int isEmpty();
  void insert(int value);
  void printList();
  void printList_reverse();
  int get_size(){return size;}
  ~LL();

};

LL::LL() {
  this->hol = NULL;
  size = 0;
}

LL::~LL() {
  cout << "deleting all nodes" << endl;
  NodePtr t;
  t = hol;
  int i;
  for (i = 0; i < size; i++) {
    hol = hol->get_next();
    delete t;
    t = hol;
  }
}


void LL::insert(int value) {
  NodePtr newPtr;      
  NodePtr previousPtr; 
  NodePtr currentPtr;  

  
  newPtr = new Node(value);

  if (newPtr != NULL) { 
    previousPtr = NULL;
    currentPtr = hol;
   
    while (currentPtr != NULL && value > currentPtr->get_data()) {
      previousPtr = currentPtr;            
      currentPtr = currentPtr->get_next(); 
                                          
    } 

    if (previousPtr == NULL) {
        newPtr->set_next(hol);
      if(hol)
          hol->set_prev(newPtr);
        hol = newPtr;
       
      }  
    else { 

      previousPtr->set_next(newPtr);
      newPtr->set_prev(previousPtr);
      newPtr->set_next(currentPtr);
      if(currentPtr)
        currentPtr->set_prev(newPtr);
    } 
    ++size;
  } 
  else {
    cout << value << " not inserted. No memory available." << endl;
  } 
} 
int LL::deletes(int value) {
  NodePtr previousPtr; 
  NodePtr currentPtr;  
  NodePtr tempPtr;     

  if (value == hol->get_data()) {
    tempPtr = hol;        
    hol = hol->get_next(); 
   
    size--;

    delete tempPtr; 

    return value;
  } 
  else {
    previousPtr = hol;
    currentPtr = hol->get_next();

    while (currentPtr != NULL && currentPtr->get_data() != value) {
      previousPtr = currentPtr;            
      currentPtr = currentPtr->get_next(); 
      if (currentPtr == hol)
        currentPtr = NULL;
    } 
    if (currentPtr != NULL) {
      tempPtr = currentPtr;
      previousPtr->set_next(currentPtr->get_next());
      delete tempPtr;
      size--;
      return value;
    }
  } 

  return '\0';
} 
int LL::isEmpty() { 
  return hol == NULL; 
} 

void LL::printList() {
  NodePtr currentPtr = hol;

  if (size == 0) {
    cout << "List is empty." << endl;
  }
  else {
    cout << "The list is:" << endl;

    int i;
    for (i = 0; i < size; i++) {
      currentPtr->print();
      cout << "  ->";
      currentPtr = currentPtr->get_next();
    }

    puts("NULL\n");
  } 
}

void LL::printList_reverse(){
  NodePtr currentPtr = hol;
  if(size==0){
    cout<<"list is empty\n";
  }
  else{
    cout<<"reverse list is : \n";
    for(int i=0;i<size-1;i++){
      currentPtr = currentPtr->get_next();
    }
    for(int i=0;i<size;i++){
      currentPtr->print();
      cout<<" ->";
      currentPtr=currentPtr->get_prev();
    }
    puts("NULL\n");
  }
}