#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


struct Student{

    static int counter; // this member variable is available to all instances of this type
                        // as this is a static member variable and available to all instances it must be initialised outside
    std::string first_name {}; // these are public member variables that are available to be written and read from outside the class
    std::string surname {};
    int id = ++counter;

    void print_member(){
        int first_name = 123; //this will override the member variables unless specifically as this ->
        std::cout << this->first_name << " " << surname << " " << id << '\n';

    }

};

int Student::counter = 0; // declaring the value of the static member variable for student class the scope is
                        // static member counter initialise to value 0

struct ModuleRecord{

    Student record {};
    int grade {};

};

bool ascend_sort(const ModuleRecord& i, const ModuleRecord& j){

    return i.grade > j.grade;

}

struct Module{

    std::string module_name {};
    std::vector<ModuleRecord> grades;

    void add_record(const Student& i, const int& grade){
        ModuleRecord a = {i, grade};

        this->grades.push_back(a);

    }

    void print() {

        if (grades.empty()) {

            std::cout << "No records" << '\n';

        }
        else {

            std::sort(grades.begin(), grades.end(), ascend_sort);

            for (const ModuleRecord& rec : grades) {



                std::cout << "First name: " << rec.record.first_name << " " << "Surname: " << rec.record.surname
                          << " " << "ID No.: " << rec.record.id << " " << "Grade: " << rec.grade << '\n';

            }
        }
    }

};


int main() {

    Student a {"Saad", "Rathore"};

    a.print_member(); // calls the public member function in instance a of class student.
                        //for a static function for the class call with class::function name (instance of class)

    //std::cout << a.first_name <<" " << a.surname << " " << a.id << '\n';

    Student Saad{"Saad", "Rathore"};
    int grade{100};
    Student Steve{"Steve", "Smith"};
    Student Gerald{"Gerald", "Ford"};
    Student Harrison{"Harrison", "Ford"};
    Student Chewie{"Chewbacca"};


    Module test{"C++ Studies"};
    test.add_record(Saad, grade);
    test.add_record(Steve,45);
    test.add_record(Gerald,78);
    test.add_record(Harrison,2);
    test.add_record(Chewie, 100);

    test.print();
    return 0;
}