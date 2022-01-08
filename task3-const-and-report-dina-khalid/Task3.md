# Const

----
<p> The const keyword specifies that a variable's value is prevented from modifying</p>
Can be used in:

- Variable declaration
- Pointer declaration
- Function arguments and return types
- Class Data members
- Class Member functions
- Objects

### 1. Constant Variables:
To use it you should:

- Initialize the variable
- Explicit value needed to be provided to the constant variable at the time of declaration of the constant variable.

#### ex:
```cpp
const int num = 15;  // num will always be 15
const int i; // error: canot be un-initialized
num = 10;  // error: assignment of read-only variable 'myNum'
```
### 2. Pointers:

The const keyword can also be used with pointers. 
Three cases:

- Pointer variable point to a const value

#### ex:
```cpp
	int x{ 10 };
	char y{ 'M' };

	const int* i = &x;
	const char* j = &y;

	// Value of x and y can be Modified
	
	x = 9;
	y = 'A';
    
	cout << *i << " " << *j;
```

- Const pointer point to the variable value

```cpp
char *mybuf = 0, *yourbuf;
char *const aptr = mybuf;
*aptr = 'a';   // OK
```

- Const pointer pointing to a const variable:

```cpp
  int x{ 9 };
const int* const i = &x;
```
<p>
A pointer to a variable declared as const can be assigned
only to a pointer that is also declared as const
</p>

```cpp
const char *mybuf = "test";
char *yourbuf = "test2";

const char *bptr = mybuf;   // Pointer to constant data


// *bptr = 'a';   // Error
```
### 3. Function arguments and return types:
We can make the return type or arguments of a function as const. Then we cannot change any of them.
```cpp
void f(const int i)
{
    i++;    // error
}

const int g()
{
    return 1;
}
```

### 4. Defining Class Data members as const

Data variables in class which are defined as const 
are not initialized during declaration.
Their initialization is done in the constructor.

```c++
class Test
{
    const int i;
    public:
    Test(int x):i(x)
    {
        cout << "\ni value set: " << i;
    }
};

int main()
{
    Test t(10);
    Test s(20);
}
```
### 5. Defining Class Object as const

When an object is declared as const,
its data members can't be modified.
<p>
For example, if in the class Test defined above, we want to define a constant object, we can do it like:
</p>

```c++
const Test r(30);
```
### 6. Defining Class's Member function as const

A const member functions can't modify data members in an object.

```c++
class Test2
{
    public:
    int i;
    Test2(int x)    // constructor
    { 
        i = x; 
    }

    int C() const  // constant function
    { 
        /* 
            can do anything but will not
            modify any data members
        */
        cout << "This is fun function";
    }

    int increment()
    { 
        i++; 
    }
};

int main()
{
    Test2 objOne(10);        // non const object
    const Test2 objTwo(20);      // const object

    objOne.Fun();     // No error
    objTwo.Fun();     // No error

    cout << objOne.i << objTwo.i;

    objOne.increment();     // No error
    objTwo.increment();     // Compile time error
}
```
-----


# & Operator

----

Can be use in:

- Logical Operators
- Bitwise Operator
- Memory address of the operand
- Reference declarator
- Modifying function's parameters
- Modifying objects in a for loop
- Avoiding copy of object in a for loop
- Avoiding a copy of large structures

### 1. Logical operator
Returns True if all operands are true.
```c++
int i=5;
int j =9;

bool n=(i > 3) && (j > 5); // true
bool m=(i > 3)  && (j < 5); // false
```

### 2. Bitwise operator
Binary AND on individual bits.
Can only be used with char and int data types.

```c++
    bool x = 3 & 2; // x=1
    bool y= 4&3; // y=0
```
### 3. Memory address of the operand
The & is an operator that returns the memory address of its operand.
If var is an integer variable,  &var is its address.

```c++
int var=5;
cout<<&var; // returns address in memory //ex 0x7ffc47a42ba4 
```

### 4. Reference declarator

We can use & to save the reference of some variable
```c++
    int s = 7;
    int& r1 = s;
    s += 10;    
    cout << r1 << endl;  // print 17
```
### 5. Modifying function's parameters:
    We can modify the value of a variable if we pass its refrence to a function

```c++
int increment(int& i){return i++;}

int main()
{
   int var = 7;
    increment(var);
    cout << var << endl;  // print 8
}
```

### 6. Modifying objects in a for loop

We can modify objects in a for loop using & operator.
```c++
    vector<int> vec{2,4,6,8};
   for (int& num: vec){
    num += 1;
    cout << num << " ";} //prints 3 5 7 9 

```

### 7. Avoiding copy of object in a for loop
We can avoid the copying of the string object if we pass its reference
```c++
vector<string> vec{"This","is","an example"} ;
    for (const auto& word: vec){
    cout << word << endl;}
```

### 8. Avoiding a copy of large structures
Usually when we pass an object to a function, a copy of it will be created.
If the object is large, this is a waste of time and memory.
Passing the reference instead of the object itself will solve this problem.
```c++
struct AssumeItLarge{
    string largName;
    long long ID;
    string data;
};

void print(const AssumeItLarge& AL){
    cout<< AL.largName << " " << AL.ID<< " "<< AL.data<< endl;
}
```
---

References:
- [StudyTonight](https://www.studytonight.com/cpp/const-keyword.php)
- [Geeks for Geeks](https://www.geeksforgeeks.org/const-keyword-in-cpp/)
- [Microsoft](https://docs.microsoft.com/en-us/cpp/cpp/const-cpp?view=msvc-170)
- [Cpp Reference](https://en.cppreference.com/w/cpp/language/reference)