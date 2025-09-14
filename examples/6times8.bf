// Multiply {ptr} by {n}; saves the value at {ptr}
// Requires at least two spaces in between ptr and n

++++++(6 at ptr)>>>++++++++<<<(8 at n)

>[-]<[>+<-]>  // set {ptr plus 1} to {ptr} and {ptr} to 0
[             // pointer is not at ptr plus 1
  >>>                            // goto n plus 1
  [-]>[-]<<[>+>+<<-]>>[-<<+>>]<  // copy {n} to n plus 1
  [<<<<+>>>>-]                   // move {n plus 1} to ptr
  <<<
  -
]<#>>>#