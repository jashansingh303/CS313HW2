#include <iostream>
#include <cassert>

using namespace std;


template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

template <class Type>
class linkedStackType
{
public:
    const linkedStackType<Type>& operator=
                              (const linkedStackType<Type>&);


    bool isEmptyStack() const;


    bool isFullStack() const;


    void initializeStack();


    void push(const Type& newItem);


    Type top() const;


    void pop();


    linkedStackType(); 


    linkedStackType(const linkedStackType<Type>& otherStack); 
  

    ~linkedStackType();

	void listAll() const;

	void set(int index, const Type& newItem);


private:
    nodeType<Type> *stackTop; //pointer to the stack

    void copyStack(const linkedStackType<Type>& otherStack); 

};


    
template <class Type> 
linkedStackType<Type>::linkedStackType()
{
    stackTop = nullptr;
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
    return(stackTop == nullptr);
} 

template <class Type>
bool linkedStackType<Type>:: isFullStack() const
{
    return false;
} 

template <class Type>
void linkedStackType<Type>:: initializeStack()
{
    nodeType<Type> *temp; 

    while (stackTop != nullptr) 
    {
        temp = stackTop;    
                           
        stackTop = stackTop->link; 
                                   
        delete temp;   
    }
} 

template <class Type>
void linkedStackType<Type>::push(const Type& newElement)
{
    nodeType<Type> *newNode;  

    newNode = new nodeType<Type>; 

    newNode->info = newElement; 
    newNode->link = stackTop; 
    stackTop = newNode;        
                             
} //end push


template <class Type>
Type linkedStackType<Type>::top() const
{
    assert(stackTop != nullptr); 
                              
    return stackTop->info; 
}//end top

template <class Type>
void linkedStackType<Type>::pop()
{
    nodeType<Type> *temp;   

    if (stackTop != nullptr)
    {
        temp = stackTop;  

        stackTop = stackTop->link; 
                                    
        delete temp;    
    }
    else
        cout << "Cannot remove from an empty stack." << endl;
}//end pop

template <class Type> 
void linkedStackType<Type>::copyStack
                     (const linkedStackType<Type>& otherStack)
{
    nodeType<Type> *newNode, *current, *last;

    if (stackTop != nullptr) 
        initializeStack();

    if (otherStack.stackTop == nullptr)
        stackTop = nullptr;
    else
    {
        current = otherStack.stackTop;  

          
        stackTop = new nodeType<Type>;  

        stackTop->info = current->info; 
        stackTop->link = nullptr;  
                               
        last = stackTop;        
        current = current->link;    

           
        while (current != nullptr)
        {
            newNode = new nodeType<Type>;

            newNode->info = current->info;
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
} 

 
template <class Type>   
linkedStackType<Type>::linkedStackType(
                      const linkedStackType<Type>& otherStack)
{
    stackTop = nullptr;
    copyStack(otherStack);
}

  
template <class Type> 
linkedStackType<Type>::~linkedStackType()
{
    initializeStack();
}
    
template <class Type>   
const linkedStackType<Type>& linkedStackType<Type>::operator=
    			  (const linkedStackType<Type>& otherStack)
{ 
    if (this != &otherStack) 
        copyStack(otherStack);

    return *this; 
}


// list all the elements in the stack
template <class Type>   
void linkedStackType<Type>::listAll() const
{ 
	
	// start from top and move to end of list
    for (nodeType<Type> * i = stackTop; i != nullptr; i = i->link)
	{	
		// print current node info
		cout << i->info << " ";
	}

	cout << endl;
	
}


// set element at given index (top is at index 0)
template <class Type>  
void linkedStackType<Type>::set(int index, const Type& newItem) {

	// start from current
	nodeType<Type> *curr= stackTop;

	// move to desired position
	for (int i = 0; i < index; i++)
	{
		curr= curr->link;
	}

	// set elemenet
	curr->info = newItem;
	
}



