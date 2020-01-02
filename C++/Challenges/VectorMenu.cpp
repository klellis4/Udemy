/*
 * This challenge is about using a collection (list) of integers and allowing the user
 * to select options from a menu to perform operations on the list.
 * 
 * Your program should display menu options to the user as follows:
 * 
 * P - Print numbers
 * A - Add a number
 * M - Display the mean of the numbers
 * S - Display the smallest number
 * L - Display the largest number
 * Q - Quit
 * 
 * Enter your choice:
 * 
 * The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
 * If an illegal choice is made, you should display "Unknown selection, please try again" and the menu options should
 * be displayed again.
 * 
 * If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
 * If the list is empty you should display "[] - the list is empty."
 * If the list is not empty then all the list elements should be displayed inside square brackets separated
 * by a space.
 * For example, [1 2 3 4 5]
 * 
 * If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list
 * which you will add and then display that it was added. For example, if the user enters 5, you
 * should display "5 added"
 * Diplicate list entries are OK.
 * 
 * If the user enters 'M' or 'm' you should calculate the mean or average of the elements in the list and display it.
 * If the list is empty you should display, "Unable to calculate the mean - no data"
 * 
 * If the user enters 'S' or 's' you should display the smallest element in the list.
 * For example, if the list contains [2 4 5 1], you should display "The smallest number is 1"
 * If the list is empty you should display "Unable to determine the smallest number - list is empty"
 * 
 * If the user enters 'L' or 'l' you should display the largest element in the list
 * For example, if the list contains [2 4 5 1] you should display "The largest number is 5"
 * If the list is empty you should display "Unable to determine the largest number - list is empty"
 * 
 * If the user enters 'Q' or 'q' then you should display "Goodbye" and the program should terminate.
 * 
 * Additional functionality if you wish to extend this program:
 * 
 * - search for a number in the list and if found then display the number of times it occurs in the list
 * - clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
 * - don't allow duplicate entries
 * - come up with your own ideas!
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    char selection {};
    vector <int> list {};
    
    do {
        // print menu
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display the mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter your choice: ";
        cin >> selection;

        switch (selection) {
            // Print list
            case 'p':
            case 'P':
                if (list.size() != 0) {
                    cout << "[ ";
                    for (auto num : list) {
                        cout << num << " ";
                    }
                    cout << "]" << endl;
                } else {
                    cout << "[] - list is empty" << endl;
                }
                break;
            // Add number to list
            case 'a':
            case 'A': {
                int num {};
                cout << "Enter the number you'd like to add: ";
                cin >> num;
                list.push_back(num);
                cout << endl;
                cout << num << " added." << endl;
                break;
            }
            // Find average
            case 'm':
            case 'M': {
                int total {};
                double average {};
                if (list.size() != 0) {
                    for (auto num : list) {
                        total += num;
                    }
                    average = static_cast<double>(total) / list.size();
                    cout << "The average is: " << average << endl;
                    
                } else {
                    cout << "Unable to calculate the mean - list is empty" << endl;
                }
                break;
            }
            // Find smallest number
            case 's':
            case 'S': {
                if (list.size() != 0) {
                    int small {list.at(0)};
                    for (unsigned int i {0}; i < list.size(); i++) {
                        if (small > list.at(i)) {
                            small = list.at(i);
                        }
                    }
                    cout << "The smallest number is: " << small << endl;
                } else {
                    cout << "Unable to determine the smallest number - list is empty" << endl;
                }
                break;
            }
            // Find largest number
            case 'l':
            case 'L': {
                if (list.size() != 0) {
                    int large {list.at(0)};
                    for (unsigned int i {0}; i < list.size(); i++) {
                        if (large < list.at(i)) {
                            large = list.at(i);
                        }
                    }
                    cout << "The largest number is: " << large << endl;
                } else {
                    cout << "Unable to determine the largest number - list is empty" << endl;
                }
                break;
            }
            // Quit
            case 'q':
            case 'Q':
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Unknown selection, please try again." << endl;
        }
        
    } while (selection != 'q' && selection != 'Q');
    
    return 0;
}
