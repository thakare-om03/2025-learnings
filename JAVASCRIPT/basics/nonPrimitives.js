// nonPrimitives.js
// Demonstrates basic non-primitive types in JavaScript: objects, arrays, Date,
// and simple type conversion with Number(). Comments explain fundamentals.

// An object literal. Objects store key-value pairs.
// Keys can be identifiers or strings (use quotes if key contains spaces).
const username = {
  "first name": "hitesh", // property name with a space requires bracket notation to access
  isLoggedin: true,       // boolean property
};

// You can add or update properties after the object is created.
// Dot notation works for identifier-like keys (no spaces, starts with letter/underscore).
username.firstname = "Mr. H";   // creates a new property 'firstname'
username.lastname = "choudhary"; // creates a new property 'lastname'

// Accessing properties:
// - Bracket notation is needed for keys with spaces or dynamically computed keys.
console.log(username["first name"]); // "hitesh"
console.log(username.lastname);      // "choudhary"
console.log(username);               // prints the whole object
console.log(typeof username);        // "object" -> objects are non-primitive

// Date: built-in object representing time. Use its methods to get parts.
let today = new Date();
console.log(today.getDate()); // day of month (1-31)

// Arrays: ordered lists of values. Arrays are objects but indexed numerically.
let anotherUser = ["hitesh", true];
console.log(anotherUser[0]); // access first element

// Type conversion with Number():
// - Number(string) attempts to parse a numeric value, returns NaN if invalid.
// - Number(null) -> 0, Number(undefined) -> NaN
let isValue = "2abc";
console.log(typeof Number(isValue)); // "number" (value will be NaN)
console.log(Number(isValue));        // NaN (Not-a-Number)
console.log(Number(null));           // 0

// Notes on fundamentals:
// - Primitives: string, number, boolean, null, undefined, symbol, bigint.
// - Non-primitives: objects (including arrays, functions, dates).
// - Objects are assigned/copied by reference; primitives by value.
// - Use typeof to get the type of a value, but typeof null === "object" is a historical quirk.
