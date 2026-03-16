# Activity 6 Stacks and Queues

## Questions
### Question 1
<p align="center">
<img src="image1.jpg" alt="Drawing for question 1" width="600" height="600">
</p>

### Question 2
<p align="center">
<img src="image2.jpg" alt="Drawing for question 2a" width="600" height="600">
</p>

### Question 3
Revised ENQUEUE(Q, x) — Detect Overflow
```
if Q.head == Q.tail + 1 OR (Q.head == 1 AND Q.tail == Q.length)
    report "Queue Overflow"
else
    Q[Q.tail] = x
    if Q.tail == Q.length
        Q.tail = 1
    else
        Q.tail = Q.tail + 1
```

Revised DEQUEUE(Q) — Detect Underflow
```
if Q.head == Q.tail
    report "Queue Underflow"
else
    x = Q[Q.head]
    if Q.head == Q.length
        Q.head = 1
    else
        Q.head = Q.head + 1
    return x
```

### Question 4
INSERT-FRONT(D, x)
```
if (D.head == 1 AND D.tail == D.length) OR (D.head == D.tail + 1)
    report "Overflow"
if D.head == 1
    D.head = D.length
else
    D.head = D.head - 1
D[D.head] = x
```

INSERT-REAR(D, x)
```
if (D.head == 1 AND D.tail == D.length) OR (D.head == D.tail + 1)
    report "Overflow"
D[D.tail] = x
if D.tail == D.length
    D.tail = 1
else
    D.tail = D.tail + 1
```

DELETE-FRONT(D)
```
if D.head == D.tail
    report "Underflow"
x = D[D.head]
if D.head == D.length
    D.head = 1
else
    D.head = D.head + 1
return x
```

DELETE-REAR(D)
```
if D.head == D.tail
    report "Underflow"
if D.tail == 1
    D.tail = D.length
else
    D.tail = D.tail - 1
x = D[D.tail]
return x
```
