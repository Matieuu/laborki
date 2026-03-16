#include <string>

class Witcher {
  private:
	std::string name_;
	std::string witcher_school_;
	int age_;
	float height_;
	float weight_;

  public:
	Witcher();
	Witcher(std::string name,
	        std::string witcher_school,
	        int age,
	        float height,
	        float weight)
	    : name_(name),
	      witcher_school_(witcher_school),
	      age_(age),
	      height_(height),
	      weight_(weight) {}
	~Witcher();
	void read(void);
	void write(void);

	void set_name(std::string name) { name_ = name; }
	void set_witcher_school(std::string witcher_school) { witcher_school_ = witcher_school; }
	void set_age(int age) { age_ = age; }
	void set_height(float height) { height_ = height; }
	void set_weight(float weight) { weight_ = weight; }

	std::string get_name(void) const { return name_; }
	std::string get_witcher_school(void) const { return witcher_school_; }
	int get_age(void) const { return age_; }
	float get_height(void) const { return height_; }
	float get_weight(void) const { return weight_; }
};
