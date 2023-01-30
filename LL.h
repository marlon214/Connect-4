#include <cstddef>
template <typename T>
class LL 
{
    //contents of each node
    struct node 
    {
        T data;
        node* prev;
        node* next;
    };
    //iterator class to allow access of each node in main
   public:
    class Iterator 
    {
       public:
        friend class LL;
        Iterator();
        Iterator(node*);
        T operator*() const;
        Iterator operator++(int);   //i++
        Iterator operator++();      //++i
        Iterator operator--(int);   //i--
        Iterator operator--();      //--i
        bool operator==(const Iterator&) const;
        bool operator!=(const Iterator&) const;

       private:
        node* current;              //since it is a private member of a nested class
                                    //the outter class does not have access to this member
                                    // that is why we signify that the outter class is marked as a friend                                
    };

    LL();
    LL(const LL<T>&);
    const LL<T>& operator=(const LL<T>&);
    ~LL();
    void headInsert(const T&);
    void tailInsert(const T&);
    void headRemove();
    bool isEmpty() const;
    std::size_t size() const;
    Iterator begin() const;
    Iterator end() const;

   private:
    node * portal;
};

//iterator class implementation
template <typename T>
LL<T>::Iterator::Iterator() 
{
    current= NULL;
}

template <typename T>
LL<T>::Iterator::Iterator(node* ptr) 
{
    current = ptr;
}

template <typename T>
T LL<T>::Iterator::operator*() const 
{
    return current->data;
}

template <typename T>
typename LL<T>::Iterator LL<T>::Iterator::operator++(int) 
{
    current= current->next;
    return current;  
}

template <typename T>
typename LL<T>::Iterator LL<T>::Iterator::operator++() 
{
    current= current->next;
    return current->prev; 
}

template <typename T>
typename LL<T>::Iterator LL<T>::Iterator::operator--(int) 
{
    current= current->prev;
    return current;           
}

template <typename T>
typename LL<T>::Iterator LL<T>::Iterator::operator--() 
{
    current= current->prev;
    return current->next;     
}

template <typename T>
bool LL<T>::Iterator::operator==(const Iterator& rhs) const 
{
    return this->current==rhs->current;
}

template <typename T>
bool LL<T>::Iterator::operator!=(const Iterator& rhs) const 
{
   return this->current!=rhs->current;
}

//Linked list class implementation
template <typename T>
LL<T>::LL() 
{
    node* temp= new node();
    portal->next= portal;
    portal->prev=portal;
    // portal->data=NULL;
}

//copy constructor
template <typename T>
LL<T>::LL(const LL<T>& copy) 
{
    this->portal= new node();
    node* temp= new node()
    temp->data= copy->portal->data;
    temp->prev= portal;
    this->portal=temp;
    node* currentNode= portal->next;

    while(currentNode->data!= NULL){


    }
}

template <typename T>
const LL<T>& LL<T>::operator=(const LL<T>& rhs) 
{
    
}

//destructor
template <typename T>
LL<T>::~LL() 
{
    
}

//head insert
template <typename T>
void LL<T>::headInsert(const T& item) 
{

}

//tail insert
template <typename T>
void LL<T>::tailInsert(const T& item) 
{
    
}

template <typename T>
void LL<T>::headRemove()
{
    
} 

template <typename T>
bool LL<T>::isEmpty() const
{
    
}

template <typename T>
std::size_t LL<T>::size() const
{
   
}

template <typename T>
typename LL<T>::Iterator LL<T>::begin() const 
{
    
}

template <typename T>
typename LL<T>::Iterator LL<T>::end() const 
{
   
}

