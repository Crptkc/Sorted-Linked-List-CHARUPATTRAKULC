#include <iostream>
using namespace std;
#include "ll.h"

void instructions( void );

int main( void )
{ 
   LL l; 
   unsigned int choice; 
   int item;

   instructions(); 
   cout<< "? " ;
   cin>> choice ;

   while ( choice != 3 ) { 
      int size;
      switch ( choice ) { 
         case 1:
            cout<<"Enter a number: " ;
            cin>> item ;
            l.insert( item ); 
            l.printList();
            l.printList_reverse();
        
            break;
         case 2: 
            if ( !l.isEmpty() ) { 
               cout<< "Enter number to be deleted: " ;
               cin>>item ;

              
               if ( item==l.deletes(item) ) { 
              
                  l.printList();
                 l.printList_reverse();
               } 
               else {
                  cout<<item<<" not found.\n\n";
               }
            } 
            else {
               cout<<"List is empty."<<endl;
            } 

            break;
         default:
           cout<< "Invalid choice." <<endl;
            instructions();
            break;
      } 
      size = l.get_size();
      if(size <= 0)
         break;
      cout<< "? " ;
     cin>>choice ;
   } 

   puts( "End of run" );
}


void instructions( void )
{ 
   cout<< "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end."<<endl ;
} 