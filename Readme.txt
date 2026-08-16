# Start the project from scratch



```
rm -rf build
cmake -S . -B build
cmake --build build
```



# For debug in VsCode: 

1. cmake -B build -d CMAKE_BUILD_TYPE=Debug

2. Write in project folder .vscode (it is already there)
    - tasks.json 
            
