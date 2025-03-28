#include "Kamikaze.h"
#include <vector>
#include "Milieu.h"

Kamikaze::Kamikaze(Bestiole *bestiole) : bestiole(bestiole)
{
}
void Kamikaze::behave(std::vector<Bestiole*> ListeBestiole)
{   
    bestiole->setCouleur(255, 0, 0);
    Bestiole *target = getTarget(ListeBestiole);
    if ((target) ) 
    {
        chase(target);
        
    }
}
Bestiole *Kamikaze::getTarget(std::vector<Bestiole*> ListeBestioles)
    {
        double minDistance=1000000;
        Bestiole* target=nullptr;
        for (std::vector<Bestiole*>::iterator it = ListeBestioles.begin(); it != ListeBestioles.end(); ++it)
            {
            Bestiole* be = *it;
            if ((bestiole->jetedetecte(be))&& (bestiole!=be))
            {
                double distance = calculateDistance(*bestiole, *be);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    target = be;
                }

            }
        }
        cout << "I found a goddarn target" << endl;
        return target;
        }
        
    
void Kamikaze::chase(Bestiole *target)
    {
        double dx = target->getX() - bestiole->getX();
        double dy = target->getY() - bestiole->getY();
        double norm = sqrt(dx * dx + dy * dy);
        if (norm>0)
        {
            dx = dx / norm;
            dy = dy / norm;
        }
        double direction= -std::atan2(dy, dx); //angle inversed becasue it's in flipped coordinates
        bestiole->setOrientation(direction);
   
    }
double Kamikaze::calculateDistance(const Bestiole &b1, const Bestiole &b2)
    {
        double dx = b1.getX() - b2.getX();
        double dy = b1.getY() - b2.getY();
        return sqrt(dx * dx + dy * dy);
    }
   
    

