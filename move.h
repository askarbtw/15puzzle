
#ifndef MOVE_
#define MOVE_ 1

#include <iostream>

enum class move { up, left, right, down };
   // The elements will be called
   // move::up, move::left, move::right, move::down.

inline std::ostream& operator << ( std::ostream& out, move m )
{
   switch(m)
   {
   case move::up : out << "move-up"; return out;
   case move::left : out << "move-left"; return out;
   case move::right: out << "move-right"; return out;
   case move::down: out << "move-down"; return out;
   }
   throw std::logic_error( "operator << : unkown move" ); 
}


// -m is the reverse move of m.

inline move operator - ( move m )
{
   switch(m)
   {
   case move::up:
      return move::down;
   case move::left:
      return move::right;
   case move::right:
      return move::left;
   case move::down:
      return move::up;
   }
   throw std::logic_error( "operator - : unknown move" ); 
}

#endif

