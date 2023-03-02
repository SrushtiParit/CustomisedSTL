//doubly circular linked list
#include<iostream>
using namespace std;
#pragma pack(1)

template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template <class T>
class DoublyCL
{
    public:
        struct node<T>* First;
        struct node<T>* Last;
        int Count;

        DoublyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
};

template <class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
    Count = 0;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    //1. allocated memory to the node
    struct node<T>* newn = new struct node<T>;
    //Initialize the values
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

// three conditions of InsertFirst are

    if((First == NULL)&&(Last == NULL))   //LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    //LL has node already
    {
        //atla links join karun ghe baher che link hotat automatically
        newn->next = First;
        (First)->prev = newn;
        First = newn;
    }
//  make it circuar     
    (First)->prev = (Last);   
    (Last)->next = (First);
    Count++;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
//1. allocated memory to the node
    struct node<T>* newn = new struct node<T>;
    //Initialize the values
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

//2. three conditions of InsertFirst are

    if((First == NULL)&&(Last == NULL))   //LL is empty
    {
        First = newn;
        Last = newn;
    }
    else   //LL has node already
    {
        //atla links join karun ghe baher che link hotat automatically
        newn->prev = Last;
        (Last)->next = newn;
        Last = newn;
    }
//3.  make it circuar or maintain circuar nature      
    (First)->prev = (Last);   
    (Last)->next = (First);
    Count++;
}

template <class T>
void DoublyCL<T>::Display()
{
    struct node<T>* temp = First;
    if((First ==NULL)&&(Last == NULL))    //filter
    {
        cout<<"Linked List is empty\n";
        return;
    }

    cout<<"Elements of link list are: \n";
    cout<<" <=>";
    do
    {
        cout<<"|" <<temp->data<< "|<=>";
        temp = temp->next;
    }while(temp != Last->next);
    cout<<" \n";
}

/*int Count(struct node<T>* First, struct node<T>* Last)
{
    int iCnt  = 0;
    if((First ==NULL)&&(Last == NULL))    //filter
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        First = First->next;
    }while(First != Last->next);

    return iCnt;
}*/

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    //Start directly with three condition 
    if((First == NULL)&& (Last == NULL))  //empty LL
    {
        return;
    }   
    else if(First == Last)  
    {
        free(First);
        First = NULL;
        Last = NULL;
        Count--;
    }
    else
    {
//master la sang pahila student gela dusrya cha nav lakshat tev        
        First = (First)->next;
//pahilya la free kr        
        free((First)->prev);       //or free((*Last)->next);
//Circular nature maintain kr
        (First)->prev = (Last);   
        (Last)->next = (First);
        Count--;
    }
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    //Start directly with three condition 
    if((First == NULL)&& (Last == NULL))  //empty LL
    {
        return;
    }   
    else if(First == Last)  
    {
        free(First);
        First = NULL;
        Last = NULL;
        Count--;
    }
    else
    {
//master la sang porachya
        Last = (Last)->prev;
        free((First)->prev);     //or free((*Last)->next);
//Circular nature maintain kr
        (First)->prev = (Last);   
        (Last)->next = (First);        
        Count--;
    }
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no, int ipos)
{
//kiti pora ahet te bagh
    int iCnt = 0;
    struct node<T>* temp = NULL;
//invalid position cha filter    
    if((ipos<1)&&(ipos>Count))  //filter
    {
        cout<<"Invaid Position \n";
        return;
    }
//Three main conditions
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == Count +1)
    {
        InsertLast(no);
    }
    else
    {
//new memory allocation for new node         
        struct node<T>* newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;
        for (iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp -> next;
        temp->next->prev = newn;    // X
        temp->next = newn;
        newn->prev = temp;      // X
        Count++;
    }
    
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int ipos)
{
//kiti pora ahet te bagh
    int iCnt = 0;
    struct node<T>* temp = NULL;
//invalid position cha filter    
    if((ipos<1)&&(ipos>Count))  //filter
    {
        cout<<"Invaid Position \n";
        return;
    }
//Three main conditions
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for (iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
        Count--;
    }
    
}

int main()
{
    DoublyCL <int>obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst( 11);
    obj.Display();


    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    
    cout<<"Number of elements are:"<<obj.Count<< "\n";

    obj.InsertAtPos(105, 5);
    obj.Display();
    
    cout<<"Number of elements are:"<<obj.Count<< "\n";

    obj.DeleteAtPos(5);
    obj.Display();
    
    cout<<"Number of elements are:"<<obj.Count<< "\n";
    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();

    cout<<"Number of elements are:"<<obj.Count<< "\n";
    return 0;
}