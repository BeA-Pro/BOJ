const fs = require('fs')
var arr, n;
var arr2 = Array()

function cal(cnt) {
  if (cnt == n) {
    console.log(arr2.join(' '));
    return
  }

  for (let i = 1; i <= n; i++) {
    if (!arr[i]) {
      arr[i] = true;
      arr2.push(i);
      cal(cnt + 1)
      arr[i] = false;
      arr2.pop();
    }
  }

}

fs.readFile('/dev/stdin', 'utf-8', (err, data) => {
  if (err) {
    console.error('Error reading the file : ', err);
    return;
  }
  n = Number(data)
  arr = Array(n + 1).fill(false);
  cal(0);
})