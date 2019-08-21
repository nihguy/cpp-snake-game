# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./src/cpp_snake_game`.

## Compile With Tests

The unit test is useful to ensures the code will not brake while the project is evolving. Moreover, it can help other programmers to understand the code easier. 
 
Although this repo has a [unit test directory](tests/), with the main class behavior explained, it is  not compiled by default. If you are going to run this tests with the project, ensures the _TESTING_ CMake's option is assigned to _ON_, as follows:

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile the project assigning _TESTING_ as _ON_ on _cmake_: `cmake .. -DTESTING=ON && make`
4. Run the tests: `./tests/test`.
5. Run the project `./src/cpp_snake_game`


## Project Specification

### README (All Rubric Points REQUIRED)

| _Done_  	| _Criteria_                                                           	| _Meets Specifications_                                                                                                                                                                                                                                                           	            |
|:-------:	|:---------------------------------------------------------------------	|:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	|         
| &#9744; 	| A `README` with instructions is included with the project            	| The README is included with the project and has instructions for building/running the project. <br><br>If any additional libraries are needed to run the project, these are indicated with cross-platform installation instructions.<br><br>You can submit your writeup as markdown or pdf. 	|
| &#9744; 	| The `README` indicates which project is chosen.                      	| The `README` describes the project you have built.<br><br>The `README` also indicates the file and class structure, along with the expected behavior or output of the program.                                                                                                        	    |
| &#9744; 	| The `README` includes information about each rubric point addressed. 	| The `README` indicates which rubric points are addressed. The `README` also indicates where in the code (i.e. files and line numbers) that the rubric points are addressed.                                                                                                      	            |


### Compiling and Testing (All Rubric Points REQUIRED)

| _Done_  	| _Criteria_                           	| _Meets Specifications_                                                                                                                                                                                                         	|
|:-------:	|:-------------------------------------	|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	|
| &#9744; 	| The submission must compile and run. 	| The project code must compile and run without errors.  We strongly recommend using  `cmake` and  `make`, as provided in the starter repos. If you choose another build system, the code must compile on any reviewer platform. 	|


### Loops, Functions, I/O

| _Done_  	| _Criteria_                                                                                     	| _Meets Specifications_                                                                                                   	| _Address_                                                                |
|:-------:	|:-----------------------------------------------------------------------------------------------	|:-------------------------------------------------------------------------------------------------------------------------	|:------------------------------------------------------------------------ |
| &#9744; 	| The project demonstrates an understanding of C++ functions and control structures.             	| A variety of control structures are used in the project.<br><br>The project code is clearly organized into functions.     |                                                                          |
| &#9744; 	| The project reads data from a file and process the data, or the program writes data to a file. 	| The project reads data from an external file or writes data to a file as part of the necessary operation of the program. 	|                                                                          |
| &#9744; 	| The project accepts user input and processes the input.                                        	| The project accepts input from a user as part of the necessary operation of the program.                                 	|                                                                          |


### Object Oriented Programming

| _Done_  	| _Criteria_                                                                       	| _Meets Specifications_                                                                                                                                                                       	| _Address_                                                                                                               |
|:-------:	|:---------------------------------------------------------------------------------	|:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	|:------------------------------------------------------------------------------------------------------------------------|
| &#9745; 	| The project uses Object Oriented Programming techniques.                         	| The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.                                                                       	| [Color class](src/core/color.hpp), [Vector2 class](src/core/vector2.hpp), [Allocation class](src/core/allocation.hpp)   |
| &#9745; 	| Classes use appropriate access specifiers for class members.                     	| All class data members are explicitly specified as public, protected, or private.                                                                                                            	| [Color class](src/core/color.hpp)                                                                                       |
| &#9745; 	| Class constructors utilize member initialization lists.                          	| All class members that are set to argument values are initialized through member initialization lists.                                                                                       	| [Color class](src/core/color.hpp), [Vector2 class](src/core/vector2.hpp), [Allocation class](src/core/allocation.hpp)   |
| &#9745; 	| Classes abstract implementation details from their interfaces.                   	| All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.      	| [Color class](src/core/color.hpp), [Vector2 class](src/core/vector2.hpp), [Allocation class](src/core/allocation.hpp)   |
| &#9744; 	| Classes encapsulate behavior.                                                    	| Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.                        	|                                                                                                                         |
| &#9744; 	| Classes follow an appropriate inheritance hierarchy.                             	| Inheritance hierarchies are logical. Composition is used instead of inheritance when appropriate. Abstract classes are composed of pure virtual functions. Override functions are specified. 	|                                                                                                                         |
| &#9744; 	| Overloaded functions allow the same function to operate on different parameters. 	| One function is overloaded with different signatures for the same function name.                                                                                                             	|                                                                                                                         |
| &#9744; 	| Derived class functions override virtual base class functions.                   	| One member function in an inherited class overrides a virtual base class member function.                                                                                                    	|                                                                                                                         |
| &#9745; 	| Templates generalize functions in the project.                                   	| One function is declared with a template that allows it to accept a generic parameter.                                                                                                       	| [Vector2 class](src/core/vector2.hpp), [Allocation class](src/core/allocation.hpp)                                      |


### Memory Management

| _Done_  	| _Criteria_                                                                                	| _Meets Specifications_                                                                                                                                                                                                                   	| _Address_                                                                |
|:-------:	|:------------------------------------------------------------------------------------------	|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	|:------------------------------------------------------------------------ |
| &#9744; 	| The project makes use of references in function declarations.                             	| At least two variables are defined as references, or two functions use pass-by-reference in the project code.                                                                                                                            	|                                                                          |
| &#9744; 	| The project uses destructors appropriately.                                               	| At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor.                                                     	|                                                                          |
| &#9744; 	| The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate. 	| The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction. 	|                                                                          |
| &#9744; 	| The project follows the Rule of 5.                                                        	| For all classes, if any one of the copy constructor, copy assignment operator, move constructor, move assignment operator, and destructor are defined, then all of these functions are defined.                                          	|                                                                          |
| &#9744; 	| The project uses move semantics to move data, instead of copying it, where possible.      	| For classes with move constructors, the project returns objects of that class by value, and relies on the move constructor, instead of copying the object.                                                                               	|                                                                          |
| &#9744; 	| The project uses smart pointers instead of raw pointers.                                  	| The project uses at least one smart pointer:  `unique_ptr`,  `shared_ptr`, or  `weak_ptr`. The project does not use raw pointers.                                                                                                        	|                                                                          |


### Concurrency

| _Done_   | _Criteria_                                    	| _Meets Specifications_                                                                                                                               	| _Address_                                                                |
|:-------: |:---------------------------------------------	|:-----------------------------------------------------------------------------------------------------------------------------------------------------	|:------------------------------------------------------------------------ |
| &#9744;  | The project uses multithreading.             	| The project uses multiple threads in the execution.                                                                                                 	|                                                                          |
| &#9744;  | A promise and future is used in the project. 	| A promise and future is used to pass data from a worker thread to a parent thread in the project code.                                              	|                                                                          |
| &#9744;  | A mutex or lock is used in the project.      	| A mutex or lock (e.g.  `std::lock_guard` or `std::unique_lock`) is used to protect data that is shared across multiple threads in the project code. 	|                                                                          |
| &#9744;  | A condition variable is used in the project. 	| A  `std::condition_variable` is used in the project code to synchronize thread execution.                                                           	|                                                                          |
