#include "Comparison.cpp"
#include "Generator.cpp"
#include <cstdlib>
#include <ctime>

int main(void) {
  std::srand(std::time(0));

  Point<int> geralt(0, 0);
  Point<int> harpy(0, 0);

  generate_points(&geralt);
  generate_points(&harpy, 10, 100);

  Comparison<int> fight1(geralt, harpy);
  fight1.show_all();

  Point<double> vesemir(0.0, 0.0);
  Point<double> werewolf(0.0, 0.0);

  generate_points(&vesemir);
  generate_points(&werewolf, 10.0, 100.0);

  Comparison<double> fight2(vesemir, werewolf);
  fight2.show_all();
}
