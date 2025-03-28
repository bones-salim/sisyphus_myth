#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<Bestiole*>   listeBestioles;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void addMember( Bestiole* b ) { listeBestioles.push_back(b); listeBestioles.back()->initCoords(width, height); }
   int nbVoisins( const Bestiole & b );
   void checkForCollisions();
   void removeDead();
   void killBestiole(Bestiole *b);
   std::vector<int> countPopulation();
   std::vector<int> getdead();
   void createBestiole();
   void comporter();
};




#endif
