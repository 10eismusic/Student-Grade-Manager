#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int choice;
	string studentNames[10] = {};
	int studentGrades[10] = {};
	int studentCount = 0;

	while (true) {
		cout << "Student Grade Manager" << endl;
		cout << "1. Add Student" << endl;
		cout << "2. View All Students" << endl;
		cout << "3. Calculate Class Average" << endl;
		cout << "4. Find Highest Grade" << endl;
		cout << "5. Search for Student" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";

		cin >> choice;

		switch (choice) {
		case 1: {
			if (studentCount >= 10) {
				cout << "Error: Database is full (max 10 students)!" << endl;
			}
			else {
				cout << "Student Name? ";
				cin >> studentNames[studentCount];
				cout << "Student Grade? ";
				cin >> studentGrades[studentCount];
				studentCount++;
				cout << "Student has been added" << endl;
			}
			break;
		}
		case 2: {
			cout << "All Students" << endl;
			if (studentCount == 0) {
				cout << "There are no students in the class" << endl;
			}
			else {
				for (int i = 0; i < studentCount; i++) {
					cout << studentNames[i] << ": " << studentGrades[i] << endl;
				}
			}
			break;
		}
		case 3: {
			if (studentCount == 0) {
				cout << "There are no students in the class yet." << endl;
			}
			else {
				int totalSum = 0;
				for (int i = 0; i < studentCount; i++) {
					totalSum += studentGrades[i];
				}
				double average = (double)totalSum / studentCount;
				cout << "Class Average: " << average << endl;
			}
			break;
		}
		case 4: {
			if (studentCount == 0) {
				cout << "There are no students in the class yet." << endl;
			}
			else {
				int highestGrade = studentGrades[0];
				for (int i = 0; i < studentCount; i++) {
					if (studentGrades[i] > highestGrade) {
						highestGrade = studentGrades[i];
					}
				}
				cout << "The highest grade in the class: " << highestGrade << endl;
			}
			break;
		}
		case 5: {
			string searchName;
			cout << "Who do you want to search for? " << endl;
			cin >> searchName;

			bool found = false;

			for (int i = 0; i < studentCount; i++) {
				if (studentNames[i] == searchName) {
					found = true;
					cout << "Found student! " << studentNames[i] << "'s grade is: " << studentGrades[i] << endl;
					break;
				}
			}
			if (!found) {
				cout << "Student has not been found." << endl;
			}
			break;
		}
		case 6: {
			cout << "Exiting program. Goodbye!" << endl;
			return 0;
		}
		default: {
			cout << "Invalid choice, please try again." << endl;
			break;
		}
		}
	}
	return 0;
}