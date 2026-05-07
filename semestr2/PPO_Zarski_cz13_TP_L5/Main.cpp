#include "Inventory.cpp"
#include "Item.cpp"
#include "LegendaryItem.cpp"

int main(void) {
  Inventory db = Inventory();
  db += Item();
  std::cin >> db[0];

  db += Item(5, 10, 0.15);
  db += db[0] + db[1];
  std::cout << db;

  LegendaryItem *legItem = new LegendaryItem(
      db[2].getDefence(), db[2].getAttack(), db[2].getCritChance(), 5);

  Item item = static_cast<Item>(*legItem);
  std::cout << item << std::endl;

  item = (Item)*legItem;
  std::cout << item << std::endl;
  std::cout << *legItem << std::endl;

  return 0;
}
