const Sum_XOR = (n) => {
  let bin = n.toString(2);
  let count = 0;

  if (n == 0) return 1;
  else if (Number.isInteger(Math.log(n))) return n;

  for (let i = 0; i < bin.length; i++) {
    if (bin[i] == "0") count++;
  }
  console.log(bin);
  return Math.pow(2, count);
};

console.log(Sum_XOR(1000000000000000));
