// Task 1: Array Filtering
function filterNumbers(arr) {
  return arr.filter((item) => typeof item === "number" && !isNaN(item));
}

// Task 2: Array Reversal
function reverseArray(arr) {
  return arr.slice().reverse();
}

// Task 3: Find Maximum in an Array
function findMax(arr) {
  return Math.max(...arr);
}

// Task 4: Remove Duplicates from an Array
function removeDuplicates(arr) {
  return [...new Set(arr)];
}

// Task 5: Flatten a Nested Array
function flattenArray(arr) {
  return arr.flat(Infinity);
}
