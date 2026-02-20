#include <iostream>
using namespace std;

int main() {
    char again;

    do {
        double sales[5][4];
        int i, j;

        for (i = 0; i < 5; i++) {
            for (j = 0; j < 4; j++) {
                sales[i][j] = 0;
            }
        }

        int sp, prod;
        double amount;
        char choice;

        cout << "=== Monthly Sales Summary ===" << endl;

        do {
            cout << "\nEnter salesperson number (1-4): ";
            cin >> sp;

            if (sp < 1 || sp > 4) {
                cout << "Invalid." << endl;
            } else {
                cout << "Enter product number (1-5): ";
                cin >> prod;

                if (prod < 1 || prod > 5) {
                    cout << "Invalid." << endl;
                } else {
                    cout << "Enter amount sold: ";
                    cin >> amount;

                    sales[prod - 1][sp - 1] += amount;
                    cout << "Saved!" << endl;
                }
            }

            cout << "Add another? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');

        double rowTotal[5];
        double colTotal[4];
        double grandTotal = 0;

        for (i = 0; i < 5; i++) {
            rowTotal[i] = 0;
        }

        for (j = 0; j < 4; j++) {
            colTotal[j] = 0;
        }

        for (i = 0; i < 5; i++) {
            for (j = 0; j < 4; j++) {
                rowTotal[i] += sales[i][j];
                colTotal[j] += sales[i][j];
                grandTotal += sales[i][j];
            }
        }

        cout << "\n=== Sales Report ===" << endl;
        cout << "\t\tSP1\t\tSP2\t\tSP3\t\tSP4\t\tTotal" << endl;

        for (i = 0; i < 5; i++) {
            cout << "Product " << i + 1 << "\t";
            for (j = 0; j < 4; j++) {
                cout << sales[i][j] << "\t\t";
            }
            cout << rowTotal[i] << endl;
        }

        cout << "Total\t\t";
        for (j = 0; j < 4; j++) {
            cout << colTotal[j] << "\t\t";
        }
        cout << grandTotal << endl;

        cout << "\nGrand Total: " << grandTotal << endl;

        cout << "\nRun again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "Goodbye!" << endl;

    return 0;
}