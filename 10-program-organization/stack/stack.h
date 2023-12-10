#define STACK_SIZE 100 
#define DEBUG
#define DEBUG_PUSH(x, y) printf("Pushed %c to stack (top is %d)\n", (x), (y));
#define DEBUG_POP(x, y) printf("Popped %c off the stack (top is %d)\n", x, y);

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char c);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int top = 0;
int contents[STACK_SIZE];

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(char c)
{
	if (is_full())
		stack_overflow();
	else
		contents[top++] = c;
}

int pop(void)
{
	if (is_empty())
	{
		stack_underflow();
		return 0;
	}
	else
		return contents[--top];
}

void stack_overflow(void)
{
	printf("Stack overflow\n");
	exit(1);
}

void stack_underflow(void)
{
	printf("Parentheses/braces are NOT nested correctly\n");
	exit(1);
}
