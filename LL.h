/******************************************************************
Name: Marlon Alejandro
NSHE ID: 5002573038
Section: 1002
Assignment: 1
Description: Connect 4 Header
******************************************************************/

using namespace std; 
template <typename T>
class LL 
{
    struct node 
    {
        T data;
        node* prev;
        node* next;
    };

public:
   
    class Iterator 
    {
    public:
        friend class LL;
        Iterator();
        Iterator(node*);
        T operator*() const;
        Iterator operator++(int);
        Iterator operator++();
        Iterator operator--(int);
        Iterator operator--();
        bool operator==(const Iterator&) const;
        bool operator!=(const Iterator&) const;

    private:
        node* current;
    };

    LL();
    LL(const LL<T>&);
    const LL<T>& operator=(const LL<T>&);
    ~LL();
    void headInsert(const T&);
    void tailInsert(const T&);
    void headRemove();
    bool isEmpty() const;
    size_t size() const;
    Iterator begin() const;
    Iterator end() const;

private:
    node * portal;
};

template <typename T>
LL<T>::Iterator::Iterator(){
    current = nullptr; 
}

template <typename T>
LL<T>::Iterator::Iterator(node* ptr) {
    current = ptr; 
}

template <typename T>
T LL<T>::Iterator::operator*() const {
    return current->data; 
}

template <typename T>
typename LL<T>::Iterator LL<T>::Iterator::operator++(int) {
   current = current->next; 
   return current; 
}

template <typename T>
typename LL<T>::Iterator LL<T>::Iterator::operator++(){
    current = current->next;
    return current->prev;
}

template <typename T>
typename LL<T>::Iterator LL<T>::Iterator::operator--(int){   
    current = current->prev; 
    return current; 
}

template <typename T>
typename LL<T>::Iterator LL<T>::Iterator::operator--() {  
    current = current->prev; 
    return current->next; 
}

template <typename T>
bool LL<T>::Iterator::operator==(const Iterator& rhs) const {
    return this->current == rhs.current; 
}

template <typename T>
bool LL<T>::Iterator::operator!=(const Iterator& rhs) const {
   return this->current != rhs.current; 
}


template <typename T>
LL<T>::LL() 
{ 
    portal = new node; 
    portal->prev = portal; 
    portal->next = portal;  
}

template <typename T>
LL<T>::LL(const LL<T>& copy) {
    LL<T>::Iterator temp; 
    this->portal = new node; 
    portal->next = portal; 
    portal->prev = portal; 
    temp = copy.begin();

    while (temp != copy.portal) {   
        this->tailInsert(temp.current->data);
        temp++;  
    }

}

template <typename T>
const LL<T>& LL<T>::operator=(const LL<T>& rhs) {
    node* ptr = portal->next; 
    LL<T>::Iterator rhsCurrent = rhs.begin(); ; 
    if(ptr != portal){
        while(portal->next != portal){
           this->headRemove();           
        }
    }

    portal->next = portal;
    portal->prev = portal;

    while (rhsCurrent != rhs.portal) {     
        this->tailInsert(rhsCurrent.current->data); 
        rhsCurrent++;  
    }
    
    return *this; 
}

template <typename T>
LL<T>::~LL() {
    node* temp = portal->next;  
    while(temp != portal)   
    {
        node* next = temp->next; 
        delete temp; 
        temp = next;  
    }
    delete portal; 
}

template <typename T>
void LL<T>::headInsert(const T& item) {
    node* temp = new node();
    temp->data = item;
    if(portal->next == portal) {
        temp->prev = portal;
        temp->next = portal; 
        portal->prev = temp; 
        portal->next = temp; 
    }else {
    
        node* head_node = portal->next; 
        head_node->prev = temp; 
        portal->next = temp;    
        temp->next = head_node; 
        temp->prev = portal;    
    }
}

template <typename T>
void LL<T>::tailInsert(const T& item) {
    node* temp = new node(); 
    temp->data = item; 
    
    if(portal->next == portal){ 
        temp->prev = portal; 
        temp->next = portal; 
        portal->prev = temp;
        portal->next = temp; 
    }else {   
        node* prev_node = portal->prev; 
        portal->prev = temp;    
        temp->prev = prev_node; 
        temp->next = portal;    
        prev_node->next = temp; 
    }
}

template <typename T>
void LL<T>::headRemove(){
    if(!isEmpty()){
        node* temp = portal->next;   
        portal->next = temp->next;  
        temp->next->prev = portal;  
        temp->prev = nullptr;       
        temp->next = nullptr;       
        delete temp;                
    }
} 

template <typename T>
bool LL<T>::isEmpty() const{

    return portal->next == portal; 
}

template <typename T>
size_t LL<T>::size() const{
    size_t count =0;
    node* temp = portal->next;
    while (temp != portal){
        count++;
        temp = temp->next; 
    }
    return count;  
}

template <typename T>
typename LL<T>::Iterator LL<T>::begin() const 
{
    return Iterator(portal->next);  
}

template <typename T>
typename LL<T>::Iterator LL<T>::end() const 
{
    return Iterator(portal); 
}   

// template <typename T>
// void LL<T>::printLL() const
// {
//     std::cout<< this->current << endl;
//     // //int num = 0; 
//     // node* temp = portal->next;
//     // // while(temp!= portal)
//     // // {
//     //     //std::cout << temp->data << "->";
//     //     int size=0;
//     //     while(size!=7){
//     //         if(temp==portal){
//     //             std::cout<<"- ";
//     //             size++;
//     //             temp = temp->next;
//     //             continue;
//     //         }
//     //         std:: cout <<""<< temp->data << " ";
//     //         temp = temp->next;
//     //         size++;
//     //     }

//     //     // temp = temp->next;
//     //     //if(num == 7) break; 

//     // std::cout << std::endl;
// }