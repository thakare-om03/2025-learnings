// Task 1
const person = {
  name: "OM",
  introduce: function () {
    console.log(`Hi. my name is ${this.name}`);
  },
};
const introduceFn = person.introduce.bind(person);
console.log(introduceFn());

// Task 2
function introduce() {
  return `Hi, I'm ${this.name}`;
}

const person1 = { name: "Rajesh" };
const person2 = { name: "Shilpa" };

console.log(introduce.call(person1));
console.log(introduce.call(person2));

// Task 3
function sum(a, b) {
  return (a + b) * this.multiplier;
}

const context1 = { multiplier: 2 };
const context2 = { multiplier: 3 };

console.log(sum.apply(context1, [4, 5]));
console.log(sum.apply(context2, [4, 5]));
