#include "Employee.h"

Professional::Professional(double rate, double salary, int days) : Employee(rate), monthly_salary(salary), vacation_days(days) {}

double Professional::calculate_weekly_salary(int hours_worked) const {
    return monthly_salary / 4;  // assuming 4 weeks in a month
}

double Professional::compute_health_care_contributions() const {
    return monthly_salary * 0.05; // just a dummy rule, 5% of monthly salary
}

int Professional::compute_vacation_days() const {
    return vacation_days;
}

Nonprofessional::Nonprofessional(double rate) : Employee(rate) {}

double Nonprofessional::calculate_weekly_salary(int hours_worked) const {
    return hourly_rate * hours_worked;
}

double Nonprofessional::compute_health_care_contributions() const {
    return hourly_rate * 40 * 0.03; // assuming 40 hour work week, 3% of weekly salary
}

int Nonprofessional::compute_vacation_days() const {
    return 0;  // dummy rule: nonprofessionals don't get vacation days in this example
}
