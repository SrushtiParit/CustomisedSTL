/*Generic singly circular linked list */

#include<iostream>
using namespace std;
#pragma pack(1)

template <class T>
struct node 
{
    T data;
    struct node *next; 
};

template <class T>
class SinglyCL 
{
    public:
        struct node<T> * First;
        struct node<T> * Last;
        int iCount;

        SinglyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();

};

/*int Count (PNODE First, PNODE Last)
{
    int iCnt = 0;
    do
    {
        iCnt++;
        First = First->next;
    } while(First != Last->next);
    return iCnt;
}*/

template <class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::InsertFirst(T No)
{
    struct node<T> * newn = new struct node<T>;

    newn ->data = No;
    newn->next = NULL;

    if((First == NULL)&&(Last == NULL))   //empty linked list 
    {
        First = Last = newn;
    }
    else     //LL contains atleast one node
    {
        newn->next = First;
        First = newn;
    }

     //to maintain the circular nature
    (Last)->next = First;
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T No)
{
    struct node<T> * newn = new struct node<T>;

    newn ->data = No;
    newn->next = NULL;

    if((First == NULL)&&(Last == NULL))   //empty linked list 
    {
        First = Last = newn;
        (Last)->next = First;    //to maintain the circular nature 
    }
    else     //LL contains atleast one node
    {
        (Last)->next = newn;
        Last = newn;
        (Last)->next = First;
    }
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int iPos)
{
    int iCnt = 0;
    struct node<T> * temp = First;

    if((iPos < 0)|| (iPos > iCount+1))
    {
        cout<<"Invalid Position\n";
    }

    if(iPos ==1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> * newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;

        for (iCnt = 1; iCnt< iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn-> next = temp->next;
        temp-> next = newn;
        iCount++;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    //This sequence is very imp as the else if condition also includes if condition in it  
    if((First == NULL) && (Last == NULL))     
    {
        cout<<"Linked list is already empty";
        return;
    }
    else if(First == Last)  //LL has just one node
    {
        //free(*First);
        delete First;
        First = NULL;
        Last = NULL;
        iCount--;
    }
    else  //If LL contains more than 1 node
    {
        First = (First)->next;
        //free((*Last)->next);
        delete (Last)->next;
        (Last)->next = First;
        iCount--;
    }
    
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    struct node<T> * temp = First;

    //This sequence is very imp as the else if condition also includes if condition in it  
    if((First == NULL) && (Last == NULL))     
    {
        cout<<"Linked list is already empty";
        return;
    }
    else if(First == Last)  //LL has just one node
    {
        delete(First);
        First = NULL;
        Last = NULL;
        iCount--;
    }
    else  //If LL contains more than 1 node
    {
        while(temp->next != Last)
        {
            temp = temp->next;
        }
        
        delete(Last);     //delete(temp->next);  (both the statements are true)
        
        Last = temp;
        (Last)->next = First;
        iCount--;
    }
    
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    int iCnt = 0;
    struct node<T> * temp1 = First;
    struct node<T> * temp2 = NULL;

    if((iPos < 0)|| (iPos > iCount+1))
    {
        cout<<"Invalid Position\n";
    }

    if(iPos ==1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1 -> next;
        temp1-> next = temp2->next;

        delete temp2;
        iCount--;
    }
    
}

template <class T>
void SinglyCL<T>::Display()
{
    struct node<T> * temp = First;
    cout<<"Elements of the linked list are: \n";
    do
    {
        cout<<"|"<< temp->data<<"|-> ";
        temp = temp-> next;
    }while (temp != Last->next);
    cout<<"\n";
}


int main()
{
    SinglyCL <int>obj;
    //int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    //iRet = Count();
    cout<<"Number of elements after insert first and last are: "<<obj.iCount<<"\n";

    obj.InsertAtPos(105, 5);
    obj.Display();

    obj.DeleteAtPos(5);
    obj.Display();
    //iRet = Count();
    cout<<"Number of elements after insert and delete at a position are: "<<obj.iCount<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();
    //iRet = Count();
    cout<<"Number of elements after delete first and last are: "<<obj.iCount<<"\n";

    return 0;
}