#include "Item.hpp"

class LegendaryItem : public Item {
private:
  double runicPower_;

public:
  LegendaryItem() : Item(), runicPower_(0.0) {}
  LegendaryItem(double defence, double attack, double critChance,
                double runicPower)
      : Item(defence, attack, critChance), runicPower_(runicPower) {}

  friend std::ostream &operator<<(std::ostream &os, const LegendaryItem &obj);

  double getRunicPower() const { return runicPower_; }
};
