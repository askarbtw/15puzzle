
#ifndef FRAME_
#define FRAME_ 1

#include <iostream>
#include <iomanip>

#include "move.h"
#include "position.h"

class frame
{

   static constexpr unsigned int nrrows = 4;
   static constexpr unsigned int nrcolumns = 5;

   static_assert( nrrows > 1, "nrrows must be at least two" );
   static_assert( nrcolumns > 1, "nrcolumns be at least two" );

   unsigned int table[ nrrows ][ nrcolumns ];
      // We use the numbers 1 .. dimension*dimension-1 for the tiles.
      // The number for the open place does not matter. 

   position open_place;

public:
   frame( );
      // Default constructor constructs the puzzle in solved position.

   frame( std::initializer_list< std::initializer_list< unsigned int >> init );

   void print( std::ostream& out ) const; 

   bool makemove( move m );
      // This method tries to make a move m. Return 
      // true if the move could be made.
      // In case false is returned, it guaranteed that there are
      // no changes.

   position find( unsigned int val ) const;
      // Find the position of val in the frame. 

   unsigned int distance( const frame& f ) const; 
      // Manhattan distance between this frame and f. 


   struct before
   {
      before( ) = default;
      bool operator( ) ( const frame& f1, const frame& f2 ) const;
   };


};

inline std::ostream& operator << ( std::ostream& out, const frame& f )
{
   f. print( out );
   return out;
}

#endif


