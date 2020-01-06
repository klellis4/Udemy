/*
 * Your challenge for section 11 is to modularize your solution to the Section 9 challenge
 * by refactoring your solution so that it uses functions.
 * 
 * You decide how to modularize the program.
 * 
 * Hints:
 *  - Create functions for each major function
 *  - Keep the functions small
 *  - Remember the Boss/Worker analogy
 *  - Keep the vector declaration in the main function and pass the vector object
 *      to any function that requires it
 * 
 * Do NOT move the vector object outside main and make it a global variable.
 * 
 * You can start by defining a function that displays the menu
 * You can then define a function that reads the selection from the user and returns it in uppercase
 * Create functions for each menu option
 * Create functions that display the list of numbers, calculates the mean, and so forth.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void display_menu();
char selection_to_upper(char);
void print_list(vector<int> list);
void add_number(vector<int> &list);
void find_average(vector<int> list);
void find_smallest(vector<int> list);
void find_largest(vector<int> list);
void search_for_num(vector<int> list);
void clear_list(vector<int> &list);
void remove_element(vector<int> &list);

int main() {
    
    char selection {};
    char selection_upper {};
    vector <int> list {};
    
    do {
        display_menu();
        cin >> selection;
        selection_upper = selection_to_upper(selection);
        
        switch (selection_upper) {
            // Print list
            case 'P':
                print_list(list);
                break;
            case 'A':
                add_number(list);
                break;
            case 'M':
                find_average(list);
                break;
            case 'S':
                find_smallest(list);
                break;
            case 'L':
                find_largest(list);
                break;
            case 'F':
                search_for_num(list);
                break;
            case 'C':
                clear_list(list);
                break;
            case 'R':
                remove_element(list);
                break;
            case 'Q':
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Unknown selection, please try again." << endl;
        }
    } while (selection_upper != 'Q');
    
    cout << endl;
    return 0;
}

void display_menu() {
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display the mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "F - Find a number in the list and display how many times it appears" << endl;
        cout << "C - Clear out the list" << endl;
        cout << "R - Remove a number from the list" << endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter your choice: ";
}

// Changes the user's selection to upper case for easier switch statement
char selection_to_upper(char sel) {
    return toupper(sel);
}

// Prints the current vector
void print_list(vector<int> list) {
    if (list.size() != 0) {
        cout << "[ ";
        for (auto num : list) {
            cout << num << " ";
        }
        cout << "]" << endl;
    } else {
        cout << "[] - list is empty" << endl;
    }
}

// Adds a number to the vector based on user input - does NOT allow for duplicate entries
void add_number(vector<int> &list) {
    int num {};
    cout << "Enter the number you'd like to add: ";
    cin >> num;
    bool exists {false};
    for (unsigned int i {0}; i < list.size(); i++) {
        if (list.at(i) == num) {
            exists = true;
        }
    }
    if (!exists) {
        list.push_back(num);
        cout << num << " added." << endl;
    } else {
        cout << "Sorry, no duplicate entries allowed." << endl;
    }
}

// Computes the mean of the entries in the vector
void find_average(vector<int> list) {
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
}

// Finds the smallest number in the vector
void find_smallest(vector<int> list) {
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
}

// Finds the largest number in the vector
void find_largest(vector<int> list) {
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
}

// Searches for a number that the user inputs in the vector.
// If it exists, output the number of times it appears
void search_for_num(vector<int> list) {
    int count {};
    int target {};
    cout << "Enter the number you wish to find: ";
    cin >> target;
    for (auto num : list) {
        if (num == target) {
            count++;
        }
    }
    if (count != 0) {
        cout << "The number " << target << " appears " << count << " times in the list." << endl;
    }
    else {
        cout << "The number " << target << " is not in the list." << endl;
    }
}

// Clears out the vector
void clear_list(vector<int> &list) {
    if (list.size() != 0) {
        list.clear();
        cout << "The list has been cleared." << endl;
    }
    else {
        cout << "The list is already empty." << endl;
    }
}

// Removes an element from the vector based on user input
void remove_element(vector<int> &list) {
    int target {};
    bool exists {false};
    cout << "Enter the number you wish to delete: ";
    cin >> target;
    for (unsigned int i {0}; i < list.size(); i++) {
        if (list.at(i) == target) {
            list.erase(list.begin() + i);
            exists = true;
            cout << target << " was deleted." << endl;
        }
    }
    if (!exists) {
        cout << target << " was not in the list." << endl;
    }
}
