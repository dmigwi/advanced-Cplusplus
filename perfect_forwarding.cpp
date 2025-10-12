// Perfect Forwarding is the act of passing a function’s parameters to another function
// while preserving its reference category. It is commonly used by wrapper methods 
// that want to pass their parameters through to another function, often a constructor.

/* Example 1 */

// template<class T>
// struct some_struct{
//   T _v;

//   template<class U>
//   some_struct(U&& v)
//     : _v(static_cast<U&&>(v)) {} // perfect forwarding here
//                                  // std::forward is just syntactic sugar for this
// };

// int main(){
//   some_struct<int> s1(5);
//   // in ctor: '5' is rvalue (int&&), so 'U' is deduced as 'int', giving 'int&&'
//   // ctor after deduction: 'some_struct(int&& v)' ('U' == 'int')
//   // with rvalue reference 'v' bound to rvalue '5'
//   // now we 'static_cast' 'v' to 'U&&', giving 'static_cast<int&&>(v)'
//   // this just turns 'v' back into an rvalue
//   // (named rvalue references, 'v' in this case, are lvalues)
//   // huzzah, we forwarded an rvalue to the constructor of '_v'!

//   // attention, real magic happens here
//   int i = 5;
//   some_struct<int> s2(i);
//   // in ctor: 'i' is an lvalue ('int&'), so 'U' is deduced as 'int&', giving 'int& &&'
//   // applying the reference collapsing rules yields 'int&' (& + && -> &)
//   // ctor after deduction and collapsing: 'some_struct(int& v)' ('U' == 'int&')
//   // with lvalue reference 'v' bound to lvalue 'i'
//   // now we 'static_cast' 'v' to 'U&&', giving 'static_cast<int& &&>(v)'
//   // after collapsing rules: 'static_cast<int&>(v)'
//   // this is a no-op, 'v' is already 'int&'
//   // huzzah, we forwarded an lvalue to the constructor of '_v'!
// }

/* Example 2*/

// #include <iostream>
// #include <string>
// #include <utility>

// void overloaded_function(std::string& param) {
//   std::cout << "std::string& version" << std::endl;
// }
// void overloaded_function(std::string&& param) {
//   std::cout << "std::string&& version" << std::endl;
// }

// template<typename T>
// void pass_through(T&& param) {
//   overloaded_function(std::forward<T>(param));
// }

// int main() {
//   std::string pes;
//   pass_through(pes);                // Prints: std::string& version
//   pass_through(std::move(pes));     // Prints: std::string&& version
// }

/* Example 3*/

#include <iostream>
#include <string>
#include <utility>

template <typename F, typename... Args>
decltype(auto) function_logging(F&& f, Args&&... args)
{
    // Log argument types using folding expressions.
    (std::cout << ... << (std::string(typeid(Args).name()) + ", ")) << "\n";

    // The perfect forward call.
    return std::forward<F>(f)(std::forward<Args>(args)...);
}

// Example of usage
auto add = [](const auto a, const auto b) -> decltype(a+b) {return a + b; };

auto main() -> int {
    auto result = function_logging(add, 1, 3.0);
    std::cout << "Result: " << result << '\n';
    return 0;
}

