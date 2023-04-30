
#include "move.h"
#include "frame.h"
#include "search.h"

int main(int argc, char *argv[])
{

#if 0
   frame f1{ { 9, 7, 10, 13 }, 
             { 6, 7, 8, 11 }, 
             { 10, 3, 14, 0 }, 
             { 13, 15, 12, 4 } } ;

   frame f2{ { 8, 15, 5, 11 },
             { 0, 6, 7, 9 },
             { 10, 2, 14, 1 },
             { 13, 3, 12, 4 } };
#endif

   frame f1{{9, 7, 5, 13, 16},
            {6, 1, 8, 11, 17},
            {10, 3, 14, 0, 18},
            {2, 15, 12, 4, 19}};

   std::cout << f1 << "\n";
   f1.makemove(move::right);
   std::cout << f1 << "\n";
   f1.makemove(move::right);
   std::cout << f1 << "\n";

   // std::cout << f2 << "\n";

#if 1
   frame f{{16, 9, 7, 10, 13},
           {14, 2, 17, 8, 4},
           {18, 1, 11, 3, 6},
           {0, 12, 5, 19, 15}};

   auto levels = search(f, frame());

   // std::cout << levels << "\n";

   auto path = getpath(levels, frame());

   std::cout << "Solution with length " << path.size() << "\n";
   unsigned int s = 0;
   for (move m : path)
   {
      std::cout << "---------------------------\n";
      std::cout << s++ << " :  " << m << " results in\n";
      f.makemove(m);
      std::cout << f;
   }
#endif

   return 0;
}
