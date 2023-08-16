let input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
let a = Number(0)
for (let i = 0; i < input[0]; i++) {
  a += Number(input[1][i])
}
console.log(a)