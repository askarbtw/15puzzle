
#ifndef UNCHECKED_FRAME_
#define UNCHECKED_FRAME_  1

#include "move.h"
#include "frame.h" 

struct uncheckedframe
{
   frame f;
   unsigned int level;     // Nr of moves from the original state.
   unsigned int dist;      // Distance towards the goal state. 

   uncheckedframe( const frame& f, unsigned int level, unsigned int dist )
      : f(f), 
        level( level ),
        dist( dist ) 
   { }

   struct secondisbetter
   {
      secondisbetter( ) = default;

      bool 
      operator( ) ( const uncheckedframe& u1, const uncheckedframe& u2 ) const;
   };

   void print( std::ostream& out ) const;  
};

inline 
std::ostream& operator << ( std::ostream& out, const uncheckedframe& u )
{
   u. print( out ); 
   return out; 
}

#endif
 
