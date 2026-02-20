#include <iostream>
using namespace std;

int main() {

    char again;

    do {

        int students, quizzes;

        cout << "Enter how many students: ";
        cin >> students;

        cout << "Enter how many quizzes: ";
        cin >> quizzes;

        double scores[students][quizzes];

        for(int i = 0; i < students; i++) {
            cout << "\nEnter scores for Student " << i + 1 << endl;

            for(int j = 0; j < quizzes; j++) {
                cout << "Quiz " << j + 1 << ": ";
                cin >> scores[i][j];
            }
        }

        cout<<endl;
        cout<<endl;

        cout << "Student\t";

        for(int j = 0; j < quizzes; j++) {
            cout << "Q" << j + 1 << "\t";
        }

        cout << "Average";
        cout << endl;

        for(int i = 0; i < students; i++) {

            double sum = 0;

            cout << i + 1 << "\t";

            for(int j = 0; j < quizzes; j++) {
                cout << scores[i][j] << "\t";
                sum += scores[i][j];
            }

            double average = sum / quizzes;

            cout << average;
            cout << endl;
        }

        cout << "\nDo you want to try again (y/n): ";
        cin >> again;

    } while(again == 'y' || again == 'Y');

    cout << "\nProgram ended.";

    return 0;
}
