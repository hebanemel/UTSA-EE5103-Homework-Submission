#include <iostream>
#include <list>
#include <string>

int main()
{
    std::list<std::string> tasks;

    // 1. Add 3 tasks
    tasks.push_back("Read Sensor Values");
    tasks.push_back("Update Control");
    tasks.push_back("Reset Memory");

    // iterator pointing to current task
    auto current = tasks.begin();

    // 2. set current to the first task (begin)
    std::cout << "Current task: " << *current << std::endl;

    // 3. Insert a new task AFTER current
    auto inserted = tasks.insert(std::next(current), "Check Battery");

    // 4. Erase the current task
    // erase returns an iterator to the next element
    current = tasks.erase(current);

    // 5. Advance to the next task (if possible)
    if (current != tasks.end())
    {
        current++;
    }

    // 6. Print entire task list
    std::cout << "\nTask List:" << std::endl;

    for (const auto& task : tasks)
    {
        std::cout << task << std::endl;
    }

    // Print current task
    if (current != tasks.end())
    {
        std::cout << "\nCurrent Task: " << *current << std::endl;
    }
    else
    {
        std::cout << "\nCurrent Task: none" << std::endl;
    }

    return 0;
}

/*
    Explanation:

    std::list was used instead of std::vector because a list allows
    safe insertion and deletion without invalidating other iterators.
    In a vector, inserting or deleting elements can shift memory and
    invalidate iterators pointing to other elements.

    In a std::list (which is a doubly linked list), inserting or
    removing elements does NOT affect iterators to other nodes.
    Only the iterator pointing to the erased element becomes invalid.
    */