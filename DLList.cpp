#include "DLList.h"
#include "DLNode.h"

/**
 *
 * @detailed     Add the given value to the list at the first place.
 *
 * @param[out]   new_v     the value to be added
 *
 */
void DLList::add_front( const string& new_v )
{
    //create a new node containing given data value
    DLNode* new_node = new DLNode{ new_v };
    new_node -> set_next( head );  //set new node next to head
    if ( !head )  //if the list is empty...
    {
        tail = new_node;
    }
    else  //if there are some nodes in the list...
    {
        head -> set_prev( new_node );
    }
    head = new_node;
    counts++;
}

/**
 *
 * @detailed     Add the given value to the list at the last place.
 *
 * @param[out]   new_v     the value to be added
 *
 */
void DLList::add_back( const string& new_v )
{
    //create a new node containing given data value
    DLNode* new_node = new DLNode{ new_v };
    if ( head )  //if there are some nodes in the list...
    {
        tail -> set_next( new_node );
        new_node -> set_prev( tail );
    }
    else  //if the list is empty...
    {
        head = new_node;
    }
    tail = new_node;
    counts++;
}


/**
 *
 * @detailed     Return the first value in the list.
 *
 * @return       the first value in the list
 *
 */
string DLList::peek_front() const
{
    if ( !head )
    {
        EmptyListException empty_class;
        throw empty_class;
    }
    return head -> get_data();
}


/**
 *
 * @detailed     Return the last value in the list.
 *
 * @return       the last value in the list
 *
 */
string DLList::peek_back() const
{
    if ( !head )
    {
        EmptyListException empty_class;
        throw empty_class;
    }
    return tail -> get_data();
}



/**
 *
 * @detailed     Remove the first value in the list and return that value.
 *
 * @return       the removed value from the list
 *
 */
string DLList::remove_front()
{
    if (!head)  // the list was empty
    {
        EmptyListException empty_class;
        throw empty_class;
    }
    
    DLNode* old_head = head;
    string  old_data;
    head = old_head -> get_next();  //point the head to the node after the old head
    old_data = old_head -> get_data();  //get the data from old head
    if ( !head )  //if the list came to be empty...
    {
        tail = nullptr;
    }
    else  //if there are still some nodes...
    {
        head -> set_prev( nullptr );
    }
    delete old_head; //delete the old head
    old_head = nullptr;
    counts--;
    return old_data;
}


/**
 *
 * @detailed     Remove the last value in the list and return that value.
 *
 * @return       the removed value from the list
 *
 */
string DLList::remove_back()
{
    if (!head)  // the list was empty
    {
        EmptyListException empty_class;
        throw empty_class;
    }
    
    DLNode* old_tail = tail;
    string      old_data;
    tail = old_tail -> get_prev();  //point taile to the node before the old tail
    old_data = old_tail -> get_data();  //get the old data
    if ( !tail )  //if the list came to be empty...
    {
        head = nullptr;
    }
    else
    {
        tail -> set_next( nullptr );  //point the last node to nullptr
    }
    delete old_tail;  //delete the old node
    old_tail = nullptr;
    counts--;
    return old_data;
}


/**
 *
 * @detailed     Remove the given value from the list.
 *
 * @param        target     the value to be removed
 *
 * @return       true if the given value is removed from the list, otherwies false.
 *
 */
bool DLList::remove_value( const string& target )
{
    if (!head)  // the list was empty
    {
        EmptyListException empty_class;
        throw empty_class;
    }
    
    bool result = false;
    DLNode* current = head;
    for (int i = 0; i < counts; i++)  //go through the entire list
    {
        if ( current -> get_data() == target )  //if the same data is found...
        {
            result = true;  //flip the bool value
            if ( current == head ) //if the location is the head
            {
                remove_front();
                current = current -> get_next();
            }
            else if ( current == tail )  //if the location is the tail
            {
                remove_back();
                current = current -> get_next();
            }
            else  //if the location is in the middle
            {
                DLNode* old_current = current;
                DLNode* prev = current -> get_prev();  //get preveous node
                DLNode* next = current -> get_next();  //get next node
                prev -> set_next( next );  //connect preveous node to next
                next -> set_prev( prev );  //connect them in the other direction
                current = next;  //move the current pointer to next
                delete old_current;  //delete the node
                old_current = nullptr;
                counts--;  //decrement the number of nodes by one
            }
        }
        else  //if the current data value isn't the same as the target
        {
            current = current -> get_next();  //just move to next node
        }
    }
    return result;
}


