#ifndef DLList_h
#define DLList_h

#include "DLNode.h"
#include <string>
using std::string;
#include <iostream>

class DLList
{
public:
    DLList () = default;
    DLList ( const DLList& list ) { *this = list; }    //copy constructor
    ~DLList()                     { clear(); }
    
    
    void    add_front( const string& new_v );
    void    add_back ( const string& new_v );
    string  peek_front() const;
    string  peek_back () const;
    string  remove_front();
    string  remove_back ();
    bool    remove_value( const string& target );
    bool    contains    ( const string& target ) const;
    bool    is_empty() const;
    int     count() const { return counts; }
    string* as_array() const;
    string* as_array_reverse() const;
    void    clear();
    void    write( std::ostream& fout ) const;
    
    //for debugging purposes
    string get_head() const { return head -> get_data(); }
    string get_tail() const { return tail -> get_data(); }
    
    const DLList& operator= ( const DLList& list );
private:
    DLNode* head   = nullptr;
    DLNode* tail   = nullptr;
    int     counts = 0;
};
std::ostream& operator<< ( std::ostream& fout, const DLList& list );



class EmptyListException {};

#endif
