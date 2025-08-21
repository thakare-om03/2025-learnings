// File: logicalop.js
// Description: Basic examples of JavaScript logical operators (AND, OR, NOT)
// Fundamentals:
// - && (AND): true only if both operands are true
// - || (OR): true if at least one operand is true
// - ! (NOT): flips the boolean value (true -> false, false -> true)

let isLoggedin = true;
let isWorking = false;

// AND: true only when both are true
// Here isLoggedin is true, isWorking is false -> overall false
console.log(isLoggedin && isWorking); // expected output: false

// OR: true when at least one is true
// Here at least one (isLoggedin) is true -> overall true
console.log(isLoggedin || isWorking); // expected output: true

// NOT: negation of the value
console.log(!isLoggedin); // expected output: false (because isLoggedin is true)
console.log(!isWorking); // expected output: true  (because isWorking is false)
