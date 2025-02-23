function stringToNumber(input) {
  const num = Number(input);
  return isNaN(num) ? "Not a number" : num;
}

function flipBoolean(input) {
  return !Boolean(input);
}

function whatAmI(input) {
  const type = typeof input;
  if (type == "number") return "I'm a number!";
  if (type == "string") return "I'm a string!";
  return `I'm a ${type}!`;
}

function isItTruthy(input) {
  return input ? "It's truthy!" : "It's falsey!";
}

let result = console.log(
  stringToNumber("Om"),
  flipBoolean(0),
  whatAmI("Om"),
  isItTruthy("HI")
);