/**
 *
 * @detailed     Search the given value in the list.
 *
 * @param        target     the value to be searched
 *
 * @return       true if the given value is found in the list, otherwies false.
 *
 */
bool DLList::contains( const string& target ) const
{
    bool result = false;
    DLNode* current = head;
    for (int i = 0; i < counts && !result; i++) //check the node until the same data is found
    {
        if ( current -> get_data() == target )
        {
            result = true;
        }
    }
    return result;
}


/**
 *
 * @detailed     Check if the list is empty or not.
 *
 * @return       true if the the list is empty, otherwies false.
 *
 */
bool DLList::is_empty() const
{
    bool result = false;
    if ( !head )
    {
        result = true;
    }
    return result;
}


/**
 *
 * @detailed     Erase all nodes in the list.
 *
 */
void DLList::clear()
{
    while ( head )  //continue to remove the first node until the end
    {
        string old_data = remove_front();
    }
}



/**
 *
 * @detailed     Display the value in the list.
 *
 * @param        fout     the output stream to which the value is sent
 *
 */
void DLList::write( std::ostream& fout ) const
{
    DLNode* current = head;
    while ( current )
    {
        fout << current -> get_data();
        fout << ( current != tail ? ", " : "" );
        current = current -> get_next();
    }
}


/**
 *
 * @detailed     Overloaded insertion operator.
 *
 * @param        fout      the output stream to which the value is sent
 * @param[out]   list      the list to be displayed
 *
 * @return       the output stream
 *
 */
std::ostream& operator<< ( std::ostream& fout, const DLList& list )
{
    list.write( fout );
    return fout;
}


/**
 *
 * @detailed     Overloaded assignment operator.
 *
 * @param[out]   copy      the list to be copied from
 *
 * @return       DLList object
 *
 */
const DLList& DLList::operator= ( const DLList& copy )
{
    clear();  //erase all nodes in the list first
    DLNode* current = copy.head;
    while ( current )  //go through the entire list...
    {
        add_back( current -> get_data() );  //add the node at back
        current = current -> get_next();  //move to next node
    }
    counts = copy.counts;
    return copy;
}


/**
 *
 * @detailed     Duplicate the list as an array and return it.
 *
 * @return       the pointer to the created array
 *
 */
string* DLList::as_array() const
{
    if (!head)  // the list was empty
    {
        EmptyListException empty_class;
        throw empty_class;
    }
    int i = 0;  //array index for later use
    string* array = new string[counts];  //create dynamic array
    DLNode* current = head;
    while ( current )  //traverse the list
    {
        array[i] = current -> get_data(); //store the data
        current = current -> get_next();  //move to the next node
        i++;  //increment the array index
    }
    return array;
}


/**
 *
 * @detailed     Duplicate the list as an array and return it.
 *               The order of the value will be reversed.
 *
 * @return       the pointer to the created array
 *
 */
string* DLList::as_array_reverse() const
{
    if (!head)  // the list was empty
    {
        EmptyListException empty_class;
        throw empty_class;
    }
    int i = 0;  //array index for later use
    string* array = new string[counts];  //create dynamic array
    DLNode* current = tail;
    while ( current )  //traverse the list
    {
        array[i] = current -> get_data(); //store the data
        current = current -> get_prev();  //move to the next node
        i++;  //increment the array index
    }
    return array;
}

