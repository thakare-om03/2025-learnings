// **** DO NOT CHANGE the values *****
const a = 18;
const b = 24;

// Addition of two values
function add(a, b) {
  return a + b;
}

// Subtract small value from larger one
function subtract(a, b) {
  if (a < b) {
    return b - a;
  } else {
    return a - b;
  }
}

function multiply(a, b) {
  return a * b;
}

// Divide larger value by small
function divide(a, b) {
  return a / b;
}

// Increase value of a by 1
function increment(a) {
  return a++;
}

// Decrease value of b by 1
function decrement(b) {
  return b--;
}

// Divide larger value by small to find the reminder
function reminder(a, b) {
  if (a < b) {
    return b % a;
  } else {
    return a % b;
  }
}
let addition = console.log(add(a,b))
let subtraction = console.log(subtract(a,b))
let multiplication = console.log(multiply(a,b))
let div = console.log(divide(a,b))
let remainder = console.log(reminder(a,b))