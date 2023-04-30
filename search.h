
#ifndef SEARCH_
#define SEARCH_  1

#include <map>
#include <vector>

#include "frame.h"
#include "uncheckedframe.h"

using levelmap = std::map< frame, unsigned int, frame::before > ; 

levelmap search( const frame& start, const frame& goal );  

std::vector< move > getpath( const levelmap& map, const frame& goal ); 
      // Construct the path from level 0 towards the goal. 
  
std::ostream&
operator << ( std::ostream& out, const levelmap& m );

#endif

