#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
protected:
    double hourly_rate;

public:
    Employee(double rate) : hourly_rate(rate) {}

    virtual double calculate_weekly_salary(int hours_worked) const = 0;
    virtual double compute_health_care_contributions() const = 0;
    virtual int compute_vacation_days() const = 0;
};

class Professional : public Employee {
private:
    double monthly_salary;
    int vacation_days;

public:
    Professional(double rate, double salary, int days);
    double calculate_weekly_salary(int hours_worked) const override;
    double compute_health_care_contributions() const override;
    int compute_vacation_days() const override;
};

class Nonprofessional : public Employee {
public:
    Nonprofessional(double rate);
    double calculate_weekly_salary(int hours_worked) const override;
    double compute_health_care_contributions() const override;
    int compute_vacation_days() const override;
};

#endif
