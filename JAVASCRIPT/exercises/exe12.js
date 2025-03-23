function* numberGenerator() {
  yield 1;
  yield 2;
  yield 3;
}

const gen = numberGenerator();
console.log(gen.next().value);
console.log(gen.next().value);
console.log(gen.next().value);
console.log(gen.next().done);

function rangeIterator(start, end) {
    let current = start;
    return {
        next() {
            return current <= end
                ? { value: current++, done: false }
                : { done: true };
        }
    };
}

const range = rangeIterator(1, 5);
console.log(range.next().value);
console.log(range.next().value);
console.log(range.next().value);
console.log(range.next().value);
console.log(range.next().value);
console.log(range.next().done);


function* fibonacciGenerator() {
    let a = 1, b = 1;
    while (true) {
        yield a;
        [a, b] = [b, a + b];
    }
}

const fib = fibonacciGenerator();
console.log(fib.next().value);
console.log(fib.next().value);
console.log(fib.next().value);
console.log(fib.next().value);
console.log(fib.next().value);
console.log(fib.next().value);
