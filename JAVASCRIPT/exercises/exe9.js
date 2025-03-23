function Animal() {}
Animal.prototype.makeSound = function () {
  return "Some generic sound";
};

function Dog() {}

Dog.prototype = Object.create(Animal.prototype); // Inherit from Animal
Dog.prototype.bark = function () {
  return "Woof!";
};

// Example usage
const dog = new Dog();
console.log(dog.makeSound()); // "Some generic sound"
console.log(dog.bark()); // "Woof!"


function Shape(color) {
    this.color = color;
}

Shape.prototype.getColor = function () {
    return this.color;
};

function Rectangle(width, height, color) {
    Shape.call(this, color); // Call Shape constructor
    this.width = width;
    this.height = height;
}

Rectangle.prototype = Object.create(Shape.prototype); // Inherit from Shape
Rectangle.prototype.getArea = function () {
    return this.width * this.height;
};

// Example usage
const rect = new Rectangle(10, 5, "blue");
console.log(rect.getColor()); // "blue"
console.log(rect.getArea());  // 50
