// Input 3 characters
// if characters 1 and 2 are not equal then print the 3rd input
// else print 4 characters in descending order with the last one being the 3rd input

// SET FLAGS
,>[-]>[-]<<[>+>+<<-]>>[-<<+>>]<  // copy {0} to 1
>>                               // goto 3
,>[-]>[-]<<[>+>+<<-]>>[-<<+>>]<  // copy {3} to 4
[<<<->>>-]<<<                    // {1} = 0 if equal; else {1} != 0
>+<                              // set {2} to 1; goto 1
// if {1} != 0 then:
[
  (COMMAND 1)(CLEAR 2)(CLEAR 1)
  ,.
  >[-]<[-]
]>
// else:
[
  (COMMAND 2)(CLEAR 1)
  ,+++.-.-.-.
  <[-]
]
