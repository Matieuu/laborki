#include "Archer.hpp"
#include "CharacterFactory.hpp"
#include "Mage.hpp"
#include "Warrior.hpp"

class ArcherFactory : public CharacterFactory {
public:
  Archer *generate() override { return new Archer(); }
};

class MageFactory : public CharacterFactory {
public:
  Mage *generate() override { return new Mage(); }
};

class WarriorFactory : public CharacterFactory {
public:
  Warrior *generate() override { return new Warrior(); }
};
