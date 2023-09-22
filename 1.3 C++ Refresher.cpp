// 1.3 C++ Refresher 

// 1.3.1 Pointers
// Here, we'll start a quick review on how to use pointers.
// Implement the method below, whose parameter, num, is an int pointer. The method must return an int whose value is three times that of the integer pointed to by num.
// Sample Input: 10
// Sample Output: 30
int TripleNum(int *num) {
    return 3 * (*num);
}

// 1.3.2 The "new" Keyword
// Here, we will review the use of the new keyword, and how we can use it to create memory on the heap. We will also review using the delete keyword in order to free that memory and prevent memory leaks.
// The method below is similar to the one seen in the previous step. However, in this method, the return type is an int pointer, instead of an int, and its parameter is an int instead of an int pointer. You must return a pointer that points to an int whose value is three times that of the value of the int num
// Remember that you will need the new keyword in order to put an int on the heap, which you can then return a pointer to. (If the int is created on the stack, it will be deleted once the method ends and it goes out of scope)
// Usually, you'll want to have any instance of memory being created with the newkeyword to then be freed by the delete keyword, normally in a destructor.
// Sample Input: 10
// Sample Output: 30
int* TripleNum(int num) const {
    int* pointer = new int(3 * num);
    return pointer;
}

// 1.3.3 Addresses and References
// Another important operator in C++ is the "&" operator. This can be used to either access the address of a variable (where it is stored in memory) or it can be used to pass something by reference into a method. See this excellent article: https://www.tutorialspoint.com/cplusplus/cpp_references.htm
// The below method receives an int passed by reference as a parameter, num. Implement the method so that it returns an int pointer which points to the same memory address as of num, and multiplies the value of num by 3.
// Sample Input: 15
// Sample Output: addresses match 45
int* TimesThree(int &num){
    num *= 3;
    return &num;
}

// 1.3.4 Templates in C++
// Templates in C++ can be used to create methods or classes that support multiple generic data types, including custom objects.
// Template methods and classes are preceded with template <typename T> or template <class T> where T is a placeholder for the actual datatype that will be used when the template is created.
// Create a template method that accepts a template type T as its parameter, triples its value then returns it as type N. Use the method signature given below.
// You can specify multiple template types by comma separating them in the template declaration. i.e  <typename  T, typename N>. Make sure that the parameter type T is the first parameter in the template declaration, and the return type N is the second parameter, as shown in the example above.
// Sample Input: 3
// Sample Output: 9 correct
template <typename T, typename N>
N ProductOfThree(T num) {
    return static_cast<N>(3*num);
}

// 1.3.5 Working with Classes in C++
// Lets try to model our course. We have a class called "COP3530" that has two instance variables, "session" and "numberOfStudents". Fill out the default and parameterized constructor for this class. Also, submit the required accessors and mutators to ensure the code works. 
// Note
// You do not have to write the main function. We have written the main function and it is hidden. The main function does the following
// creates an object with the default constructor
// calls your accessors and prints first line of output
// reads the first line of input and sets the value of your object to the newly read values using the mutators you created
// calls your accessors and prints second line of output
// Sample Input: 
// Summer2021 200
// Sample Output:
// Summer2020 150
// Summer2021 200
#include <iostream>
#include <string>
using namespace std;

class Cop3530 {
private:
    string session = "";             //stores session, example: Summer2020
    int numberOfStudents = -1;       //stores total number of students in the session
public:
    Cop3530();                  
    Cop3530(string session, int numberOfStudents);

    //accessors and mutators for session
    void setSession(string session); 
    string getSession(); 

    //accessors and mutators for getNumberOfStudents
    void setNumberOfStudents(int numberOfStudents); 
    int getNumberOfStudents();
};
Cop3530::Cop3530(){
    //default constructor sets session to "Summer2020" and numberOfStudents to 150
    setSession("Summer2020");
    setNumberOfStudents(150);
}
Cop3530::Cop3530(string session, int numberOfStudents){
    //parameterized constructor sets session and numberOfStudents 
    setSession(session);
    setNumberOfStudents(numberOfStudents);
}
void Cop3530::setSession(string s){
    // mutator for session
    session = s;
}
string Cop3530::getSession(){
    //accessor for session
    return session;
}
void Cop3530::setNumberOfStudents(int n){
    //mutator for NumberOfStudents
    numberOfStudents = n;
}
int Cop3530::getNumberOfStudents(){
    //accessor for NumberOfStudents
    return numberOfStudents;
}
