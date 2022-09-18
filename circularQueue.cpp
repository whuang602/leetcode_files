// William Huang

/*
	Goal: Utilize a linkedlist to create a circular version of queue
	Reasoning: creating a circular structure is most easily done with linkedlist that has individual
	nodes that can point at other nodes and therefore back to the original front node
*/

/*
	Node is created as a struct because I want to be able to access all of the member variables without
	having to create extra accessor or mutator functions. Also, there's nothing that needs to be private
	within Node.
*/
struct Node {
	/*
		The main purpose of Node is just to hold one integer value and hold the pointer to the next Node
		in the queue. Also added an constructor with an integer parameter to make lifer easier in the main
		MyCircularQueue function when declaring and initializing Node on the heap.
	*/
    int value;
    Node* next;
    Node(int val): value(val), next(nullptr) {};
};

class MyCircularQueue {
private:
    
    /*
    	These class member variables are declared as private to ensure they do not get changed outside of 
    	the class.
    	size: holds the intended size of the queue.
    	sizeCounter: holds the current size of the queue, number of Nodes that currently exist in the queue.
    	front: a Node pointer that holds the node at the very front of the queue.
    	back: a Node pointer that holds the node at the very back/rear of the queue.
    */
    int size;
    int sizeCounter;
    Node* front;
    Node* back;
    
public:
    
    /*
    	Circular queue constructor with an integer parameter k
    	1) k is the intended size of the circular queue, so set variable size to be k.
    	2) Next, initialize all the other member variables to default values (0, NULL, nullptr, etc)
    */
    MyCircularQueue(int k) {
        size = k;
        sizeCounter = 0;
        front = nullptr;
        back = nullptr;
    }
    
    /*
    	enQueue adds a value/Node to the end of queue, but only if the intended size permits.
    	As in, only add value if the current existing amount of nodes is less than the intended size.
    */
    bool enQueue(int value) {
        
        /*
        	if !sizeCounter ( sizeCounter == 0 ) then there's nothing in the queue yet. So we declare
        	and initialize a new Node pointer and give it the integer value from the parameter. Then set
        	both front and back to be this new node since having only one node in the queue means it's both
        	the front and the rear. Increase sizeCounter to indicate that we have added a node to the queue.
        	Return true to indicate that a node/value has been added to the queue succesffuly.
        */
        if ( !sizeCounter )
        {
            Node* newNode = new Node(value);
            front = newNode;
            back = newNode;
            back -> next = front;
            sizeCounter++;
            return true;
        }

        /*
        	If the function hasn't exited then that means there's at least one node in the queue but still
        	less than the intended size. This means we can add another node to the queue.
        	1) Declare and initialize a new node pointer and give it the integer value from the parameter
        	2) Since queues add new values at the end, we just need set this new node as the next node of the
        		current back node.
        	3) Set back to be this new rear node and link this node back to the front node.
        	4) Increase sizeCounter and return true to indicate we have successfuly added another node/value
        		to the queue.
        */
        if ( sizeCounter < size )
        {
            Node* newNode = new Node(value);
            back -> next = newNode;
            back = newNode;
            back -> next = front;
            sizeCounter++;
            return true;
        }
        
        /*
        	If the function still hasn't exited by this point then the current amount of nodes in the queue
        	has already reached its maximum capacity, which means we can't add anymore. Return false as
        	a result.
        */
        return false;
    }
    
    bool deQueue() {
    	/*
    		if !sizeCounter ( sizeCounter == 0 ) then there's nothing to remove from the queue. Return false
    		because nothing (has been)/(can be) removed.
    	*/
        if ( !sizeCounter )
            return false;
        
        /*
        	If the function hasn't exited then that means there's at least one Node to remove from the list.
        	Since this is a queue, we remove objects from the front.
        	1) create a temporary node pointer variable to hold the current front node (to be removed).
        	2) set pointer front to point at the node right after the current front
        		and connect the back node to this new front
        	3) cut off the old front and delete it from memory
        	4) reduce sizeCounter so we know we just freed up one node from the queue
        	5) return true because one node has been successfully removed and deleted
        */
        Node* nodeHolder = front;
        front = front -> next;
        back -> next = front;
        nodeHolder -> next = nullptr;
        delete nodeHolder;
        sizeCounter--;
        return true;
    }
    
    int Front() {
    	/*
    		if !sizeCounter ( sizeCounter == 0 ) then we return -1 because there's nothing in the node and
    		therefore there's no front node to return the integer value of
    	*/
        if ( !sizeCounter )
            return -1;
        
        /*
        	the queue has at least one node so we can return the value stored in the front node
        */
        return front -> value;
    }
    
    int Rear() {
    	/*
    		If !sizeCounter ( sizeCounter == 0 ) then we return -1 because there's nothing in the node and
    		therefore there's no rear node to return the integer value of
    	*/
        if ( !sizeCounter )
            return -1;
        /*
        	The queue has at least one node so we can return the value stored in the "rear"/back node
        */
        return back -> value;
    }
    
    bool isEmpty() {
        
        /*
        	Return true if sizeCounter == 0 or if any of the front/back pointers are NULL
        */
        if ( front == nullptr || back == nullptr || !sizeCounter )
            return true;
        
        /*
        	Return false because there's at least one node in the queue
        */
        return false;
    }
    
    bool isFull() {
        
        /*
        	If the sizeCounter ( current number of existing nodes in the queue ) is the same as the intended
        	size of the queue then we return true because that means the queue is full.
        */
        if ( sizeCounter == size )
            return true;
        
        /*
			Return false because there's less than size number of nodes in the queue and therefore the
			queue is not full.
        */
        return false;
    }
};
