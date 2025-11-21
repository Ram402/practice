// #include <iostream>
// #include <cassert>
// #define my_assert(expr, msg) \
//     do { \
//         if (!(expr)) { \
//             std::cerr << "❌ Assertion failed in function " << __func__ << ":\n" \
//                       << "  Message   : " << msg << "\n" \
//                       << "  Expression: " << #expr << "\n" \
//                       << "  File      : " << __FILE__ << "\n" \
//                       << "  Line      : " << __LINE__ << "\n"; \
//             std::abort(); \
//         } \
//     } while(0)


// using namespace std;


// int add(int a,int b)
// {
//     return a+b;
// }

// int main()
// {
//     int a,b,expected_op;
//     cout << "Enter num1 and num2: ";
//     cin >> a >> b;
//     cout << "Enter the expected output: ";
//     cin >> expected_op;
//     my_assert(add(a,b)==expected_op, "Addition Testcase failed");
//     cout << "Test case passed" << endl;
// }
