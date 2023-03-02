//Generic singly linear linked list in C++

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
class SinglyLL
{
    public: 
        struct node<T> * First;
        int iCount;

        SinglyLL();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPosition(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int iPos);

        void Display();
};

/*
Return_Value Class_Name :: Function_Name(Parameters)
{

}
*/

template <class T>
SinglyLL<T> :: SinglyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>:: InsertFirst(T No)
{
    //Step1 : Allocate the memory for node
    struct node<T> * newn = new struct node<T>;

    //Step2 : Initialise node
    newn->data = No;
    newn->next = NULL;

    //step 3: Check if the LL is empty or not
    if(First == NULL)
    {
        First = newn;
    }
    else   //if LL contains at least one node
    {
        newn->next = First;
        First= newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    //Step1 : Allocate the memory for node
    struct node<T> * newn = new struct node<T>;

    //Step2 : Initialise node
    newn->data = No;
    newn->next = NULL;

    //step 3: Check if the LL is empty or not
    if(First == NULL)
    {
        First = newn;
    }
    else   //if LL contains at least one node
    {
        struct node<T> * temp = First;
        while(temp ->next != NULL)
        {
            temp = temp ->next;
        }
        temp-> next = newn;
    }
     iCount++;
}

template <class T>
void SinglyLL<T>:: InsertAtPosition(T No, int iPos)
{
    if((iPos < 1)||(iPos>iCount+1))  //filter
    {
        cout<<"Invalid Position!";
        return;       //return to the function call and because the return type of this function is void so just return;
    }

    if(iPos == 1)
    {
       InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        struct node<T> * newn = new struct node<T>;
        newn ->data = No;
        newn->next = NULL;

        struct node<T> * temp = First;
        for(int iCnt = 1; iCnt< iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn-> next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL<T>:: DeleteFirst()
{
    if(First == NULL)  //if(iCount == 0)
    {
        return;
    }
    else if(First-> next == NULL)  // else if(iCount == 1)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct node<T> * temp = First;
        First = First->next;
        delete temp;
        iCount--;
    }
}

template <class T>
void SinglyLL<T>:: DeleteLast()
{
    if(First == NULL)  //if(iCount == 0)
    {
        return;
    }
    else if(First-> next == NULL)  // else if(iCount == 1)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct node<T> * temp = First;
        while(temp -> next ->next != NULL)
        {
            temp = temp->next;
        }   
        delete temp-> next;
        temp->next =NULL;

        iCount--;
    }
}

template <class T>
void SinglyLL<T>:: DeleteAtPosition(int iPos)
{
    if((iPos < 1)||(iPos>iCount+1))  //filter
    {
        cout<<"Invalid Position!";
        return;       //return to the function call and because the return type of this function is void so just return;
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
        struct node<T> * temp1 =First;
        for(int iCnt =1; iCnt<iPos -1; iCnt++)
        {
            temp1 =temp1->next;
        }
        struct node<T> * temp2 = temp1-> next;
        temp1-> next = temp2 -> next;
        delete temp2;

        iCount--;

    }
}

template <class T>
void SinglyLL<T>:: Display()
{
    cout<<"Element of Linked list are: "<<"\n";
    struct node<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL \n";
}


int main()
{
    SinglyLL <int>obj1;
    SinglyLL <int>obj2;
    
    cout<<"First pointer contains: "<<obj1.First<<"\n";
    cout<<"Number of nodes are: "<<obj1.iCount<<"\n";

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.Display();
    cout<<"Number of nodes are: "<<obj1.iCount<<"\n";

    obj1.InsertLast(101);
    obj1.InsertLast(111);
    obj1.InsertLast(121);

    obj1.Display();
    cout<<"Number of nodes are: "<<obj1.iCount<<"\n"; 

    obj1.InsertAtPosition(105, 5);
    obj1.Display();
    cout<<"Number of nodes are: "<<obj1.iCount<<"\n";

    obj1.DeleteAtPosition(5);
    obj1.Display();
    cout<<"Number of nodes are: "<<obj1.iCount<<"\n";

    obj1.DeleteFirst();
    obj1.DeleteLast();

    obj1.Display();
    cout<<"Number of nodes are: "<<obj1.iCount<<"\n"; 
    return 0;
}