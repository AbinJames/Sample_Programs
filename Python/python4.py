
data = None;
courses = []
students = []
grades = []
output = []
while data != 'EndOfInput':
    data = input()
    if data == 'Courses':
        data = input()
        while data not in ['Grades', 'Students', 'EndOfInput']:
            courses = courses + [data.split("~")]
            data = input()
    if data == 'Students':
        data = input()
        while data not in ['Grades', 'Courses', 'EndOfInput']:
            students = students + [data.split("~")]
            data = input()
    if data == 'Grades':
        data = input()
        while data not in ['Students', 'Courses', 'EndOfInput']:
            grades = grades + [data.split("~")]
            data = input()
i = 0
students.sort()
for x in students:
    y = students[i][0]
    j = 0
    sum = 0
    for w in grades:
        if y in w:
                n = 0
                if 'A' in w:
                    n = 10
                elif 'AB' in w:
                    n = 9
                elif 'B' in w:
                    n = 8
                elif 'BC' in w:
                    n = 7
                elif 'C' in w:
                    n = 6
                elif 'CD' in w:
                    n = 5
                elif 'D' in w:
                    n = 4
                j = j + 1
                sum = sum + n
    if j==0:
        avg = 0
    else:
        avg = sum/j
    avg = round(avg,2)
    students[i] = students[i] + [str(avg)]
    students[i] = "~".join(students[i])
    print(students[i])
    i = i + 1