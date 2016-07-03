namespace cpp oparitmeticas

enum Operation {
  POWER = 1,
  ROOT = 2,
  LOG = 3
}


exception InvalidOperation{
  1:i32 whatOp,
  2:string why
}

service Calculator{
  
  void ping(),

  i32 power(1:list<double> num, 1:double exp) throws (1:InvalidOperation ouch)
  i32 log(1:list<double> num) throws (1:InvalidOperation ouch)
  i32 root(1:list<double> num) throws (1:InvalidOperation ouch)
}