### Building Embedded Systems

## Homework week 8

For this assignment I added a funciton to my console code for my final project. 

### Print out the heap pointer
By doing a malloc we can get the current pointer to the heap

### Print out the stack pointer. 
The stack pointer is a tiny bit trickier. To make sure I got it right I looked in the registers during debug (sp)

### An uniintialized global variable
created a global int called globalDummy then take a pointer to it. 

### A static variable inside a funciton 
created a static variable with in this console funciton and take a pointer to it. 

### A variable inside a fucntion. 
created and intialised a variable in the console funciton and then took a pointer to it. 

### Console output. 
<img src="https://github.com/error404notfound/making-embedded-systems-homework/blob/main/homework_week_8/assets/Screen%20Shot%202022-05-20%20at%2012.17.55%20PM.png" alt="Console output" >
### Example of debug. 

<img src="https://github.com/error404notfound/making-embedded-systems-homework/blob/main/homework_week_8/assets/Screen%20Shot%202022-05-19%20at%207.36.52%20PM.png" alt="Debug console output" >

### Code
```
static eCommandResult_T ConsoleCommandWeek8Homework(const char buffer[])
{
	eCommandResult_T result = COMMAND_SUCCESS;

	// stack pointer.
	int p;
	uint32_t stack_pointer = &p;

	// the heap pointer
	int *ptr;
	ptr = malloc(15 * sizeof(*ptr));

	// An unintialise global variable
	uint32_t gVar = &dummyGlobal;

	// A static variable inside a function
	static int staticInFunc = 0;
	uint32_t staticInFunAddress = &staticInFunc;

	// A variable inside a function.
	int v = 0;
	uint32_t varInFunc = &v;

	char textToWrite[ 16 ];
	sprintf( textToWrite, "%x", stack_pointer );
  ```
  

