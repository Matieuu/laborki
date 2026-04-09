#include <iostream>
#include <string>

class Person {
private:
  std::string name_;
  int age_;
  float height_;
  float weight_;

protected:
  std::string origin_;

public:
  Person() : name_("Człowiek"), age_(0), height_(0), weight_(0) {
    std::cout << "Konstruktor domyślny - klasa podstawowa Person\n";
  }
  ~Person() { std::cout << "Destruktor - klasa podstawowa Person\n"; }
  void introduce_yourself() { std::cout << "I'm " << name_ << std::endl; }
  std::string get_name() const { return name_; }
  int get_age() const { return age_; }
  float get_height() const { return height_; }
  float get_weight() const { return weight_; }
};

class Witcher : public Person {
public:
  Witcher() : Person() {
    std::cout << "Konstruktor domyślny - klasa pochodna Witcher\n";
  }
  ~Witcher() { std::cout << "Destruktor - klasa pochodna Witcher\n"; }
  void cast_a_sign() { std::cout << "The sign: Aard!\n"; }
  void set_origin(std::string origin) { origin_ = origin; }
  void reveal_the_origin() {
    std::cout << "I come from " << origin_ << std::endl;
  }
};

class Sorceress : public Person {
private:
  std::string magic_academy_;
  int age_;

public:
  Sorceress(std::string magic_academy, int age)
      : magic_academy_(magic_academy), age_(age) {
    std::cout << "Konstruktor wieloargumentowy - klasa pochodna Sorceress\n";
  }
  ~Sorceress() { std::cout << "Destruktor - klasa pochodna Sorceress\n"; }
  std::string get_magic_academy() const { return magic_academy_; }
  int get_age() const { return age_; }
};

int main(void) {
  Witcher *witcher = new Witcher();

  witcher->introduce_yourself();
  std::cout << witcher->get_name() << std::endl;
  std::cout << witcher->get_age() << std::endl;
  std::cout << witcher->get_height() << std::endl;
  std::cout << witcher->get_weight() << std::endl;

  witcher->cast_a_sign();

  witcher->set_origin("Rivia");
  witcher->reveal_the_origin();

  Sorceress *sorceress = new Sorceress("Aretuza", 100);
  std::cout << sorceress->get_name() << std::endl;
  std::cout << sorceress->get_height() << std::endl;
  std::cout << sorceress->get_weight() << std::endl;
  std::cout << sorceress->get_age() << std::endl;
  std::cout << sorceress->get_magic_academy() << std::endl;

  delete witcher;
  delete sorceress;
  return 0;
}

//? Działanie którego konstruktora zaobserowałeś i dlaczego?
//! Obu, ponieważ najpierw wywoływany jest konstruktor klasy podstawowej przez
//! listę inicjalizacyjną, a następnie jest wywoływany konstruktor klasy
//! pochodnej

//? Czy udało się wywołać metody klasy podstawowej dla obiektu klasy pochodnej?
//Dlaczego?
//! Tak, ponieważ klasa Witcher dziedziczy wszystkie pola oraz metody klasy
//! podstawowej, jednak nie do wszystkich ma dostęp (private)

//? Czy zauważyłeś działanie destruktora? Jeżeli tak, to jakiego i dlaczego?
//! Tak, oba destruktory się uruchamiają, ponieważ obiekt pochodny musi
//! zniszczyć siebie i część odziedziczoną

//? Wyjaśnij dlaczego istnieje możliwość nadania wartości polu w klasie
//podstawowej poprzez metodę klasy pochodnej.
//! Ponieważ pole ma ustawiony modyfikator protected sprawiający że te pola są
//! dostępne w klasie pochodnej ale nie poza nią

//? Jakie wartości zostały wyświetlone?
//! Domyślne z klasy Person oraz ustawione z klasy Sorceress, pole age_ jest z
//! klasy Sorceress

//? Jaką wartość teraz uzyskałeś?
//! Ustawioną przez klasę Sorceress

//? Co się dzieje w momencie, gdy klasa pochodna i klasa podstawowa posiadają
//pola o tych samych nazwach?
//! Klasa pochodna przesłania pole stworzone przez klasę podstawową i korzysta
//! ze swojej
