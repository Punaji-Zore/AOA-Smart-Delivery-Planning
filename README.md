# Smart Delivery Planning – Fractional Knapsack

## Problem Statement

A delivery company has a vehicle with a fixed carrying capacity. Each package has a certain value and weight. The objective is to maximize the total value carried by the vehicle using the Fractional Knapsack approach.

## Description

This is a menu-driven C program that implements the Greedy Method for solving the Fractional Knapsack problem.

The program:
- Accepts package details and vehicle capacity
- Calculates the Value/Weight ratio
- Sorts packages in decreasing order of ratio
- Selects complete packages whenever possible
- Selects a fraction of a package when required
- Displays selected packages
- Calculates total weight used
- Calculates maximum value obtained

## Algorithm

**Greedy Method – Fractional Knapsack**

The package with the highest Value/Weight ratio is selected first.

## Technologies Used

- C
- Dev-C++

## Time Complexity

The program uses Bubble Sort to arrange packages according to their Value/Weight ratio.

**Time Complexity:** O(n²)

**Space Complexity:** O(n)

## Example

Vehicle Capacity: **15**

| Package | Value | Weight |
|--------:|------:|-------:|
| 1 | 40 | 5 |
| 2 | 30 | 10 |
| 3 | 50 | 5 |
| 4 | 20 | 4 |

**Maximum Value Obtained:** 113

**Total Weight Used:** 15

## Author

Punaji Zore
