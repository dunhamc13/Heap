//This class was modeled off of a partially created Class by Professor Olson of the UWB and from Carrano/Henry.
//This was created as a public repository in an effort to master the ADT Heap for a midterm.
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
      
      //overloaded constructor
      //preconditions need a pointer to an array of items, with the number of items to heapify
      Heap(Data** array, int itemCount)
      {}//end overloaded constructor
      
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
         return ceil(log2(itemCount + 1) -1;
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
      bool add(const Data* newData)
      {}//end add data to heap
      
      //removes the minimum item from the heap
      Data* removeMin(const Data* newData)
      {
         //check if empty
         if (itemCount == 0) return nullptr;
         
		   // Give memory back to user
		   Comparable *toReturn = items[1];
         
         //swap last item to head of heap and decrement
		   items[1] = items[itemCount];
		   itemCount--;
         
         //rebuild heap this is a trickle down
   		heapRebuild(1);
		   return toReturn;
      }//end remove data to heap
      
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
            return childIndex / 2;(normally child
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
      void heapRebuild()
      {}//end heapRebuild
      
      //creates a heap
      //precondition array of items
      void heapCreate()
      {}//end heapRebuild
      
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
