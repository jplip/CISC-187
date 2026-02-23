# Activity 3a Sorting
## [Youtube Video](https://youtu.be/IQuTK2qgY3M)

# Questions
## 1. Use Big O Notation to describe the time complexity of an algorithm that takes $4N + 16 steps.$- **1 pt**
Since we are using Big O Notation, we can ignore the constant of 16 steps and the 4 next to N and just use N by itself, which is linear, to get O(N).

## 2. Use Big O Notation to describe the time complexity of an algorithm that takes $2N^2$. **1 pt**
We can get rid of the constant of the 2 next to the N because we are using Big O Notation to get $N^2$, to get $O(N^2)$.

## 3. Use Big O Notation to describe the time complexity of the following function, which returns the sum of all numbers of an array after the numbers have been doubled: - **2 pt**
Double the numbers first, and then set that to the number element, and then add the numbers together for the sum to return. They are both O(N) and run sequentially.
```
def double_then_sum(array) 
	doubled_array = []

	array.each do |number| 
		doubled_array << number *= 2
	end

	sum = 0

	doubled_array.each do |number| 
		sum += number
	end
	return sum 
end

```

## 4. Use Big O Notation to describe the time complexity of the following function, which accepts an array of strings and prints each string in multiple cases: - **2 pts**
Runs for each element of the string to get O(N) and goes through each string to get O(L). We then can get O(N * L).
```
def multiple_cases(array) 
	array.each do |string|
		puts string.upcase 
		puts string.downcase 
		puts string.capitalize
	end 
end
```

## 5. The next function iterates over an array of numbers, and for each number whose index is even, it prints the sum of that number plus every number in the array. What is this function’s efficiency in terms of Big O Notation? - **4 pts**
Iterates over each number in the array to get O(N), but has a condition within for every even which is N/2. So you get N(N/2) which is $N^2$/2 to get O($N^2$).
```
def every_other(array) 
	array.each_with_index do |number, index|
		if index.even?
			array.each do |other_number|
            	puts number + other_number
			end 
		end
	end 
end
```
