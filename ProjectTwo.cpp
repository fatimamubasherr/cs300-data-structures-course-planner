/*
 * CS 300 – Project Two
 * Advising Assistance Program
 *
 * Student: Fatima Mubasher
 * 
 * This program loads course data from a CSV file,
 * stores it in a Binary Search Tree (BST),
 * prints courses in alphanumeric order,
 * and allows users to look up individual courses
 * and their prerequisites.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// -------------------------------
// Course Structure
// -------------------------------
struct Course {
    string courseNumber;
    string title;
    vector<string> prerequisites;
};

// -------------------------------
// BST Node
// -------------------------------
struct Node {
    Course course;
    Node* left;
    Node* right;

    Node(Course c) {
        course = c;
        left = nullptr;
        right = nullptr;
    }
};

// -------------------------------
// Binary Search Tree Class
// -------------------------------
class BinarySearchTree {
private:
    Node* root;

    void insertNode(Node*& node, Course course) {
        if (node == nullptr) {
            node = new Node(course);
        }
        else if (course.courseNumber < node->course.courseNumber) {
            insertNode(node->left, course);
        }
        else {
            insertNode(node->right, course);
        }
    }

    void inOrder(Node* node) const {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->course.courseNumber << ", "
                 << node->course.title << endl;
            inOrder(node->right);
        }
    }

    Course search(Node* node, const string& courseNumber) const {
        if (node == nullptr) {
            return Course();
        }

        if (node->course.courseNumber == courseNumber) {
            return node->course;
        }
        else if (courseNumber < node->course.courseNumber) {
            return search(node->left, courseNumber);
        }
        else {
            return search(node->right, courseNumber);
        }
    }

    void destroy(Node* node) {
        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    ~BinarySearchTree() {
        destroy(root);
    }

    void Insert(Course course) {
        insertNode(root, course);
    }

    void PrintInOrder() const {
        inOrder(root);
    }

    Course Search(string courseNumber) const {
        return search(root, courseNumber);
    }
};

// -------------------------------
// Utility: Split CSV Line
// -------------------------------
vector<string> split(const string& line) {
    vector<string> tokens;
    string token;
    stringstream ss(line);

    while (getline(ss, token, ',')) {
        tokens.push_back(token);
    }
    return tokens;
}

// -------------------------------
// Load Courses From File
// -------------------------------
void loadCourses(const string& filename, BinarySearchTree& bst) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    string line;

    while (getline(file, line)) {
        vector<string> tokens = split(line);

        if (tokens.size() < 2) {
            continue;
        }

        Course course;
        course.courseNumber = tokens[0];
        course.title = tokens[1];

        for (size_t i = 2; i < tokens.size(); i++) {
            course.prerequisites.push_back(tokens[i]);
        }

        bst.Insert(course);
    }

    file.close();
    cout << "Courses loaded successfully." << endl;
}

// -------------------------------
// Main Program
// -------------------------------
int main() {

    BinarySearchTree bst;
    bool dataLoaded = false;

    cout << "Welcome to the course planner." << endl;

    while (true) {

        cout << endl;
        cout << "1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit" << endl;
        cout << "What would you like to do? ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (choice == 1) {

            string filename;
            cout << "Enter file name: ";
            cin >> filename;

            loadCourses(filename, bst);
            dataLoaded = true;
        }

        else if (choice == 2) {

            if (!dataLoaded) {
                cout << "Please load courses first." << endl;
            }
            else {
                cout << "Here is a sample schedule:" << endl;
                bst.PrintInOrder();
            }
        }

        else if (choice == 3) {

            if (!dataLoaded) {
                cout << "Please load courses first." << endl;
            }
            else {
                string courseNumber;
                cout << "What course do you want to know about? ";
                cin >> courseNumber;

                // Convert to uppercase
                transform(courseNumber.begin(), courseNumber.end(),
                          courseNumber.begin(),
                          [](unsigned char c){ return toupper(c); });

                Course course = bst.Search(courseNumber);

                if (course.courseNumber.empty()) {
                    cout << "Course not found." << endl;
                }
                else {
                    cout << course.courseNumber << ", "
                         << course.title << endl;

                    if (course.prerequisites.empty()) {
                        cout << "Prerequisites: None" << endl;
                    }
                    else {
                        cout << "Prerequisites: ";
                        for (size_t i = 0; i < course.prerequisites.size(); i++) {
                            cout << course.prerequisites[i];
                            if (i < course.prerequisites.size() - 1) {
                                cout << ", ";
                            }
                        }
                        cout << endl;
                    }
                }
            }
        }

        else if (choice == 9) {
            cout << "Thank you for using the course planner!" << endl;
            break;
        }

        else {
            cout << choice << " is not a valid option." << endl;
        }
    }

    return 0;
}

