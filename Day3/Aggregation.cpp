// now takes an exampe of studne and teacher again if teacher want ot have dateial of all sitent wofor some eokt then its have to store dtails of alten as refernce 
//but point to be remeber that  still boteh exit eindepnednet ly 
//the have connection stornger than assocation  but weaker ethan pther since bothe can exist indepentley 

// When to Use Aggregation

// Use it when:

// A class has a collection of objects.
// Those objects have independent lifetimes.
// Multiple objects may share the same part.

// Examples:

// Company → Employees
// University → Students
// Team → Players
// Playlist → Songs
// Library → Books
// again take an exmapeoof studne treancer


#include<bits/stdc++.h>
using namespace std;

class Student{
    private :
    string name;
    int marks;

    public:
    Student(string name){
        this->name=name;
    }
    string getName () const {
        return name;
    }
    int getMarks(){
        return marks;
    }
    void setmarks(int m){
        marks=m;
    }
};

class Teacher{
    string name;
    vector<Student*>v;
    public:
    Teacher(string name):name(name){}
    void Work(const Student & student){
        cout<<"Teacher "<<name<<" teaches to "<<student.getName()<<endl;
    }
    void store(Student & student){
        v.push_back(&student);
        cout<<"stored succefully";
    }
    void setmark(Student & student,int m){
student.setmarks(m);
    }
};

int main(){
    Student s("nitish");
    Teacher t("rakesh");
    t.Work(s);
    t.store(s);
    return 0;
}