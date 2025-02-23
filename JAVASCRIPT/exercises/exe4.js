function sumOfN(n) {
  if (n === 1) {
    return 1;
  }
  let sum = 0;
  for (let i = 1; i <= n; i++) {
    sum += i;
  }
  return `Sum of ${n} natural numbers: ${sum}`;
}

function printMultiplicationTable(n) {
  let table = [];
  for (let i = 1; i <= 10; i++) {
    table.push(`${n} * ${i} = ${n * i}`);
  }
  return table;
}

function countVowels(str) {
  const vowels = "aeiouAEIOU";
  let count = 0;
  for (let char of str) {
    if (vowels.includes(char)) {
      count++;
    }
  }
  return count;
}
