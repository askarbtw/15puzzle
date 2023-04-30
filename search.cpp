
#include "search.h"

#include <queue>
#include <algorithm>

// Remove this when you finished the other parts.

#if 1

// We are trying to find a path from start to goal. 

levelmap search( const frame& start, const frame& goal )
{
   levelmap levels;

   std::priority_queue< uncheckedframe, std::vector< uncheckedframe >, 
                        uncheckedframe::secondisbetter > unchecked; 

   levels[ start ] = 0;
 
   unchecked. push( uncheckedframe( start, 0, start. distance( goal ) ));

   // As long as there are states whose neighbours are unexplored,
   // we pick the best, and explore its neighbours: 

   while( unchecked. size( ))
   {
      uncheckedframe best = unchecked. top( );
         // The best unchecked state as selected by uncheckedstate_better.
      // std::cout << "best unchecked =\n" << best << "\n\n";

      unchecked. pop( );

      if( best. dist == 0 )
         return levels;        // Found!   
     
      for( auto m : { move::up, move::down, move::left, move::right } )
      {
         frame next = best.f;
         bool made = next. makemove( m );

         if( made )
         {
            auto p = levels. find( next );
            if( p == levels. end( ) || best. level + 1 < p -> second ) 
            {
               // We did not reach next before, or we reached it
               // in more steps. 

               levels[ next ] = best. level + 1; 
               unchecked. push( uncheckedframe( next, best. level + 1, next. distance( goal )) );
            }
         }
      }

   }

   return levels;
}



std::vector<move> getpath( const levelmap& map, const frame& goal ) 
{
   auto p = map. find( goal );
   if( p == map. end( ))
      throw std::runtime_error( "goal is not present" );

   unsigned int level = p -> second;
   auto current = goal;

   std::cout << "goal was found on level " << level << "\n";

   std::vector< move > path;

   while( level )
   {
      for( move m : { move::up, move::down, move::left, move::right } )
      {
         auto next = current;
         bool made = next. makemove( m );
         if( made )
         {
            auto p = map. find( next );
            if( p != map. end( ) && p -> second < level )
            {
               path. push_back( m );
               current = next;

               level = p -> second;  
               goto found;
            } 
         }
      }

      std::cout << "failing at " << current << "\n";
      std::cout << "level = " << level << "\n";

      throw std::runtime_error( "there is no path" );
   found:
      ;
   }

   // We now have the path from goal to level 0,
   // so it has to be reversed.

   reverse( path. begin( ), path. end( )); 
   for( auto& m : path )
      m = -m;

   return path;
}

std::ostream& operator << ( std::ostream& out, const levelmap& map ) 
{
   out << "Levelmap of size :\n\n";

   for( const auto& p : map )
   {
      out << "level " << p. second << ":\n";
      out << p. first << "\n";
   }
   out << "size = " << map. size( ) << "\n";
   return out;
}

#endif

