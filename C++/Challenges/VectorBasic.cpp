/*
 * Declare 2 empty vectors of integers named vector1 and vector2.
 * 
 * Add 10 and 20 to vector1 dynamically using push_back
 * Display the elements in vector1 using the at() method as well as its size
 * using the size() method.
 * 
 * Add 100 and 200 to vector2 dynamically using push_back
 * Display the elements in vector2 using the at() method as well as its size using the size() method.
 * 
 * Declare an empty 2D vector called vector_2d
 * Remember that a 2D vector is a vector of vector<int>
 * 
 * Add vector1 to vector_2d dynamically
 * Add vector2 to vector_2d dynamically
 * 
 * Display the elements in vector_2d using the at() method
 * 
 * Display the elements in vector1
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector <int> vector1;
    vector <int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);
    
    cout << "\nvector1:" << endl;
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;
    cout << "vector1 contains " << vector1.size() << " elements" << endl;
    cout << endl;
    
    vector2.push_back(100);
    vector2.push_back(200);
    
    cout << "\nvector 2: " << endl;
    cout << vector2.at(0) << endl;
    cout << vector2.at(1) << endl;
    cout << "vector2 contains " << vector2.size() << " elements" << endl;
    cout << endl;
    
    vector <vector<int>> vector_2d;
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    cout << "\nvector_2d:" << endl;
    cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;
    cout << endl;
    
    vector1.at(0) = 1000;
    
    cout << "\nvector_2d:" << endl;
    cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;
    cout << endl;
    
    cout << "\nvector1:" << endl;
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;
    cout << "vector1 contains " << vector1.size() << " elements" << endl;
    
    return 0;
}
