//doubly linear linked list in C++

#include<iostream>
using namespace std;
#pragma pack(1)

template <class T>
struct node        //total size of this struct node is now 20 byte
{
    T data;       //memory will be allocated in the sequence in which it has been declared
    struct node<T> *next;
    struct node<T> *prev;      // X
};

template <class T>
class DoublyLL
{
    public:
        struct node<T> * First;
        int iCount;

        DoublyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPosition(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int iPos);

        void Display();
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct node<T> * newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        (First)->prev = newn;  // X

        First = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct node<T> * newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;      // X

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct node<T> * temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;      // X
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPosition(T no, int iPos)
{
    

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> * newn = new struct node<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;      // X

        struct node<T> * temp = NULL;
        temp = First;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next->prev = newn;    // X
        temp->next = newn;
        newn->prev = temp;      // X
        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if((First)->next == NULL)
    {
        free(First);
        First = NULL;
        iCount--;
    }
    else
    {
        First = (First)->next;
        free((First)-> prev);     //X
        (First)->prev = NULL;    //X
        iCount--;
    }
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct node<T> * temp = First;
    if(First == NULL)
    {
        return;
    }
    else if((First)->next == NULL)
    {
        free(First);
        First = NULL;
        iCount--;
    }
    else
    {
        while(temp->next ->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        iCount--;
    }
}

template <class T>
void DoublyLL<T>::DeleteAtPosition(int iPos)
{
    struct node<T> * temp1 = NULL;
    struct node<T> * temp2 = NULL;
    int iCnt = 0;

    if((iPos < 1) || (iPos > iCount+ 1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;  
        temp2->next->prev = temp1;      // X
        delete temp2;
        iCount--;
    }
}

template <class T>
void DoublyLL<T>::Display()
{
    cout<<"Element of Linked list are: "<<"\n";
    struct node<T> * temp = First;

    cout<<"NULL <=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|<=>";
        temp = temp->next;
    }
    cout<<"NULL \n";
}

int main()
{
    DoublyLL <int>obj1;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.Display();
    obj1.InsertLast(101);
    obj1.InsertLast(111);
    obj1.InsertLast(121);

    obj1.Display();
    cout<<"Number of nodes are: "<<obj1.iCount<<"\n"; 

    obj1.InsertAtPosition(105, 5);
    obj1.Display();

    obj1.DeleteAtPosition(5);
    obj1.Display();
    //iRet = Count();
    cout<<"Number of elements after insert and delete at a position are: "<<obj1.iCount<<"\n";


    obj1.DeleteFirst();
    obj1.DeleteLast();
    obj1.Display();
    cout<<"Number of nodes are: "<<obj1.iCount<<"\n"; 


    return 0;
}

