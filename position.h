

#ifndef POSITION_
#define POSITION_  1

#include <iostream>

struct position
{
   unsigned int row;
   unsigned int column;

   position( ) 
      : row(0), column(0)
   { }

   position( unsigned int row, unsigned int column )
      : row( row ),
        column( column )
   { }

};

inline std::ostream& operator << ( std::ostream& out, position p )
{
   out << "[ " << p.row << ", " << p.column << " ]";
   return out; 
}

// Manhattan distance between positions p1 and p2:

inline unsigned int distance( position p1, position p2 ) 
{
   auto drow = ( p1. row > p2. row ) ? 
                    p1. row - p2. row : p2. row - p1. row;
   auto dcol = ( p1. column > p2. column ) ? 
                    p1. column - p2. column : p2. column - p1. column;
   return drow + dcol;
}

#endif


