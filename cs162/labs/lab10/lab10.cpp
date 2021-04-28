#include <iostream>
#include <string>

using namespace std;

class Pet {
	protected:
		string name;
		int weight;
	public:
		Pet();
		~Pet();
		string get_name();
		void set_name(string);
		int get_weight();
		void set_weight(int);
		virtual string getLifespan();
};

class Dog : public Pet {
	private:
		string breed;
	public:
		Dog();
		~Dog();
		string get_breed();
		void set_breed(string);
		string getLifespan();
};

Pet::Pet() {}

Pet::~Pet() {}

string Pet::get_name() {
	return name;
}

void Pet::set_name(string name) {
	this->name = name;
}

int Pet::get_weight() {
	return weight;
}

void Pet::set_weight(int weight) {
	this->weight = weight;
}

string Pet::getLifespan() {
	return "unkown lifespan";
}

Dog::Dog() {}

Dog::~Dog() {}

string Dog::get_breed() {
	return breed;
}

void Dog::set_breed(string breed) {
	this->breed = breed;
}

string Dog::getLifespan() {
	if(get_weight() > 100) return "Approximately 7 years";
	if(get_weight() < 100) return "Approximately 13 years";
}

int main() {
	Pet p;
	Dog *d;
	
	string name;
	cout << "What is your pets name?: ";
	cin >> name;
	p.set_name(name);

	int weight;
	cout << "What is your pets weight?: ";
	cin >> weight;
	p.set_weight(weight);

	cout << p.getLifespan() << endl;

	int num_dogs;
	cout << "How many dogs?: ";
	cin >> num_dogs;
	d = new Dog[num_dogs];

	cout << endl;
	for(int i = 0; i < num_dogs; i++) {
		string dog_name, dog_breed;
		int dog_weight;
		d[i] = Dog();
		cout << "Dog #" << i+1 << "'s name: ";
		cin >> dog_name;
		d[i].set_name(dog_name);
		cout << "Dog #" << i+1 << "'s weight: ";
		cin >> dog_weight;
		d[i].set_weight(dog_weight);
		cout << "Dog #" << i+1 << "'s breed: ";
		cin >> dog_breed;
		d[i].set_breed(dog_breed);
		cin.clear();
		cout << endl;
	}

	for(int i = 0; i < num_dogs; i++) {
		cout << "Dog #" << i+1 << ": " << d[i].getLifespan() << endl;
	}

	delete [] d;

	return 0;
}
