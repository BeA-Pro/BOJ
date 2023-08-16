const fs = require('fs')
const Max = 10000001;
const prime = new Array(Max).fill(false);

for (let i = 2; i < Max; i++) {
  if (!prime[i]) {
    let a = i * 2;
    while (a < Max) {
      prime[a] = true;
      a += i;
    }
  }
}

// for (let i = 2; i < 100; i++) {
//   if (!prime[i]) console.log(i)
// }

fs.readFile('/dev/stdin', 'utf-8', (err, data) => {
  if (err) {
    console.error('Error reading the file : ', err);
    return;
  }

  let number = Number(data);
  let n = 2;
  while (number !== 1) {
    if (prime[n]) {
      n++;
      continue;
    }

    if (number % n === 0) {
      console.log(n)
      number /= n;
    } else n++;
  }

})