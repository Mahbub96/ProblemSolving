function xorMaker(n) {
  let prev = 0;
  console.log(0, prev);
  for (let i = 1; i <= n; i++) {
    let current = prev ^ i;
    console.log(i, current);
    prev = current;
  }
}

// xorMaker(15);

const sequenceMaker = (l, r) => {
  let res;
  let count = 0;
  while (l % 4 != 0) {
    l--;
    count++;
  }

  switch (count) {
    case 0:
      res = l;
      break;
    case 1:
      res = 1;
      break;
    case 2:
      res = l + 3;
      break;
    case 3:
      res = 0;
      break;
  }
  //   n,1,n+3,0,

  for (let i = l + count + 1; i <= r; i++) {
    if (i % 4 == 0) {
      res = res ^ i;
    } else if (i % 4 == 1) {
      res = res ^ 1;
    } else if (i % 4 == 2) {
      res = res ^ (i + 1);
    } else if (i % 4 == 3) {
      res = res ^ 0;
    }
  }
  return res;
};

console.log(sequenceMaker(3, 5));
