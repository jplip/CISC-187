# Activity 4a Sorting II


## Questions
1. 
Since

2a.
We

2b.

2c.

3a. The time complexity would be O(N) because the for loop goes through the string length.
```
function containsX(string) {
	foundX = false;
	for(let i = 0; i < string.length; i++) { 
		if (string[i] === "X") {
			foundX = true; 
		}
	}
	return foundX; 
}
```

3b. This code is faster because it will return true once found 'X' inside of the string length compared to the code in 3a which runs the whole string length no matter if it found 'X' already or not.
```
function containsX(string){
    for(let i=0; i<string.length; i++){
        if(string[i] === "X")
            return true;
    }
    return false;
}
```
