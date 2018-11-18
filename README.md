# Locate Function Definition


This is a simple c++ function that locates the function definition of the given function name in the source code.

# Under The hood

  - Uses regex for pattern match
  - Improved efficiency by locating number line only if the function name is matched

### Compilation and execution
```bash
g++ funcDef.cpp -o funcDef.out
./funcDef.out
```
### Road Ahead
- a parser such as clang can be utilized to improve robustness of the function

License
----

MIT


**Free Software, Hell Yeah!**


