// fundamentals: let vs const
// - let: block-scoped variable that can be reassigned.
// - const: block-scoped binding that cannot be reassigned. (Note: objects/arrays declared with const can still be mutated.)
// Prefer const by default and use let when you know the value will change.

let gameName = "spiderman ps4"; // initial value
gameName = "spiderman miles morales"; // allowed: let can be reassigned
console.log("gameName:", gameName);

const username = "omthakare"; // value that should not be reassigned
// username = "omthakare1"; // <-- would throw: TypeError: Assignment to constant variable.
console.log("username:", username);

// Example showing mutation vs reassignment for const:
// objects declared with const cannot be rebound, but their properties can change.
const player = { name: "omthakare" };
player.name = "omthakare1"; // allowed: mutation of object property
console.log("player:", player);
