/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function (functions) {
  return function (x) {
    if (!functions.length) return x;
    let value = 0;
    for (let i = functions.length - 1; i >= 0; i--) {
      if (!value) value = functions[i](x);
      else value = functions[i](value);
    }
    return value;
  };
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
