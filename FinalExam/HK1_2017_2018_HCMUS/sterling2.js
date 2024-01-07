// Calculate sterling number using the formula S(n+1, k) = k * S(n, k) + S(n, k-1)

function calSterlingNumber(n, k) {
  if (n == 0 && k == 0) {
    return 1;
  }
  if (n == 0 || k == 0) {
    return 0;
  }
  return k * calSterlingNumber(n - 1, k) + calSterlingNumber(n - 1, k - 1);
}

console.log(calSterlingNumber(10, 5));
