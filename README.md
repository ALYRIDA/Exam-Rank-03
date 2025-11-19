# Exam-Rank-03
Exam Rank 03 - My Solutions
Level 1 Solutions
1. get_next_line.c
Simplified line reading implementation

Uses static buffer for persistence between calls

Reads in chunks defined by BUFFER_SIZE

Returns one line per call, NULL on EOF

Handles basic memory allocation

Key Features:

Static buffer management

Simple malloc approach

Direct file descriptor reading

2. filter.c
Text filtering with pattern replacement

Reads from stdin and replaces specified patterns with asterisks

Handles buffer concatenation for large inputs

Memory efficient with proper cleanup

Key Functions:

ft_check_replace() - Replaces target string with '*'

ft_strjoin() - Concatenates buffers

Robust error handling with proper memory freeing

3. scanf.c
Custom scanf implementation

Supports %c, %d, %s format specifiers

Handles whitespace skipping

Works with FILE streams and stdin

Key Functions:

scan_char(), scan_int(), scan_string() - Type-specific parsers

match_space() - Skips whitespace

ft_vfscanf() - Core parsing logic

Level 2 Solutions
1. permutations.c
Generates all string permutations in lexicographic order

Sorts input first for ordered output

Uses backtracking with recursion

Tracks used characters with boolean array

Algorithm:

Sort input string

Recursive backtracking to build permutations

Marks used positions to avoid repetition

2. powerset.c
Finds all subsets that sum to target value

Uses bitmask approach (2^n combinations)

Efficient subset generation

Prints valid subsets that match target sum

Approach:

Iterate through all 2^n possible subsets

Calculate sum for each bitmask

Print subsets that match target

3. rip.c
Removes invalid parentheses to make string valid

Calculates minimum removals needed

Uses recursive backtracking to try removals

Outputs all valid results

Process:

Count invalid parentheses

Recursively remove parentheses

Validate and print correct results

Common Strengths
Memory Management: Proper allocation and freeing

Error Handling: Robust input validation

Algorithm Efficiency: Appropriate approaches for each problem

Code Readability: Clear logic and structure

Compilation & Usage
All programs compile with standard C flags and handle edge cases appropriately. Each solution demonstrates understanding of fundamental algorithms and C programming concepts required for Exam Rank 03.
