class Employee:
    employee_count = 0

    def __init__(self, name, designation, salary):
        self.name = name
        self.designation = designation
        self.salary = salary
        Employee.employee_count += 1

    def display_employee_info(self):
        print(f"Name: {self.name}, Designation: {self.designation}, Salary: {self.salary}")

# Example usage
employees = [
    Employee("Alice", "Manager", 75000),
    Employee("Bob", "Engineer", 60000),
    Employee("Charlie", "Analyst", 50000)
]

for employee in employees:
    employee.display_employee_info()

print(f"Total number of employees: {Employee.employee_count}")


# output
# Name: Alice, Designation: Manager, Salary: 75000
# Name: Bob, Designation: Engineer, Salary: 60000
# Name: Charlie, Designation: Analyst, Salary: 50000
# Total number of employees: 3