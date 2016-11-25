# ny

ny is a programming language.

## Progress

- [ ] Grammar
- [ ] Lexer
- [ ] Parser
- [ ] Interpreter


## Build

Run `make`.

## Ideas

### function

```
fn f1(a int, b int) int
  a + b

fn f2()
  put("hello world")
```

function is defined with `fn` followed by an identifier.

The types for argument and return value must be specified. If a function does not return anything, return type is omitted.

Return is implcit. The last line of a scope always returns, if a function signature specifies return type.

```
f1(1, 2):string

# maybe
fn f2 = f1:string
```

The return value of a function can be cast to a certain type.

```
foo = f1(1)
foo(2)
```

A function can be curried. The signature of the curried function is inferred from the original function.

```
fn f1(a int) fn
  fn(b int) int
    a + b  
```

A higher order function can be defined by specifying the return type as `fn`. The nested function expressions respect lexical scoping.

```
fn f1(a int, b int) fn
  fn(c int) fn
    fn() int
      a + b + c
```

Any function with more than two arguments is also a higher order function, because of currying.

We can therefore define the function signature of the following function. This is akin to Haskell's function signature definition:

```
fn f1(a int, b int) int
  a + b

int -> int -> int
```

Anonymous functions can be written by simply removing the identifier.

```
fn f1(a int) fn
  fn(b int) int
    a + b  
```

Here, the return function is an anonymous function. A named function cannot be used as a return value of a higher order function.

### OOP

A method does not have an explicit receiver. A function with the first argument as the receiver is effectively a method. Therefore, there is no need to define prototypes for many built in methods.

```
# array.map(fn) becomes map(arr, fn)
foo int[] = [1,2,3,4]
bar int[] = map(foo, fn(elm int) int
  elm + 1
)

# string.toLowerCase becomes lower(string)
...
```

```
type Animal
  int age
  string name

type Dog
  Animal
```

There is no classical inheritance. However there is a custom type similar to C's struct or Go's type. Here `Dog` implements `Animal`, meaning that `Dog` has all properties of `Animal`.

The above definition is not equal to

```
type Animal
  int age
  string name

type Dog
  int age
  string name
```

because type needs to be nested explicitly to indicate that one type implements another.

Ruby's method missing style delegation is possible

```
fn move(a Animal, x int, y int)
  # do something

dog = Dog{age: 1, name: "Happy"}
move(dog, 1, 2)
```

In the above example, `move` is defined not for `Dog`, but for `Animal`. But since `Dog` implements `Animal`, the code runs.

To help manage symbol tables for method missing style delegation, we can perhaps distinguish between function definition and method definition using keyword `def`.

```
# this is a method
def (a Animal, x int, y int)
  # ...

# this is a function, not a method
fn (a Animal, x int, y int)
  # ...
```

### Type conversion

There are no built in functions for converting types. All casting is done by
following the variable identifier by a colon and a built-in type.

```
int foo = 1
string bar = foo:string
```

You can't cast between user defined types. You must write a function to do the casting.

### Generics

There are generic types.

```
foo int[] = [1,2,3,4]
bar int[] = map(foo, fn(elm int) int
  // do something
)

arr1 Foo[] = {Thing0, Thing1, Thing2}
arr2 Foo[] = map(d1, fn(elm Foo) Foo
  // do something
)
```

You can see that `map` operates on both `int` and `Foo`. The signature of `map` is

```
X[] -> (X -> Y) -> Y[]
```

`X` and `Y` can be anything. In fact, they can even be of the same type.

## License

MIT
