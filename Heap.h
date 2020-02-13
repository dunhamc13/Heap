//This class was modeled off of a partially created Class by Professor Olson of the UWB and from Carrano/Henry.
//This was created as a public repository in an effort to master the ADT Heap for a midterm.
//Precondition: The template item that is being passed must have functioning operators >/<.

#include <vector>
using namespace std;

template <typename Data>
class Heap
{
   public:
      //default constructor
      Heap()
      {}//end default constructor
      
      //overloaded constructor
      //preconditions need a pointer to an array of items, with the number of items to heapify
      Heap(Data** array, int itemCount)
      {}//end overloaded constructor
      
      //returns int value of num of items in heap
      int numItems()
      {}//end numItems
      
      //returns bool value if heap is empty
      bool isEmpty()
      {}//end isEmpty

      //returns int value of heap height
      int getHeight()
      {}//end getHeight

      //returns value stored at heap root
      Data* peakTop()
      {}//end peakTop

      //adds an item to the heap
      bool add(const Data* newData)
      {}//end add data to heap
      
      //removes an item from the heap
      bool remove(const Data* newData)
      {}//end remove data to heap
      
      //Destructor
      virtual ~Heap()
      {}//end destructor

   private:
      //returns index value of left child of argument
      int getLeft(int parentIndex)
      {}//end getLeft
      
      
      //returns index value of right child of argument
      int getRight(int parentIndex)
      {}//end getRight
      
      //returns index value of parent of argument
      int getParent(int parentIndex)
      {}//end getParent
      
      //returns bool value if node is leaf
      bool isLeaf(int nodeIndex)
      {}//end isLeaf
      
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
