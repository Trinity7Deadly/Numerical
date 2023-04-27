


// Joe needs to evaluate the following integral :


//   _
//  / \  1
//  |
//   \       sin(2x)*ln(2 + cos(x))
//    \    -------------------------   dx
//     |       [ 3 + sin^2(x) ]^2
//     |
//     |
//  \_/  0 


// He plans to evaluate the integral by using Simpson's (1/3) rule with
// n = 10.  He also plans to compute the error bound. Joe recalls that
// this error bound requires that he bound the absolute value of the 
// 4-th derivative of the function being integrated over the region of
// integration (0 to 1 in this case).  

// Joe is not looking forward to the algebraic mess involved in computing
// the 4-th derivative, let alone in trying to bound it, so he decides
// to use Automatic Differentiation to compute the 4-th derivative at each
// of the points x = 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0
// and compute his bound with these 11 values.  

// Implement Joe's plan, outputting both his estimate of the integral
// and his estimate of the error bound.

