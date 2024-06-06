#include <iostream>
#include <queue>
#include <vector>

struct Person {
    std::string name;
    int age;
    Person(std::string name, int age) : name(name), age(age) {}

    //Custom comparator
    bool operator<(const Person &p) const {
        return age > p.age; //min heap
    }
};

int main() {
    //Priority queue with custom data type and comparator
    std::priority_queue<Person> pq;

    pq.push(Person("Alice", 25));
    pq.push(Person("Bob", 30));
    pq.push(Person("Charlie", 20));

    while(!pq.empty())
    {
        Person p = pq.top();
        std::cout << p.name << " " << p.age << std::endl;
        pq.pop();
    }
}