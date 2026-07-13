// Assocation means - two independent objects know each other and collaborate
// Both can exist inepnendley
//colllbaroetion without eowner sjip 

// its used when 
// 1 object collborate
// 2 objects are independent
// 3 either can exoest alon 

//letes take an exaple of student and teacher

#include<bits/stdc++.h>
using namespace std;

class Student{
    private :
    string name;
    public:
    Student(string name){
        this->name=name;
    }
    string getName () const {
        return name;
    }
};

class Teacher{
    string name;
    public:
    Teacher(string name):name(name){}
    void Work(const Student & student){
        cout<<"Teacher "<<name<<" teaches to "<<student.getName()<<endl;
    }
};

int main(){
    Student s("nitish");
    Teacher t("rakesh");
    t.Work(s);
    return 0;
}
