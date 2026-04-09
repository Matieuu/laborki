#include "Enemy.cpp"
#include "Harpy.cpp"
#include "Werewolf.cpp"

int main(void) {
  Enemy **enemies = new Enemy *[4];

  Harpy *harpy = new Harpy(2, 1, 3, 7);
  Werewolf *werewolf = new Werewolf(7, 3, 1, 2);
  Harpy *harpy2 = new Harpy();
  Werewolf *werewolf2 = new Werewolf();

  enemies[0] = harpy;
  enemies[1] = werewolf;
  enemies[2] = harpy2;
  enemies[3] = werewolf2;

  for (int i = 0; i < 4; i++) {
    enemies[i]->attack(0.1);
    enemies[i]->update_position(2, 2);
    enemies[i]->show();
  }

  delete harpy;
  delete werewolf;
  delete harpy2;
  delete werewolf2;
  delete[] enemies;

  return 0;
}

//? Jak myślisz, dlaczego pola klasy Enemy są protected, a nie private?
//! Ponieważ potrzebujemy do nich dostępu z klas pochodnych

//? Czy można wskaźnikowi klasy pochodnej przypisać wskaźnik klasy bazowej?
//! Nie, wyrzuci błąd `Incompatible pointer types assigning`

//? Które ze stworzonych klas są klasami abstrakcyjnymi? Uzasadnij odpowiedź.
//! Klasa `Enemy` ponieważ jako jedyna nie może istnieć sama z siebie,
//! potrzebuje innej klasy do przesłonięcia metod wirtualnych
