#include <iostream>

using namespace std;

class Animal
{
public:
	virtual ~Animal() {}
	// Virtual constructor (creation)
	virtual Animal* create() const { return new Animal(); }
	// Virtual constructor (copying), uses copy constructor in this case
	virtual Animal* clone() const { return new Animal( *this ); }
//	virtual void makeSound() const = 0;
	virtual void makeSound() const { cout << "[Silence]" << endl; };
};

class Sheep : public Animal
{
public:
	Sheep* create() const { return new Sheep(); }
	Sheep* clone() const { return new Sheep( *this ); }
	void makeSound() const { cout << "Meeeee" << endl; }
};

class Cow : public Animal
{
public:
	Cow* create() const { return new Cow(); }
	Cow* clone() const { return new Cow( *this ); }
	void makeSound() const { cout << "Mooooo" << endl; }
};

class Frog : public Animal
{
public:
	Frog* create() const { return new Frog(); }
	Frog* clone() const { return new Frog( *this ); }
	void makeSound() const { cout << "Ribbit" << endl; }
};

//void pokeAnimal( const Animal& animal )
//{
//	Animal* a = new Animal( animal );
//	a->makeSound();
//}

void pokeAnimal( Animal* animal )
{
	cout << "pokeAnimal: " << typeid( animal ).name() << endl;
	
//	Animal* clonedAnimal = new Animal( *animal ); // Here the copy will be the base type
	Animal* clonedAnimal = animal->clone();	// Now the animal will be a proper clone
	clonedAnimal->makeSound();
	cout << typeid( clonedAnimal ).name() << endl;
	
	// Creating a new animal of the same type without knowing what type it is
	Animal* newAnimal = animal->create();
	cout << "New animal of the same type says: ";
	newAnimal->makeSound();
	cout << typeid( newAnimal ).name() << endl;
}

int main( int argc, char *argv[] ) 
{
	Cow c;
	Cow* cow = c.create();
//	Cow* cow = new Cow;
//	Cow cow;
	cout << typeid( cow ).name() << endl;
	pokeAnimal( cow );
}