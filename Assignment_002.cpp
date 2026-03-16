#include <iostream>
using namespace std;

void analyzeGrades(int *grades, int students, int subjects)
{
    int highest = *(grades);

    cout << "\nGrade Matrix:\n";

    for(int i = 0; i < students; i++)
    {
        int sum = 0;

        for(int j = 0; j < subjects; j++)
        {
            int value = *(grades + i * subjects + j);

            cout << value << " ";
            sum += value;

            if(value > highest)
                highest = value;
        }

        double average = (double)sum / subjects;
        cout << " | Average: " << average;

        cout << endl;
    }

    cout << "\nHighest grade in matrix: " << highest << endl;
}

int main()
{
    int students, subjects;

    cout << "Enter number of students: ";
    cin >> students;

    cout << "Enter number of subjects: ";
    cin >> subjects;

    int grades[students][subjects];

    cout << "\nEnter grades:\n";

    for(int i = 0; i < students; i++)
    {
        cout << "Student " << i+1 << ":\n";

        for(int j = 0; j < subjects; j++)
        {
            cout << "Subject " << j+1 << ": ";
            cin >> grades[i][j];
        }
    }

    analyzeGrades(&grades[0][0], students, subjects);

    return 0;
}