# list = [2 1 0 8 15 7 3 6] <- stcok prices against equal distributions of time. The problem is to find the best time for buying and selling the stocks, given that there is no short selling involved

### Approach: We can take 2 variables i and j and try to maximize the value of list[i] - list[j] given that i and j are the selling and buying values respectively. In thase case we will have a total of 8C2 possible choices to make, i.e. 8*7/2 = 28 choices and in this case we get the max diff at i = 3 ($0) and j = 5($15).

## Brute force: O(n)^2 approach
- diff_max = 0
- for i from 1 to n-1:
-       for j from i+1 to n:
-           diff_max = max(diff_max,list[j]-list[i])

## Divide and conquer: O(n log n)
- maxSubArray(arr,l,u)
- base cases: if one or 2 elements in subarr return 0 or max(arr[0] - arr[1], 0)
- recursive:
-  m = l+u / 2
-  m1 = maxSubArray(arr,l,m)
-  m2 = maxSubArray(arr,m+1,u)
-  y = maxElement(arr,l,m) *
-  x = minElement(arr,m+1,u) *
- return max(m1,m2,y-x)

## * minElement(arr,m+1,u):
- min = 99999
- for i from l to u:
    - min = minimum(min,arr[i])
    - return min