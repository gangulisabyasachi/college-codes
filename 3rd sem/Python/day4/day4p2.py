class Student:
    college_name = "HITK"
    student_count = 0

    def __init__(self, stdid, name, marks):
        self.stdid = stdid
        self.name = name
        self.marks = marks
        self.average = sum(marks) / len(marks)
        self.grade = self.calculate_grade(self.average)
        Student.student_count += 1

    def calculate_grade(self, average):
        if average >= 90:
            return 'O'
        elif average >= 80:
            return 'A'
        elif average >= 70:
            return 'B'
        elif average >= 60:
            return 'C'
        elif average >= 50:
            return 'D'
        else:
            return 'F'

    def display_student_info(self):
        print(f"{self.stdid} \t {self.name} \t {self.marks[0]} \t {self.marks[1]} \t {self.marks[2]} \t {self.average:.2f} \t {self.grade}")

# Input data
students = [
    Student(1, "AAA", [90, 90, 90]),
    Student(2, "BBB", [70, 70, 70]),
    Student(3, "CCC", [10, 30, 40]),
    Student(4, "DDD", [5, 50, 50]),
    Student(5, "EEE", [56, 57, 58])
]

# Display results
print(f"College Name: {Student.college_name}")
print(f"Total Number of Students: {Student.student_count}")
print("ID \t Name \t Sub1 \t Sub2 \t Sub3 \t Average \t Grade")

for student in students:
    student.display_student_info()


# output
# College Name: HITK
# Total Number of Students: 5
# ID       Name    Sub1    Sub2    Sub3    Average         Grade
# 1        AAA     90      90      90      90.00   O
# 2        BBB     70      70      70      70.00   B
# 3        CCC     10      30      40      26.67   F
# 4        DDD     5       50      50      35.00   F
# 5        EEE     56      57      58      57.00   D

