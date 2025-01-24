# 1/22/2025
* Make code run faster
* Hardware
    * Run on a faster computer
    * CPU clock speeds are plateauing
    * Moore's Law is dead? Why?

## Software
```
import numpy as np
x = np.zeros(10)
for i in range(0, 10):
    x[i] += i + 2
```
1 CPU * 10 units of runtime  
No dependencies b/t iterations, each value can be calculated in parallel  
Run each iteration of the loop on a separate CPU: 1 CPU * 10 runtime -> 10 CPU * 1 runtime  

## C
* Manual memory management (no garbage collection), must free memory after use
* Brain --text editor--> source files (.h and .c) --compiler--> object files (.o) --linker--> executable
