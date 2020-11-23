/*
Here we create custom class for
Priority queue.

greater<int> was the class for ascending ordering. i.e. min heap -> min priority queue.

We need to make our custom.
Let's do this.

Here we are creating a queue
And the priority is given to the person with the biggest age.

*/

#include <iostream>
#include <queue>
#include <string>


using namespace std;


class Person {
public:
    string name;
    int age;

    Person() {
        name = "Default";
        age = 0;
    }

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
};


class PersonCompare {
public:
    /*
        this is bascially operator overloading
        We are overloading the parenthesis
        So that when the object created from PersonCompare is called
        We are acutally creating the __call__ method that we use in Python.
    */
    bool operator()(Person A, Person B) {
        return A.age < B.age;
    }
};


int main() {
    // priority queue based on PersonCompare
    priority_queue<Person, vector<Person>, PersonCompare> pq;

    int n = 5;
    while (n--) {
        string name;
        int age;
        cin >> name >> age;
        cout << name << age;

        Person p(name, age);
        pq.push(p);
    }

    while (!pq.empty()) {
        Person val = pq.top();
        cout << "Name: " << val.name << ", Age: " << val.age << endl;
        pq.pop();
    }

    // You can get the top 3 most aged people.
    // You would just need to get the top 3 times.
    // popping 3 times, means 3*O(logn).
    // accessing the top 3 times, means 3*O(1)
    // Complexity: 3 * O(logn) + 3 * O(1) = O(logn)
    return 0;
}
