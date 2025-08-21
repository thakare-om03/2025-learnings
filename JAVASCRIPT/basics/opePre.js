/**
 * Fundamentals (brief):
 * - Parentheses () force grouping and change the normal evaluation order.
 * - Operator precedence: * (multiplication) runs before + and - (addition/subtraction).
 * - + and - have the same precedence and are evaluated left-to-right.
 * - Use console.log(...) to output values for inspection.
 *
 * Expression: ((2 * (3 + 2)) - 1)
 * Steps:
 *   1. (3 + 2) -> 5
 *   2. 2 * 5   -> 10
 *   3. 10 - 1  -> 9
 */

let score = 2 * (3 + 2) - 1; // calculate a numeric result using grouping and operators
console.log(score); // expected output: 9
