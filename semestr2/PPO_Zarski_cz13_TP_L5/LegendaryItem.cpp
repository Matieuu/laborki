#include "LegendaryItem.hpp"
#include <format>
#include <ostream>

std::ostream &operator<<(std::ostream &os, const LegendaryItem &obj) {
  os << std::format(
      "Legendary Item (defence: {}, attack: {}, critical hit chance: {}, "
      "runic power: {})",
      obj.defence_, obj.attack_, obj.critChance_, obj.runicPower_);
  return os;
}
