//This class was modeled off of a partially created Class by Professor Olson of the UWB and from Carrano/Henry.
//This was created as a public repository in an effort to master the ADT Heap for a midterm.
//This class is not homework or Student Ethics bound.  This is me, playing with what I've learned to master it.
//Precondition: The template item that is being passed must have functioning operators >/<.

#include <vector> // for use of vectors
#include <cmath> //for ceiling function to get height
using namespace std;

template <typename Data>
class Heap
{
   public:
      //default constructor
      Heap() : itemCount(0)
      {}//end default constructor
      
      // copy Constructor
      // Preconditions: a heap exists
      // Postconditions: creates a copy of a heap.
      Heap(const Heap &aHeap)
      {
        //get size to run for loop
        int size = aHeap.items.size();

        //for (size) copy items...
        for (int i = 1; i < size; i++)
        {
            //make anew node and get values for it.  don't share addy's with old node
            Data* copyData = new Data();
            *copyData = *aHeap.items[i];

            //use legacy insert function
            this->insert(copyData);
        }//end for copy items
	}//end copyHeap Constructor
	
   //Dunham------------------------------------------------------------------
	// operator= Constructor  
    //  you can not just pass the new node = old node.  This will cause double free
    // of destructor.
    //
    // This function overloads operator= for heaps.  It starts by making
    // sure that LHS and RHS don't have same address.  Next, it makes sure that
    // the LHS is empty.  Then it copies RHS to LHS.
    // 
	// Preconditions: a heap exists
	// Postconditions: creates a copy of a heap.
	Heap* operator=(Heap &aHeap) 
        {
	      //Check addy's both sides not equal
	      if (this != &aHeap)
	      {
		 //if LHS has elements, make space
		 if (this->itemsCount > 0)
		 {
		    destroyHeap(items);
		 }//end if not empty then empty LHS 

		 //get size to run for loop
		 int size = aHeap.items.size();

		 //must push back a nullptr first else we get vector range/bounds errors 
		 //this is due to how the heap driver creates a dummy at index 0
		 items.push_back(nullptr);

		 //for (size) copy items...
		 for (int i = 1; i < size; i++)
		 {
		    //make anew node and get values for it.  don't share addy's with old node
		    Data *copyData = new Data();
		    *copyData = *aHeap.items[i];

		    //use legacy insert function
		    this->insert(c);
		 }//end for copy items
	      }//end if LHS is not RHS

	      return this; 
	}//end operator=
	
      //overloaded constructor
      //preconditions need a pointer to an array of items, with the number of items to heapify
      Heap(Data** array, int numItems)
      {
	      //must push back a nullptr first else we get vector range/bounds errors 
	      //this is due to how the heap driver creates a dummy at index 0
	      items.push_back(nullptr);

	      //First loop through array, only the number times as the size of the array.
	      for (int i = 0; i < numItems; i++)
	      {
		 //Make a static Comparable from the array and store it in items.
		 Data* newData = array[i];
		 items.push_back(newData);
	      }//end for copy array

	      //must set numElements to count - which represents the number of elements
	      this->itemsCount = numItems;

	      //use heapify function to ensure items are in heap order.
	      this->heapify();
      }//end overloaded constructor
      
      //returns int value of num of items in heap
      int numItems()
      {
         return itemCount;
      }//end numItems
      
      //returns bool value if heap is empty
      bool isEmpty()
      {
         if (itemCount == 0)
            return true;
         else
            return false;
      }//end isEmpty

      //returns int value of heap height
      int getHeight()
      {
         return ceil(log2(itemCount) -1);//normally itemCount + 1 if no off by one fix
      }//end getHeight

      //returns value stored at heap root
      Data* peakTop()
      {
         //check if empty
         if (isEmpty())
            return nullptr;
         else
            Data* top = &items[1];
         return top;
      }//end peakTop

      //adds an item to the heap
      void add(Data* newData)
      {		
	      //check for null value
	      if (newData == NULL) 
		      return;
	      
	      // Add item in position 0 (dummy position) to prevent percolating up from root 
	      if (items.size() < 1) items.push_back(c);
	      else items[0] = newData;
	      
	      // Ensure we have enough space
	      itemsCount++;
	      while ((int) items.size() <= itemsCount)
		      items.push_back(nullptr);
	      
	      // bubbleUp
	      int position = itemsCount;
	      while (*newData < *items[position / 2]) 
	      {
		      items[position] = items[position / 2];
		      position = position / 2;
	      }
	      items[position] = newData;
      }//end add data to heap
      
      //removes the minimum item from the heap
      Data* removeMin()
      {
	 //
         //check if empty
         if (itemCount == 0) 
		 return nullptr;
         // Give memory back to user
	 Comparable *toReturn = items[1];
         
         //swap last item to head of heap and decrement
         items[1] = items[itemCount];
	 itemCount--;
         
         //rebuild heap this is a trickle down
   	 bubbleDown(1);
         return toReturn;
      }//end remove data to heap
      
      //creates a heap
      //precondition array of items and space created for items
      void heapify()
      {
	      //
	      for (int i = itemsCount / 2; i > 0; i--)
		      bubbleDown(i);
      }//end heapRebuild
	
      //Destructor
      virtual ~Heap()
      {}//end destructor

   private:
      //returns index value of left child of argument
      int getLeft(int parentIndex)
      {
	 //due to adding a dummy node at index 0 these forumulas don't need off by 1 manipulation.
         return (2 * parentIndex);//normally + 1
      }//end getLeft
      
      
      //returns index value of right child of argument
      int getRight(int parentIndex)
      {
	  //due to adding a dummy node at index 0 these forumulas don't need off by 1 manipulation.
         return (2 * parentIndex) + 1;//normall + 2
      }//end getRight
      
      //returns index value of parent of argument
      int getParent(int childIndex)
      {
         if (childIndex == 1 || childIndex == 0)
            return -1;
         else
	    //due to adding a dummy node at index 0 these forumulas don't need off by 1 manipulation.		 
            return childIndex / 2;//(parent index -1) /2 ** modified for dummy 0 insert fixes off by one
      }//end getParent
      
      //returns bool value if node is leaf
      bool isLeaf(int nodeIndex)
      {
         //use floor to get min value of index for leaf and itemCount to get max value of items
         if (nodeIndex >= (floor(n / 2) + 1) && nodeIndex <= itemCount)
            return true;
         
         //must not be leaf
         else
            return false;
      }//end isLeaf
      
      //restores heap
      //precondition has two semi heaps
      void bubbleDown(int position)
      {
	      //get child position
	      int child = position * 2;
	      
	      //make sure child exists
	      if (child > itemsCount) 
		      return;
	      
	      //get largest value for child
	      if (child != itemsCount && *items[child] > *items[child + 1]) 
		      child++;
	      //for minHeap make sure child isn't smaller than parent
	      if (*items[child] < *items[position]) 
	      {
		      swap(items[child], items[position]);
		      //recursive call
		      bubbleDown(child);
	      }//end swap
      }//end heapRebuild
      

      
      //desrtuctor helper
      void clear(vector<Data*> aVector)
      {
         //loop through vector and return memory, decrease numElements
         for (int i = 1; i < itemCount + 1; i++)
         {
            delete aVector[i];
            --itemCount;
         }
      }//end makeEmpty
      
      //number of elements in the heap
      int itemCount = 0;
      
      //vector to create the heap
      vector<Data*> items;0

}//end class heap
