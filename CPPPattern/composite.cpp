#include <vector>
#include <iostream> 
#include <algorithm> 
#include <functional> 
#include <list>
using namespace std;

class Person {
public:
	virtual void show()=0;
	virtual ~Person() {}
};

class Student: public Person {
private: string name;
private: string phone;
	public:
		Student(string name, string phone) {
			this->name = name;
			this->phone = phone;
		}
public:
	void show()  {
		cout << "   $$ Name: " << this->name << '\n';
		cout << "   $$ Phone: " << this->phone << '\n';
	}
};

class Teacher : public Person {
private: string name;
private: string phone;
public:
	Teacher(string name, string phone) {
		this->name = name;
		this->phone = phone;
	}
public:
	void show() {
		cout << "   $$ Name: " << this->name << '\n';
		cout << "   $$ Phone: " << this->phone << '\n';
	}
};



// Composite
class PersonCollection : public Person {

public:
	void show()  {
		for_each(personList.begin(), personList.end(), mem_fun(&Person::show));

	}
	void add(Person* aPerson) {
		personList.push_back(aPerson);
	}

private:
	list<Person*> personList;
};

int main()
{
	Student* student1 = new Student("Mahsa", "0565654");
	Student* student2 = new Student("Kashi", "0546654");

	PersonCollection studentCollection;
	studentCollection.add(student1);
	studentCollection.add(student2);

	Teacher* teacher1 = new Teacher("Sara", "038756678");
	Teacher* teacher2 = new Teacher("Sima", "078687688");

	PersonCollection teacherCollection;
	teacherCollection.add(teacher1);
	teacherCollection.add(teacher2);

	PersonCollection personList;
	personList.add(&studentCollection);
	personList.add(&teacherCollection);
	personList.show();

	return 0;
}