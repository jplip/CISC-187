# Activity 12 Recursions

## Questions
### Question 1
The space complexity is $O(n^2)$ because the collection array will grow proportionally to the number of pairs generated from elements that are different in the array.

### Question 2
The space complexity is $O(n)$ because the new array will be the reverse of every element from the original array.

### Question 3
This funcition reverses the array with $O(1)$ extra space as there is no new array created and the amount of extra memory will stay constant regardless of the size.
```
function reverse1(array){
    let left = 0;
    let right = array.length - 1;

    while(left < right){
        let temp = array[left];
        array[left] = array[right];
        array[right] = temp;

        left++;
        right--;
    }
    return array;
}
```

### Question 4
The time complexity for all versiuons are $O(n)$ and the space complexity for version #1 and #2 are also $O(n)$ while version #3 is $O(1)$.

| Version    | Time complexity | Space complexity |
| ---------- | --------------- | ---------------- |
| Version #1 | O(n)               | O(n)                |
| Version #2 | O(n)               | O(1)                |
| Version #3 | O(n)               | O(n)                |
