function outer() {
  let counter = 4;
  return function () {
    counter++;
    return counter;
  };
}

let incremental = outer();
console.log(incremental());
