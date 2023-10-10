#include <iostream>
#include "SingleLinkedList.h"
#include "Employee.h"

void testSingleLinkedList() {
    std::cout << "Testing Single_Linked_List:\n";

    Single_Linked_List<int> list;

    // Test push_back and size
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    std::cout << "After push_backs, Size: " << list.size() << "\n";

    // Test push_front and size
    list.push_front(0);
    std::cout << "After push_front, Size: " << list.size() << "\n";

    // Test front and back
    std::cout << "Front: " << list.front() << ", Back: " << list.back() << "\n";

    // Test pop_back
    list.pop_back();
    std::cout << "After pop_back, Size: " << list.size() << ", Back: " << list.back() << "\n";

    // Test pop_front
    list.pop_front();
    std::cout << "After pop_front, Size: " << list.size() << ", Front: " << list.front() << "\n";

    // Test insert
    list.insert(1, 4);  // inserting 4 at index 1
    std::cout << "After insert at index 1: Front: " << list.front() << ", Back: " << list.back() << ", Size: " << list.size() << "\n";

    // Test remove
    list.remove(1);  // removing item at index 1 (which is 4)
    std::cout << "After remove at index 1: Front: " << list.front() << ", Back: " << list.back() << ", Size: " << list.size() << "\n";

    // Test find
    size_t position = list.find(2);
    if (position != list.size()) {
        std::cout << "Found item 2 at position: " << position << "\n";
    }
    else {
        std::cout << "Item 2 not found in list.\n";
    }

    // Test empty
    while (!list.empty()) {
        list.pop_front();
    }
    std::cout << "After emptying the list, Size: " << list.size() << "\n";
}


void testEmployee() {
    std::cout << "\nTesting Employee Classes:\n";

    Professional prof(20, 4000, 10);  // hourly rate, monthly salary, vacation days
    Nonprofessional nonprof(15);  // hourly rate

    std::cout << "Professional weekly salary: " << prof.calculate_weekly_salary(40) << "\n";
    std::cout << "Professional health care contributions: " << prof.compute_health_care_contributions() << "\n";
    std::cout << "Professional vacation days: " << prof.compute_vacation_days() << "\n";

    std::cout << "Nonprofessional weekly salary (for 40 hours): " << nonprof.calculate_weekly_salary(40) << "\n";
    std::cout << "Nonprofessional health care contributions: " << nonprof.compute_health_care_contributions() << "\n";
    std::cout << "Nonprofessional vacation days: " << nonprof.compute_vacation_days() << "\n";
}

int main() {
    testSingleLinkedList();
    testEmployee();

    return 0;
}
