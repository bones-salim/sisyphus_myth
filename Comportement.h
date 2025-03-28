#ifndef COMPORTEMENT_H
#define COMPORTEMENT_H
#include <string>
#include <vector>
#include <memory>
class Bestiole;
class Milieu;

class Comportement
{
public:
    virtual void behave(std::vector<Bestiole*> ListeBestiole) = 0;
    virtual ~Comportement() = default;
};
#endif  
