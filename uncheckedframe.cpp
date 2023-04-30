
#include "uncheckedframe.h"

void uncheckedframe::print(std::ostream &out) const
{
   out << f;
   out << "(level = " << level << ",distance = " << dist << ")\n";
}

bool uncheckedframe::secondisbetter::operator()(const uncheckedframe &u1, const uncheckedframe &u2) const
{
   if (u1.dist < u2.dist)
   {
      return false;
   }
   else if (u1.dist > u2.dist)
   {
      return true;
   }
   else if (u2.dist == u1.dist)
   {
      if (u2.level < u1.level)
      {
         return true;
      }
      else
      {
         return false;
      }
   }
}
