var expect = function (val) {
  return {
    toBe: (val1) => {
      if (val !== val1) throw new Error("Not Equal");
      else return true;
    },
    notToBe: (val1) => {
      if (val === val1) throw new Error("Equal");
      else return true;
    },
  };
};
