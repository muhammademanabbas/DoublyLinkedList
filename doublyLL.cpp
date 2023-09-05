#include <iostream>
using namespace std;
struct Node {
    int data  ; 
    Node * next ; 
    Node * prev  ; 
    Node (int data)
    {
        this ->data = data  ;
        this ->next =NULL ;
        this ->prev = NULL ;
    }
};
class DoublyLL {

    Node * head ; 
    Node * tail ; 
    public:
    DoublyLL();
    bool search  (const int num ) ;
    void insertAtheaad (const int num) ;
    void insertAtEnd (const int num) ;
    void printALL() ;
    ~DoublyLL() ;
    void removeFront () ;
    void removeEnd () ;
    bool removeAt (const int num) ;

};

 DoublyLL :: DoublyLL ()
    {
        head = NULL ;
        tail = NULL ;
    }
    DoublyLL :: ~DoublyLL ()
    {
        Node * temp = head ;
        while (temp != NULL)
        {
            Node * curr  = temp ; 
            temp = temp ->next ;
            delete curr ;
        }
    }
    bool DoublyLL :: search (const int num)
    {
        Node * sear = head  ; 
        while (sear!=NULL && sear->data!=num)
        {
             sear  = sear->next ;
        }
        if (sear==NULL) return false ; 
        return true  ;
    }
    bool DoublyLL :: removeAt(const int num)
    {
        Node * curr = head  ;
        Node * prev = NULL  ;
        while (curr != NULL && curr->data != num)
        {
            prev = curr ;
            curr = curr ->next ;
        }
        if (curr == NULL)
        {
            return false ;
        }
        else if (curr == head)
        {
            removeFront() ;
        }
        else if (curr == tail)
        {
            removeEnd() ;
        }
        else 
        {
            prev ->next = curr ->next ;
            curr ->next ->prev = prev ;
            delete curr ;
        }
        return true ;
        
    }
    void DoublyLL:: removeEnd ()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl ;
        }
        else 
        {
            Node * temp = tail ;
            tail = tail ->prev ;
            tail ->next = NULL ;
            delete temp ;
        }
    }
    void DoublyLL :: removeFront ()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl ;
        }
        else 
        {
            Node * temp = head ;
            head = head ->next ;
            head ->prev = NULL ;
            delete temp ;
        }
    }
   void DoublyLL :: insertAtheaad (const int num)
    {
        Node * temp = new Node (num) ;
        if (head == NULL)
        {
            head = temp ;
            tail = temp ;
        }
        else 
        {
            temp ->next = head ;
            head ->prev = temp ;
            head = temp ;
        }
    }

    void  DoublyLL :: insertAtEnd (const int num)
    {
        Node * temp = new Node (num) ;
        if (head == NULL)
        {
            head = temp ;
            tail = temp ;
        }
        else 
        {
            tail ->next = temp ;
            temp ->prev = tail ;
            tail = temp ;
        }
    }
    void DoublyLL ::  printALL()
    {
        Node * temp = head  ;
        while (temp != NULL)
        {
            cout << temp ->data << " " ;
            temp = temp ->next;
        }
    }
int main ()
{
   DoublyLL o ;
    o.insertAtEnd(1) ;
    o.insertAtEnd(2) ;
    o.insertAtEnd(3) ;
    o.insertAtEnd(4) ;
    // o.printALL() ;
    o.removeAt(3) ;
    // o.printALL() ;
    o.insertAtheaad(20) ;
    o.insertAtEnd(33);
 o.insertAtEnd(23) ;
 o.printALL();
 if  (o.search  (1003) )
 cout  <<"Find " ; 
 else cout  <<"Not Found " ;
 o.removeAt(23) ;
 o.insertAtEnd(1003) ;
 o.printALL() ;
 
   return 0 ; 
}
