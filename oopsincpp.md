Object oriented programming
topics - 
1 - Class
2 - Object
3 - encapsulation
4 - inheritance
5 - polymorphism
6 - abstraction
7- internface
 ----------------------------
 Class ->
 Only 9 types of classes are provided in general, namely, abstract, final, mutable, wrapper, anonymous, input-output, string, system, network. We may further divide the classes into parent class and subclass if inheritance is used.

 Classes are pass by reference, and the structures are pass by copy. It doesn’t depend on the program.

class Student 
{
    int a; 
    public : float a; 
};

Same variable can’t be defined twice in same scope. Even if the data types are different, variable name must be different. There is no rule like Public member should come first or last.

Template classes are known to be generic classes because those can be used for any data type value and the same class can be used for all the variables of different data types.

Classes doesn’t have any size, actually the size of object of the class can be defined. That is done only when an object is created and its constructor is called.

Abstract classes can have member functions with no implementation, where the inheriting subclasses must implement those functions.

A friend class can access all the private members of another class, of which it is a friend. It is a special class provided to use when you need to reuse the data of a class but don’t want that class to have those special functions. 

The class containing main function can be inherited and hence the program can be executed using the derived class names also in java.

Member functions must be declared inside class body, though the definition can be given outside the class body. There is no way to declare the member functions outside the class.

Class definition must end with a semicolon, not colon. Class can have only member functions in its body with no data members.

Instance of abstract class can’t be created as it will not have any constructor of its own, hence while creating an instance of class, it can’t initialize the object members. Actually the class inheriting the abstract class can have its instance because it will have implementation of all members

    ---Blueprint of an object
    ---has own member functions and data types
    Access the data members --->
        Pointers --- ->
        normal objects  --- .
    Member functions -->
            Inline functions
            Scope resolution
                example -->
                double Box::getVolume(void) {
                    return length * breadth * height;
                }
Constructor is also a member function.

In case of parameterized constructor, you can use following syntax to initialize the fields −

Line::Line( double len): length(len) {
   cout << "Object is being created, length = " << len << endl;
}
Above syntax is equal to the following syntax −

Line::Line( double len) {
   cout << "Object is being created, length = " << len << endl;
   length = len;
}

C::C( double a, double b, double c): X(a), Y(b), Z(c) {
   ....
}