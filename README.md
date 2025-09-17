# Study Hours Tracker (C Language)

This repository contains a C program developed as part of my **Problem Solving portfolio** at Solent University.  
The program tracks study hours for up to ten subjects across two consecutive weeks, checks against a weekly study goal, and provides a per-subject comparison of hours.

## Features
- Input validation to prevent negative or invalid values.
- Flexible: supports 1 to 10 subjects (user-defined).
- Calculates and displays total study hours per week.
- Checks whether the weekly goal was met for each week.
- Compares Week 1 and Week 2 totals (increase / decrease / no change).
- Shows per-subject changes between weeks.

## Example Output
```text
How many subjects? (1-10): 3
Name for subject 1 (no spaces): Maths
Name for subject 2 (no spaces): Programming
Name for subject 3 (no spaces): Networking
Weekly study goal (hours): 10

-- WEEK 1 --
Maths hours: 4
Programming hours: 3
Networking hours: 3

-- WEEK 2 --
Maths hours: 5
Programming hours: 5
Networking hours: 5

WEEK 1 TOTAL: 10.00
Goal (10.00): Met

WEEK 2 TOTAL: 15.00
Goal (10.00): Met

Total comparison (W1 -> W2): Increased by 5.00

Per-subject changes (W1 -> W2):
Maths: Increased by 1.00
Programming: Increased by 2.00
Networking: Increased by 2.00
