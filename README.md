# cs300-data-structures-course-planner
Course Planner application built using a Binary Search Tree with runtime analysis comparing vector, hash table, and BST implementations. Developed for CS 300 at SNHU.

_

Course Planner Project

This repository contains my work from CS 300 at Southern New Hampshire University. The project focused on selecting and implementing an appropriate data structure to support an academic course planner system.

The submission includes:
	•	Project One: Runtime and memory analysis of vector, hash table, and binary search tree implementations
	•	Project Two: Working Course Planner application implemented using a Binary Search Tree

___

Problem Being Solved

The goal of the project was to design a program that would allow academic advisors to:
	1.	Print a list of Computer Science courses in alphanumeric order
	2.	Display detailed information about a specific course, including its prerequisites

The challenge was not simply writing a program that worked, but selecting and justifying an appropriate data structure based on performance and scalability considerations.

___

Approach and Importance of Data Structures

I approached this problem by first analyzing how different data structures would perform during course loading, searching, and sorted output.

In Project One, I compared:
	•	Vector
	•	Hash Table
	•	Binary Search Tree

I evaluated runtime complexity for file loading, insertion, searching, and sorting, as well as memory implications. While vectors were simple and hash tables provided fast lookup, the Binary Search Tree provided a natural solution for sorted output using in-order traversal.

Understanding data structures is critical because the structure chosen determines performance behavior. A correct solution is not enough in software development. The solution must also scale efficiently and remain maintainable.

___

Roadblocks and Debugging

One of the biggest roadblocks in Project Two was ensuring the program strictly followed assignment specifications while remaining stable.

For example, I had to carefully validate user input, prevent operations before data was loaded, and debug a compile issue caused by a small syntax error. This reinforced how small mistakes can prevent an entire program from building, even if the overall structure is correct.

I also worked to improve normalization and search behavior to ensure consistent lookups regardless of input formatting.

___

Growth in Software Design

This project expanded how I think about software design. Instead of immediately coding, I now evaluate:
	•	Expected operations
	•	Runtime tradeoffs
	•	Memory implications
	•	Worst-case vs average-case behavior

Choosing a Binary Search Tree was not accidental. It was based on aligning structure behavior with the advisor’s requirement for alphanumeric printing.

This project strengthened my ability to reason about performance before implementation.

___

Writing Maintainable and Adaptable Code

Through this project, I focused on:
	•	Separating concerns (loading, searching, printing)
	•	Writing readable function structures
	•	Adding input validation
	•	Preventing partial data loading
	•	Designing with future scalability in mind

I also learned the importance of normalizing input data and validating file formats early to prevent downstream errors.

The result is a Course Planner that is not only functional but logically structured and adaptable.

___

Portfolio Value

From this project, I can demonstrate to employers:
	•	Practical implementation of a Binary Search Tree
	•	Understanding of runtime complexity analysis
	•	Comparison and justification of multiple data structures
	•	Debugging and input validation
	•	Clean separation of algorithmic logic

This project reflects foundational algorithmic thinking and structured program design, which are essential for software engineering roles.
