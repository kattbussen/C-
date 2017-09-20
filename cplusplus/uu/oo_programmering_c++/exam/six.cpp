#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Course {
  private:
    string name;
    int points;
  
	public:
    Course(string na, int point) {
      name = na;
      points = point;
    } 
    
    string getName() {
      return name;
    } 
    
    int getPoints() {
      return points;
    }
		
		string printInfo() {
			return name+"("+to_string(points)+") ";
		} 
};  

class Person {
  private:
    vector<Course> courseVec;
    string name;

  public:
    Person(string na) {
      name = na;
    } 
    
    string getName() {
      return name;
    } 
    
    void addCourse(Course *course) {
      courseVec.push_back(*course); 
    } 
		
		string getCourses() {
			string ret = "";
	
			vector<Course>::iterator it;
			for(it = courseVec.begin(); it != courseVec.end(); ++it) {
				ret += it->printInfo();
			}
			return ret;
		}

		virtual string printInfo() = 0;
};  

class Student : public Person {
  public:
    Student(string name) : Person(name) {
    }
	
		string printInfo() {
			string ret = getName();
			ret += ", student, studerar " + getCourses() + "\n";
			
			return ret;
		}	
};  

class Employee : public Person {
  private:
    string role;
    int salary;
  
	public:
    Employee(string name, string ro, int sal) : Person(name) {
      role = ro;
      salary = sal;
    }

		string printInfo() {
			string ret = getName();
			ret += ", " + role + ", " + "tjänar  " + to_string(salary) + ", undervisar " + getCourses() + "\n";
			return ret;
		} 
};  

class Department {
  private:
    vector<Employee> evec;
    vector<Student> svec;
		 
 
	public:
    void addEmployee(Employee *emp) {
      evec.push_back(*emp);
    }
  
    void addStudent(Student *stud) {
      svec.push_back(*stud);
		}

		ostream& print(ostream &output) {

			output << "ANSTÄLLDA:" << endl;

			vector<Employee>::iterator eit;
			for(eit = evec.begin(); eit != evec.end(); ++eit) {
				output << eit->printInfo();	
			}

			output << "STUDENTER:" << endl;
			vector<Student>::iterator sit;
			for(sit = svec.begin(); sit != svec.end(); ++sit) {
				output << sit->printInfo();
			}

			return output;
		}
		
		friend std::ostream& operator<<(std::ostream &output, Department dpt) {
			return dpt.print(output);
		}
};

int main()
{
  Course *c1 = new Course("C++", 5);
  Course *c2 = new Course("Datorgrafik", 5);
  Course *c3 = new Course("Fortran", 5);
  Employee *e = new Employee("Kalle Anka", "lärare", 20000);
  e->addCourse( c1);
  e->addCourse( c2);
  Student *s = new Student("Erik Anka" );
  s->addCourse( c3);

  Department d;
  d.addEmployee( e );
  d.addStudent ( s );

  cout << d;
}

