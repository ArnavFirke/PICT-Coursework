// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentContract {
    struct Student {
        int roll;
        string name;
    }

    Student[] private students;

    // Add a student only if the roll number does not already exist
    function add(int roll, string memory name) public {
        for (uint i = 0; i < students.length; i++) {
            if (students[i].roll == roll) {
                revert("Roll number already exists");
            }
        }
        students.push(Student(roll, name));
    }

    // Retrieve all students
    function display() public view returns (Student[] memory) {
        return students;
    }

    // Retrieve a specific student by index (1-based index)
    function display2(uint index) public view returns (int, string memory) {
        require(index > 0 && index <= students.length, "Index out of bounds");
        Student memory student = students[index - 1];
        return (student.roll, student.name);
    }
}
