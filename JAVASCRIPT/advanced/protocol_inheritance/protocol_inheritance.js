function Person(name) {
  this.name = name;
}

Person.prototype.greet = function () {
  console.log(`Hi, my name is ${this.name}`);
};

let om = new Person("Om");
om.greet();