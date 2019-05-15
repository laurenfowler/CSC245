	using namespace std;
        #include "dsexceptions.h"
	#include <vector>

        template <class Comparable>
        class BinaryHeap
        {
          public:
            explicit BinaryHeap( int capacity = 100 );

            bool isEmpty( ) const;
            bool isFull( ) const;
            const Comparable & findMin( );

            const Comparable & findMax( );

	    int Height () const;	

            void insert( const Comparable & x );
            void deleteMin( );
            void deleteMin( Comparable & minItem );
            void makeEmpty( );
	    void printLtSubtree();
	    void printLeaves();

          private:
            int                currentSize;  // Number of elements in heap
            vector<Comparable> array;        // The heap array

            void buildHeap( );
            void percolateDown( int hole );
            void printLtSubtree(int i);
	    void printLeaves(int i);
        };

        #include "BinaryHeap.cpp"
