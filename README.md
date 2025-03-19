# Static Inline Extern Const in C++
A short note to remind myself about these keywords. These are about linker (and to some extend translator).

[A very good blog by Andreas Fertig](https://andreasfertig.com/blog/2023/03/static-inline-or-an-unnamed-namespace-whats-the-difference/)

<!-- markdown-toc start - Don't edit this section. Run M-x markdown-toc-refresh-toc -->
**Table of Contents**

- [Static Inline Extern Const in C++](#static-inline-extern-const-in-c)
- [Static, Inline and Class Variable](#static-inline-and-class-variable)
  - [Namespace as Global Const Variable](#namespace-as-global-const-variable)
- [Const Member Function](#const-member-function)
- [Const, Extern and Global Variable](#const-extern-and-global-variable)
- [How To Run The Code](#how-to-run-the-code)

<!-- markdown-toc end -->


# Static, Inline and Class Variable
A variable declared at the top of a program, has global scope and linker has to *externally linked* it to all files when compiling in order for other file to access it.

> Static refers to a duration, which means they are created when the program is started, and destroyed when it ends. (Taken from www.learncpp.com)

In C, static can be used to *internally linked* a global variable's scope to the file it is declared and defined. It gets more interesting in C++, in object oriented sense the same idea can be apply to an member variable, one can make a member variable `static` in order for all objects created by the same class to access the same member variable (e.g. global class counter), note that a static member shares the same scope region as the class, but not with the object itself!

A static member has to be defined out of line (i.e. `static int i = 1` will not work), and are little bit messy as it can only be access within the same file (i.e. cannot access `.hpp`'s static member at `.cpp`) as mentioned before. This is where `inline` keywords can come in handy to be use in-conjunction with (i.e. `static inline`).

In performance programming `inline` serves a different purpose that are too complicated to explain here, but in this scope the `inline` variable just refers to variable that can have more than one definition as long as the definition stays the same, and have *external linkage* hence able to access across files.

## Namespace as Global Const Variable

> Constexpr functions are implicitly inline, but constexpr variables are not implicitly inline. If you want an inline constexpr variable, you must explicitly mark it as inline. (Taken from www.learncpp.com)

`inline constexpr` in a namespace is a good way to define sets of mathametics' and sciences' constant! However remember `extern constexpr` doesn not support forward declaration.

# Const Member Function
*Const* variable and function are easy to understand. However one can also make a class member function const by adding `const` at the end of a function declaration (i.e. `void Foo() const {};`).

A const member function restrict changes being made to the instance of the object itself (e.g. member variable) including anything it is associated with. If a member function is `const`, and within the object there is a member variable declared as `index`, while the member function can access `index`, the function cannot change `index`'s value (e.g. adding).

# Const, Extern and Global Variable
By default, *non-const global variable* are already *externally linked*. *Const* variable are *internally linked* hence if you need to define global `const` use both keywords together.

To use a `extern const` variable in another file, a forward declaration in said other file must be included.

# How To Run The Code
This sample uses clang as the compile, please change it to fit your needs.

To make a project run `make` at project root.

To clean (i.e. remove executable) run `make clean`.

To generate compile_commands.json for clangd LSP, run `make clean && bear -- make`.
