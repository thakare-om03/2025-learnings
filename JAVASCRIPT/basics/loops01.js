/*
  fundamentals: loops in JavaScript

  - while loop: repeats as long as a condition is true. Condition is checked before each iteration,
    so it may run zero times if the condition is false initially.

  - do...while loop: similar to while, but the body runs first and the condition is checked afterwards.
    This guarantees the loop body runs at least once.

  - for loop: convenient when you need an index and know (or can compute) the number of iterations.
    Initialization; condition; increment form the loop control.

  The examples below demonstrate these basic patterns and common idioms (accumulation, arrays, iteration).
*/

/* 
1. while loop: calculate sum of numbers from 1 to 5.
   Pattern: initialize accumulator and counter, test condition, update accumulator and counter.
*/
let sum = 0; // accumulator for the total
let i = 1;   // loop counter starts at 1

while (i <= 5) {
  sum += i; // add current counter to accumulator (sum = sum + i)
  i++;      // advance the counter to avoid infinite loop
}
// sum === 15
// console.log(sum);

/* 
2. while loop: build a countdown array from 5 to 1.
   Pattern: start from a value and decrement until condition fails.
*/
let countdown = [];
let j = 5;

while (j > 0) {
  // push current value and then decrement
  countdown.push(j);
  j--;
}
// countdown === [5, 4, 3, 2, 1]
// console.log(countdown);

/* 
3. do...while loop: collect user input until "stop" is entered.
   Note: `prompt` is available in browsers; commented out for non-browser environments.
   do...while ensures the prompt appears at least once.
*/
let teaCollection = [];
let tea;

// do {
//   tea = prompt('Enter your favourite tea (type "stop" to finish)');
//   if (tea !== null && tea !== "stop") { // check for cancel (null) and stop sentinel
//     teaCollection.push(tea);
//   }
// } while (tea !== "stop" && tea !== null);

/* 
4. do...while loop: add numbers from 1 to 3 into total.
   Shows classic accumulation with a do...while when you want the body to execute first.
*/
let total = 0;
let k = 1;

do {
  total += k; // add current k
  k++;        // move to next number
} while (k <= 3);
// total === 6
// console.log(total);

/* 
5. for loop: multiply each element of an array by 2 and store results.
   for loops are ideal when you iterate by index over arrays.
*/
let multipliedNumbers = [];
let numbers = [2, 4, 6];

for (let l = 0; l < numbers.length; l++) {
  // read current element, transform it, and push to result array
  multipliedNumbers.push(numbers[l] * 2);
}
// multipliedNumbers === [4, 8, 12]
// console.log(multipliedNumbers);

/* 
6. for loop: copy/list cities into a new array.
   Example of iterating an array and working with each element.
*/
let cities = ["Paris", "New York", "Tokyo", "London"];
let cityList = [];

for (let c = 0; c < cities.length; c++) {
  const myCity = cities[c]; // current city from the array
  cityList.push(myCity);
}
console.log(cityList); // ["Paris", "New York", "Tokyo", "London"]
