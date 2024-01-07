// Calculate Combination of nCk using the formula nCk = n! / (k! * (n-k)!)

function calCombination(k, n) {
  let result = 1;
  for (let i = 1; i <= k; i++) {
    result *= (n - i + 1) / i;
  }
  return result;
}

// Calculate Bell number using the formula Bn+1 = sum(k=0 to n) C(n,k) * Bk

function calBellNumber(n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  let bell = 0;
  for (let i = 0; i <= n; i++) {
    bell += calCombination(i, n) * calBellNumber(i);
  }
  return bell;
}

function getPermutations(n) {
  // Chuyển số n thành một mảng các chữ số
  const digits = Array.from(String(n));

  // Sử dụng hàm đệ quy để sinh các hoán vị
  function generatePermutations(arr, current = []) {
    if (arr.length === 0) {
      // Khi mảng rỗng, thêm hoán vị hiện tại vào mảng kết quả
      result.push(current.join(""));
      return;
    }

    for (let i = 0; i < arr.length; i++) {
      // Tạo một bản sao của mảng hiện tại để tránh ảnh hưởng đến các lượt sau
      const newArr = arr.slice();
      // Loại bỏ phần tử tại vị trí i
      const removed = newArr.splice(i, 1);
      // Gọi đệ quy với mảng đã loại bỏ và phần tử hiện tại được thêm vào mảng kết quả
      generatePermutations(newArr, current.concat(removed));
    }
  }

  // Mảng kết quả
  const result = [];

  // Gọi hàm đệ quy để sinh hoán vị
  generatePermutations(digits);

  return result;
}

// Sử dụng hàm với một số nguyên n
const n = 1234567;
const permutations = getPermutations(n);

const dangers = {
  1: [1, 2, 7],
  2: [2, 6],
  3: [3, 4],
  4: [4, 5],
  5: [],
  6: [],
  7: [],
};

function countSafePermutations(permutations) {
  let count = 0;
  for (let i = 0; i < permutations.length; i++) {
    const permutation = permutations[i];
    let isSafe = true;
    for (let j = 0; j < permutation.length; j++) {
      const digit = permutation[j];
      // Convert digit to number
      const danger = dangers[Number(digit)];
      // console.log(danger);
      // Check if danger contains j + 1
      for (let k = 0; k < danger.length; k++) {
        if (danger[k] === j + 1) {
          isSafe = false;
          break;
        }
      }
    }
    if (isSafe) {
      count++;
    }
  }
  return count;
}

const safePermutations = countSafePermutations(permutations);
console.log(safePermutations / 6);
