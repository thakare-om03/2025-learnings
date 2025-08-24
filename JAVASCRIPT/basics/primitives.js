// Fundamentals: JavaScript primitive data types
// Primitives are immutable (you can't change them in place) and are copied by value.
// Most frequently used primitives: string, number, boolean, undefined, null, bigint, symbol.
// There are also object wrapper types (String, Number, Boolean) — avoid using `new` with these
// because they create objects, not primitive values, and can cause surprising behavior.

// -------------------------
// String (primitive) — used for text
// -------------------------
let name = "om";
let lastname = "thakare";
let fullname = `${name} ${lastname}`; // primitive string
let newname = new String("thakare"); // String object (wrapper) — typeof -> "object"

console.log(name, typeof name); // "om" "string"
console.log(newname, typeof newname); // [String: 'thakare'] "object"
console.log(fullname, typeof fullname); // [String: 'om thakare'] "object"

// Recommended: use primitive strings. Only use String object intentionally in rare cases.

// -------------------------
// Boolean (primitive) — true / false
// -------------------------
let ishireable = false; // primitive boolean
let newishireable = new Boolean(false); // Boolean object (wrapper)

console.log(ishireable, typeof ishireable); // false "boolean"
console.log(newishireable, typeof newishireable); // [Boolean: false] "object"

// Note: Boolean objects are truthy even if they wrap false, which can be surprising:
// Boolean(new Boolean(false)) === true

// -------------------------
// Number (primitive) — all numeric values (integers and floats)
// -------------------------
let age = 21; // primitive number
let newage = new Number(21); // Number object (wrapper)

console.log(age, typeof age); // 21 "number"
console.log(newage, typeof newage); // [Number: 21] "object"

// Special numeric values: NaN, Infinity (both typeof "number").

// -------------------------
// BigInt — integers with arbitrary precision
// -------------------------
let big = 9007199254740993n; // note the trailing "n"
console.log(big, typeof big); // 9007199254740993n "bigint"

// -------------------------
// Symbol — unique identifiers
// -------------------------
let id = Symbol("id");
console.log(id, typeof id); // Symbol(id) "symbol"

// -------------------------
// undefined — declared but not initialized
// -------------------------
let salary; // no value assigned
console.log(salary, typeof salary); // undefined "undefined"

// -------------------------
// null — explicitly "no value"
// -------------------------
let married = null;
console.log(married, typeof married); // null "object" (historical JS quirk)

// -------------------------
// Summary: avoid wrapper objects (new String/Number/Boolean).
// Use primitives for predictable behavior and better performance.
// -------------------------
