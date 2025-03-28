#include "Milieu.h"

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <set>
#include "Comportement.h"
#include "Kamikaze.h"

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}


void Milieu::step( void )
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      Bestiole* b=*it;
      
      b->action( *this );
      b->draw( *this );

   }

   checkForCollisions();
   removeDead();

   comporter();

   

}
void Milieu::comporter(){

   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      Bestiole* b=*it;
      if ((b->getBehavior())!=nullptr)
      {
         cout << "I am a behaving" << endl;
         b->getBehavior()->behave(listeBestioles);
      }
      else
      {
         b->setCouleur(0, 0, 0);
      }
   } 
}
void Milieu::killBestiole(Bestiole *b)
{
   std::vector<Bestiole *>::iterator it = listeBestioles.begin();
   while (it != listeBestioles.end())
   {
      if (*it == b)
      {
         delete *it;
         it = listeBestioles.erase(it);
      }
      else
      {
         ++it;
      }
   }
}


int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;
   for ( std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == **it) && b.jeTeVois(**it) )
         ++nb;

   return nb;

}
void Milieu::checkForCollisions()
{
    int collisionRange =7;
    for (auto it = listeBestioles.begin(); it != listeBestioles.end();)
    {  
        
        for (auto it2 = listeBestioles.begin(); it2 != listeBestioles.end();)
       {  
               Bestiole* b1 = *it;
                Bestiole* b2 = *it2;
          if (std::abs(b1->getX() - b2->getX()) <= collisionRange)
          {
             if (std::abs(b1->getY() - b2->getY()) <= collisionRange)
             {
                if (it != it2)
                {
                   b1->collision();
                   break;
                }
             }
          }
          ++it2;
       }
       ++it;
    }
 }

 std::vector<int> Milieu::getdead() {
   std::vector<int> deadIndexes;
   for (size_t i = 0; i < listeBestioles.size(); ++i) {
       if (listeBestioles[i]->getMort()) { // Check if Bestiole is dead
           deadIndexes.push_back(i);
       }
   }
   return deadIndexes;
}

void Milieu::removeDead()
{ std::vector<int> deadIndexes = getdead();
   std::vector<int> sortedIndexes(deadIndexes.begin(), deadIndexes.end());
   std::sort(sortedIndexes.begin(), sortedIndexes.end(), std::greater<int>());
   for (int indexToDelete : sortedIndexes) {
      if (indexToDelete >= 1 && static_cast<std::vector<Bestiole*>::size_type>(indexToDelete) < listeBestioles.size()) {
         delete listeBestioles[indexToDelete];
      // Remove the pointer from the vector
         listeBestioles.erase(listeBestioles.begin() + indexToDelete);
  }
}

}

// void Milieu::createBestiole()
// {
//    Bestiole *b = new Bestiole();
//    double x;
//    x = static_cast<double>(std::rand()) / RAND_MAX;
//    Comportement *comp= new Kamikaze(*b);
//    if (x <1)
//       behavior->addBehavior(new Kamikaze(b));

//    addMember(b);
// }
