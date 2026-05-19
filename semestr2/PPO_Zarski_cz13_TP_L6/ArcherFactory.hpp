#include "Archer.hpp"
#include "CharacterFactory.hpp"

class ArcherFactory : public CharacterFactory {
public:
  Character *generate() override { return new Archer(); }
};
