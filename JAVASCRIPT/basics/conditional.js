/*
  conditional.js
  Basic examples of conditional statements in JavaScript with short descriptions.

  Fundamentals shown:
  - Comparison operators (>, <, ===, ==)
  - if...else control flow
  - typeof operator to check a value's type
  - Boolean truthiness (how values evaluate in conditions)
  - Array length check to determine emptiness
*/

// Example 1: Comparing two numeric values using >
let num1 = 5;
let num2 = 8;

console.log("I am regular upper code");
// if condition evaluates whether num1 is greater than num2
if (num1 > num2) {
  console.log("num1 is greater than num2");
} else {
  // This branch runs when the condition is false
  console.log("Nope, num1 is NOT greater");
}

console.log("I am regular bottom code");

// Example 2: Comparing strings
// For equality of primitive values it's recommended to use strict equality (===)
// here both variables contain the same string, so the condition is true.
let username = "chai";
let anotherUsername = "chai";

if (username === anotherUsername) {
  // If usernames are identical, we might ask the user to pick another one
  console.log("Pick another username");
} else {
  console.log("You can pick this username");
}

// Example 3: Checking a value's type with typeof
// typeof returns a string describing the type ("number", "string", "boolean", etc.)
// Note: numeric-looking strings are still of type "string"
let score = "44";

if (typeof score === "number") {
  console.log("Yep, this is a number");
} else {
  console.log("No that is not a number");
}

// Example 4: Boolean values and truthiness
// A boolean variable can be true or false; conditions use its truthiness
let isTeaReady = false;

if (isTeaReady) {
  // runs when isTeaReady is true
  console.log("Tea is Ready");
} else {
  // runs when isTeaReady is false (or any falsy value)
  console.log("Tea is NOT ready");
}

// Example 5: Checking if an array is empty using its length property
// An empty array has length 0; length is always a number representing element count
let items = ["item1"];

console.log("items.length =", items.length);

if (items.length === 0) {
  console.log("Array is empty");
} else {
  console.log("Array is NOT empty");
}
