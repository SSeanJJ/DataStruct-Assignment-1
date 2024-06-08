# CMSC 3613

## Programming Assignment: Lists

**Due Date:** Check the D2L calendar for the due date.

### Assignment:

Implement a program that uses a contiguous list (list.h) to manage a sequence of personal records. The format of the personal records is defined as a struct in `main.h` as follows.

```cpp
struct Personal_record {
   string first_name;
   string last_name;
   int code;
};
```

You are required to use the contiguous list implementation and the main program provided by the instructor. The following functions should be implemented in the program.

1. Insert every record read from a data file into the contiguous list (`record_list`) declared in `main.cpp` in ascending alphabetical order based on the last name of the record. For records with the same last name, break the tie using the first name. If a record already exists with the same first and last name in the list, the new record should be discarded instead of being inserted into the list.
2. Print the content of the list using the following format for each record.
   ```
   Last Name:
   First Name:
   Code:
   ```
3. Use sequential search to look for a record in the list based on user-specified first and last names. Display the record using the same format as that of Item 2 (see above). If the record is not found, display “Not found”.

### Requirements:

- Fill in the code segment required in the `main.cpp` file.
- The program is menu-driven. You can import a list of records from a given data file.

### Test Files:

- One test data file `data.txt` is provided.

### Submission:

Create a folder named `assignment1` in your CS server account. All source code should be put in the folder. The code should NOT be modified after the due date. Altered code will be considered late.

- Make sure that the instructor can use `make` to compile and build the program and run it.
- Submit a report in Assignment 1 of D2L Assignments. The report should include the following items:
  - Your name and UCO student ID
  - The assignment number
  - Your server username (all of the above: 10 pts)
  - Do not submit the password!
  - A brief discussion (10 pts):
    - Is there a better way to implement the search function? Explain your suggestion.
  - Also submit your `main.cpp` source file in Assignment 1 of D2L Assignments. (80 pts)

**Note 1:** Do NOT submit any other part of the program.  
**Note 2:** Do not use Zip. Upload your report and `main.cpp` as separate files in D2L for submission.

### Notes:

- To be considered on time, the program must be turned in before the due date.
- Programs must reflect your knowledge and work, not others.
- No points, zero (0), will be given to any program containing compilation errors.
- Program grades reflect both the performance of the program and the programming style of the program.

```

```
