/*****************************************************************
* Name: Christopher Boseak
* Class: CS 162
* Description: lab 7 - Demo of linked lists
******************************************************************/
#include <iostream>
#include <cstdlib>

using namespace std;

//Prototyping
struct node;
void addToNode(int);
void removeFromNode(int);
void printNodeList();
void menu();
void removeFilo();
void removeFifo();

//initializing pointers as NULL
node* frontOf = NULL; // frontOf points to front of list
node* current = NULL; // current is the current position
node* temp = NULL; // temp will be used when scrolling through,as a place holder for the previous

int main()
{
    //call to menu function
    menu();

}

//NODE
struct node
{
    int data;
    node* next;
};

/*************************************
* ADD TO NODE FUNCTION
**************************************/
void addToNode(int addTo)
{
    node* n = new node;
    n->next = NULL;
    n->data = addTo;

    // if first position is not empty
    // start at first position
    if (frontOf != NULL)
    {
        current = frontOf;

        // while next is not empty(end)
        // advance forward
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = n;
    }
    // else the front position
    // will be the new node
    else
    {
        frontOf = n;
    }
}

/*****************************************************
* REMOVE FROM NODE FUNCTION - USER SPECIFIED
******************************************************/
void removeFromNode(int deleteFrom)
{
    node* deletePtr = NULL;

    temp = frontOf;
    current = frontOf;

    //while current pointer is not at end of list and
    //current pointer is not what we are looking for
    while(current != NULL && current->data != deleteFrom)
    {
        temp = current;
        current = current->next;
    }

    //current point is null, it means our parameter is not in list
    if(current == NULL)
    {
        cout << deleteFrom << " was not found" << endl;
    }
    else
    {
        //set delete point to found number
        deletePtr = current;

        //make current next in list
        current = current->next;

        //make temp(which was at last item) connect with current
        //(which is the next item) this will link the items before and
        //after so that you can delete the item without dangling pointers
        temp->next = current;

        //since before and after are linked, the item searched
        //is now deleted.
        delete deletePtr;
        cout << deleteFrom << " has been deleted!" << endl;
    }
}
/*****************************************************
* REMOVE FROM NODE FUNCTION - FIFO
******************************************************/
void removeFifo()
{

    node* deletePtr = NULL;
    current = frontOf;

    //since first position is getting deleted, reset front position to the second item on list (now the first)
    frontOf = current->next;
    deletePtr = current;

    delete deletePtr;



}
/*****************************************************
* REMOVE FROM NODE FUNCTION - FILO
******************************************************/
void removeFilo()
{
    node* deletePtr = NULL;
    temp = frontOf;
    current = frontOf;

    // if next is not null continue(finds end of list)
    while (current->next != NULL)
    {
        temp = current;
        current = current->next;

    }

    //removes link in previous node since current node no longer exists.
    temp->next = NULL;
    deletePtr = current;
    delete deletePtr;

}


/*****************************************************
* PRINT FUNCTION - PRINTS LIST
******************************************************/
void printNodeList()
{
    //points to front of list
    current = frontOf;

    //while current position is not end of list
    while(current != NULL)
    {
        cout << current->data << endl;
        current = current->next;
    }
}

/*****************************************************************
* MENU FUNCTION - I OPTED TO THE MENU IN A FUNCTION INSTEAD OF
* MAIN BECAUSE IT ALLOWED ME TO CONTINUOUSLY CALL IT AFTER EACH
* ACTIVITY..... ALLOWING THE PROGRAM TO CONTINUE
*****************************************************************/
void menu()
{
    int choiceIn, intIn, removeIn;

    cout << "\nwhat would you like to do?\n" << endl
        << "1. Add integer to list" << endl
        << "2. Remove integer from list" << endl
        << "3. FIFO Remove - Remove First Item in List" << endl
        << "4. FILO Remove - Remove Last Item in List" << endl
        << "5. Print List" << endl
        << "6. Quit" << endl
        << "\nChoice: ";
    cin >> choiceIn;

    if (choiceIn == 1)
    {
        cout << "\nPlease specify integer to add to list" << endl
            << "Integer: " ;
        cin >> intIn;
        addToNode(intIn);
        menu();
    }
    else if (choiceIn == 2)
    {
        cout << "\nWhat integer would you like to remove?" << endl
            << "Integer: " ;
        cin >> removeIn;
        removeFromNode(removeIn);
        menu();
    }
    else if (choiceIn == 3)
    {
        removeFifo();
        menu();
    }
    else if (choiceIn == 4)
    {
        removeFilo();
        menu();
    }
    else if (choiceIn == 5)
    {
        cout << "\nCURRENT LIST" <<endl
            << "-------------------" << endl;
        printNodeList();
        menu();
    }
    else
    {
        //De-allocating memory on exit
        current = frontOf;
        while(current->next != NULL)
        {
            temp = current;
            current = temp->next;
            delete temp;
        }

        exit(0);
    }
}




