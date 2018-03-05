#ifndef DLNode_h
#define DLNode_h

#include <string>
using std::string;


class DLNode
{
public:
    DLNode( string v ) : data( v ) {}
    
    string  get_data() const { return data; }
    DLNode* get_next() const { return next; }
    DLNode* get_prev() const { return prev; }
    void    set_data( string new_v )     { data = new_v; }
    void    set_next( DLNode* new_next ) { next = new_next; }
    void    set_prev( DLNode* new_prev ) { prev = new_prev; }
private:
    string data;
    DLNode* next = nullptr;
    DLNode* prev = nullptr;
};

#endif 
