const person = {
  name: "Om",
  age: 21,
  introduce: function () {
    return `Hi, my name is ${this.name} and I am ${this.age} years old`;
  },
};

function outer() {
  return inner();
  function inner() {
    return "Inner function called";
  }
}
let result = console.log(outer());
