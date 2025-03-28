#include "Aquarium.h"
#include "Milieu.h"
#include "Kamikaze.h"
#include "Bestiole.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 640, 480, 30 );

    for ( int i = 1; i <= 18; ++i )
    {
    ecosysteme.getMilieu().addMember(new Bestiole() );
    }
  
   for ( int i = 1; i <= 20; ++i )
      {
      Bestiole* bestiola= new Bestiole();
      Kamikaze* kamikazi = new Kamikaze(bestiola);
      bestiola->setComportement(kamikazi);
      bestiola->setCouleur(0, 0, 255);
      
      ecosysteme.getMilieu().addMember(bestiola );
      }
   
      ecosysteme.run();


   return 0;

}
