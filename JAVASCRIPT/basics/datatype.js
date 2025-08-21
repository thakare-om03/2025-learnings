// Fundamentals of JavaScript datatypes and variable behavior.
// - Primitives: number, string, boolean, undefined, null (copied by value).
// - Reference types: objects and arrays (copied by reference).
// - let: block-scoped, can be reassigned.
// - const: block-scoped, binding cannot be reassigned (object contents can still change).

// Number (primitive)
let age = 21;
console.log("age:", age, "type:", typeof age);

// String (primitive)
let name = "OM";
console.log("name:", name, "type:", typeof name);

// Boolean (primitive)
let isHireable = false;
console.log("isHireable:", isHireable, "type:", typeof isHireable);

// Object (reference type)
let footballers = { name: "messi", country: "arg" };
console.log("footballers:", footballers, "type:", typeof footballers);

// Array (also a reference type)
let footballer = ["messi", "ronaldo", "neymar"];
console.log("footballer (array):", footballer, "type:", typeof footballer);

// undefined (declared but not initialized)
let isbad;
console.log("isbad (uninitialized):", isbad, "type:", typeof isbad);

// Copying primitives copies the value (independent)
let getage = age;
getage = 30; // modifying getage does not change age
console.log("age (original):", age, "getage (modified):", getage);

// Reassignment with let is allowed
let marvelCharacter = "spiderman";
marvelCharacter = "ironman"; // reassigning the variable
console.log("marvelCharacter (reassigned):", marvelCharacter);

// const binding cannot be reassigned
const names = "thakare";
// names = 'om' // <-- would throw: TypeError: Assignment to constant variable.
console.log("names (const):", names);
