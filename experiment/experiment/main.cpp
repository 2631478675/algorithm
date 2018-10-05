#include <iostream>
using namespace std;
class Student{
private:
    int num;
    float score;
public:
    Student(int n, float s):
            num(n),score(s){}
    void change(int n, float s){
        num = n;
        score = s;
    }
    void display(){
        cout << num << " " << score << endl;
    }
};
void fun(Student &stu){
    stu.display();
    stu.change(101,80.5);
    stu.display();
}
int main() {
    Student stu(101,78.5);
    fun(stu);
    return 0;
}