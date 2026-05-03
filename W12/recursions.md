# Activity 12 Recursions

## Questions
### Question 1
This line would be the base case of the function as this is the condition that will stop the recursion from recurring.
```
return if low > high
```

### Question 2
This would never reach the factorial($10$).
It will never stop and end up going into negative numbers as it will skip $n=1$ and will probably crash because it will just continue for as long as it can.

### Question 3
To fix the issue we return if high and low are equal.
This will eventually happen as recursion will lower high by $1$ each time.
```
def sum(low, high)
    return low if high == low
    return high + sum(low, high - 1)
end
```

### Question 4
This will handle any nested array by calling the function.
If it's just an element, it will just print out.
```
def print(array)
    for each element in array
        if element is an array
            print(element)
        else
            print element
    end
end
```
