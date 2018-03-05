#include "DLNode.h"
#include "DLList.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    cout << endl << "\t\t\t ~Test the Doubly-Linked List~ " << endl;
    
    DLList list;
    string value;
    
    
    cout << endl << "Enter the string value (0 to stop): ";
    cin >> value;
    while ( value != "0" )
    {
        list.add_back( value );
        cout << list << endl;
        cout << "head: " << list.get_head() << endl;
        cout << "tail: " << list.get_tail() << endl;
        cout << "counts: " << list.count() << endl;
        cout << endl << "Enter the string value (0 to stop): ";
        cin >> value;
    }
    
    
    cout << endl << endl;
    cout << list << endl;
    cout << "head: " << list.get_head() << endl;
    cout << "tail: " << list.get_tail() << endl;
    //cout << "peek_front(): " << list.peek_front() << endl;
    //cout << "peek_back(): " << list.peek_back() << endl;
    cout << "counts: " << list.count() << endl;
    cout << ( list.is_empty() ? "The list is empty.\n" : "The list is not empty.\n" );
    //list.remove_front();
    //cout << "remove_front(): " << list << endl;
    //list.remove_back();
    //cout << "remove_back(): " << list << endl;
    
    cout << "head: " << list.get_head() << endl;
    cout << "tail: " << list.get_tail() << endl;
    cout << "peek_front(): " << list.peek_front() << endl;
    cout << "peek_back(): " << list.peek_back() << endl;
    cout << "counts: " << list.count() << endl;
    
    string* array = list.as_array();
    string* reverse_array = list.as_array_reverse();
    cout << "as_array() method: ";
    for (int i = 0; i < list.count(); i++)
    {
        cout << array[i];
        cout << ( i < list.count() - 1 ? ", ": "\n" );
    }
    cout << "as_array_reverse() method: ";
    for (int i = 0; i < list.count(); i++)
    {
        cout << reverse_array[i];
        cout << ( i < list.count() - 1 ? ", ": "\n" );
    }
    
    string v;
    cout << "Enter the value you want to check if it is in the list: ";
    cin >> v;
    cout << ( list.contains( v ) ? "Yes, there is.\n" : "No, there isn't.\n" );
    cout << "Enter the value you want to remove: ";
    cin >> v;
    cout << ( list.remove_value( v ) ? "The value is removed.\n" : "The value is not found.\n" );
    cout << list << endl;
    
    cout << "head: " << list.get_head() << endl;
    cout << "tail: " << list.get_tail() << endl;
    cout << "peek_front(): " << list.peek_front() << endl;
    cout << "peek_back(): " << list.peek_back() << endl;
     
    cout << "counts: " << list.count() << endl;
    
    DLList list2{ list };
    cout << "Copy constructor: " << list2 << endl;
    cout << "head: " << list2.get_head() << endl;
    cout << "tail: " << list2.get_tail() << endl;
    cout << "counts: " << list2.count() << endl;
    
    
    cout << endl << "Enter the string value (0 to stop): ";
    cin >> value;
    while ( value != "0" )
    {
        list.add_front( value );
        cout << list << endl;
        cout << "head: " << list.get_head() << endl;
        cout << "tail: " << list.get_tail() << endl;
        cout << "counts: " << list.count() << endl;
        cout << endl << "Enter the string value (0 to stop): ";
        cin >> value;
    }
    
    cout << endl << endl;
    cout << list << endl;
    cout << "head: " << list.get_head() << endl;
    cout << "tail: " << list.get_tail() << endl;
    cout << "peek_front(): " << list.peek_front() << endl;
    cout << "peek_back(): " << list.peek_back() << endl;
    cout << "counts: " << list.count() << endl;
     

    return 0;
}
