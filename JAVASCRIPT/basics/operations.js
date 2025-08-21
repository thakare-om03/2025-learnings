/**
 * fundamentals: basic arithmetic, assignment, increment/decrement, and comparisons
 * This file demonstrates common JavaScript operators and prints results to the console.
 * Use these short examples to understand how values are calculated and compared.
 */

// --- Addition ---
// The + operator adds numbers (or concatenates strings).
let addition = 10 + 50;
console.log("Addition (10 + 50):", addition);

// --- Variable assignment ---
// Variables hold values that can be reused later.
let base = 11000; // base salary
let bonus = 5000; // bonus amount

// Calculate total salary by adding two variables.
let totalSalary = base + bonus;
console.log("Total salary (base + bonus):", totalSalary);

// --- Division ---
// The / operator divides the left operand by the right.
let div = 8 / 2;
console.log("Division (8 / 2):", div);

// --- Exponentiation ---
// The ** operator raises the left operand to the power of the right.
let expo = 2 ** 3; // 2 to the power of 3
console.log("Exponentiation (2 ** 3):", expo);

// --- Modulo (remainder) ---
// The % operator returns the remainder after division.
let mod = 10 % 3; // remainder of 10 divided by 3
console.log("Modulo (10 % 3):", mod);

// --- Subtraction ---
// The - operator subtracts the right operand from the left.
let sub = 10 - 3;
console.log("Subtraction (10 - 3):", sub);

// --- Multiplication ---
// The * operator multiplies two numbers.
let mul = 10 * 3;
console.log("Multiplication (10 * 3):", mul);

// --- Increment & Decrement ---
// ++ increases a number by 1, -- decreases a number by 1.
let inc = 10;
inc++; // inc is now 11
let credits = 100;
credits--; // credits is now 99
console.log("Increment result (inc):", inc);
console.log("Decrement result (credits):", credits);

// --- Comparisons ---
// Comparison operators return boolean values (true or false).
let num1 = 10;
let num2 = 20;
console.log("Equal (num1 == num2):", num1 == num2); // loose equality
console.log("Not equal (num1 != num2):", num1 != num2); // loose inequality
console.log("Greater than (num1 > num2):", num1 > num2);
console.log("Less than (num1 < num2):", num1 < num2);
console.log("Greater or equal (num1 >= num2):", num1 >= num2);
console.log("Less or equal (num1 <= num2):", num1 <= num2);

// Tip: Prefer strict equality (===) and strict inequality (!==) in real code
// to avoid unexpected type-coercion behavior.
