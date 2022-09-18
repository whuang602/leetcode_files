// Name: William huang
// rotateList but with for-loop

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        /* 
            Approach: For-Loop
            (I originally attempted a recursive version of this problem, which did pass all 231 tests on leetcode, but ended up
            not being clean enough to really warrant being recursive. Ironically, this non-recursive version was quite a bit cleaner.)

            General Goal:
            1) calculate size of the list of nodes
            2) reduce k (times to rotate) to the necessary amount so we dont waste resources
            3) use a for loop to rotate the list k times
        */

        /*
            If k (number of times to rotate) is 0 or less then just return the head node. There's no reason to go further.
        */
        if ( k < 1 )
            return head;
        
        /* Declare and initialize two variables:
            1) oldTail to do 2 things, (a) walk through every node in the list to calculate size and later (b) store the tail node of the list
            2) size to store and calculate the total number of nodes in the list, initialized to 0 so it doesn't start out as some random trash value
        */
        ListNode* oldTail = head;
        int size = 0;
        
        /* 
            This is a while loop that will help us calculate the size of the list (to be used later in reducing memory usage). Basically, now that oldTail
            has been set to the head of the nodes we can use it to walk through every node until we find the last node, which is immediately followed
            by a NULL. The moment oldTail becomes NULL, we know we have gotten the right size value and can exit the while loop.
        */
        while ( oldTail != NULL )
        {
            oldTail = oldTail -> next;
            size++;
        }
        
        /*
            If the size is 1 or less then there's no point rotating the list at all. So I simply return head and skip the rest of the function.
        */
        if ( size <= 1 )
            return head;
        
        /* 
            This part is important for reducing unnecessary memory usage:
            The below checks to see if the k (times to rotate) is greater than or equal to the size of the list, because everytimes the list is rotated "size"
            times, it is back to its origninal order. So the actual number of times we need to rotate the list is the remainder of k and size. If we don't do this,
            there's a lot of unnecessarily runtime and memory usage.
        */
        if ( k >= size )
            k = k % size;
        
        /*
            Declare and initialize newTail to go through the nodes and store the new tail node, which is the node right before the current last node
        */
        ListNode* newTail;

        /*
            Now that we have reduced k to the necessary amount, we can use a for-loop to rotate the list "k" times.
        */
        for ( int i = 0 ; i < k ; i++ )
        {
            /* 
                At this point, we know that the size of the list is at least 2, which means head and head -> next are not NULL.
                We set (and also reset) oldTail = head -> next and newTail = head so that newTail will always be the node right before oldTail.
             */
            oldTail = head -> next;
            newTail = head;
            
            /*
                We initialize a while loop that lasts until the end of the list has been found. This is done by checking if the node
                after oldTail (which starts at head -> next) is NULL. We shift newTail and oldTail one node forward until the actual newTail
                and oldTail has been found.
            */
            while ( oldTail -> next != NULL )
            {
                newTail = newTail -> next;
                oldTail = oldTail -> next;
            }
            
            /*
                Now that newTail has been set to the node right before the last node and oldTail has been set to the
                very last node, we can begin to rotate the list. Now that the old tail has been stored else where, we can
                safely set the next node of newTail to be NULL, which now indicates newTail is the last node in the list.
                We then connect oldTail to the start of the list by making its next node the current head of the list. Then we end by
                setting head to the oldTail, finalizing one rotation of the list.
            */
            newTail -> next = NULL;
            oldTail -> next = head;
            head = oldTail;
        }
        
        /*
            By the time the code reaches here, the list has been rotated the correct number of times ( k % size ) so we can return the possibly new head node.
        */
        return head;

    }
};