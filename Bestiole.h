#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <tuple> 
using namespace std;

class Comportement;
class Milieu;


class Bestiole
{

private :
   static const int        MAX_AGE;
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;
   static int              next;

private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;
   bool              mort=false;
   double            mortProb=0;
   int               timeToLive;   /** The remaining life time of the creature. */
   double            deathProb; /** The probability of death of the creature. */
   double            cloneProb;
   double            camouflageCoeff; /** The camouflage coefficient of the creature. */
   //Accesoire         *accesoire;   /** The accessory of the creature. */
   //Sensor            *sensor;
   std::vector<Bestiole *> detectedBestioles;
   Comportement*      comportement;

   T               * couleur;

private :
   void bouge( int xLim, int yLim );

public :   
                                           // Forme canonique :
   Bestiole( void );                            // Constructeur par defaut                 //constructeur par comportement
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;
   bool jetedetecte( Bestiole* b );
  
   void initCoords( int xLim, int yLim );
   void collision();
   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );
   void setVitesse(double v) { vitesse = v; }  
   void setX(int _x) { x = _x; }
   void setY(int _y) { y = _y; }
   void setOrientation(double o) { orientation = o; }
   //void setAccesoire(Accesoire *a) { accesoire = a; }
   void setComportement(Comportement *b) { comportement= b; }
   void setMort(bool m) { mort = m; };
   void setCouleur(int r, int g, int b)
   {
      couleur[0] = r;
      couleur[1] = g;
      couleur[2] = b;
   }

   //Accesoire *getAccesoire() const { return accesoire; }
   //Comportement *getBehavior() const { return behavior; }
   int getTimeToLive() const { return timeToLive; }
   std::tuple<double, double> getPosition() { return std::tie(x, y); }
   double getOrientation() { return orientation; }
   //Sensor *getSensor() { return sensor; }
   double getCamouflage() { return camouflageCoeff; }
   bool getMort() const { return mort; };
   int getX() const { return x; }
   int getY() const { return y; }
   Comportement *getBehavior() const { return comportement; }
   std::vector<Bestiole *> getDetected() { return detectedBestioles; }
   
};

#endif
