namespace cpp oparitmeticas

exception InvalidOperation{
  1:i32 whatOp,
  2:string why
}

struct DoubleList{
	1: list<double> values
}

service Calculator{
  
  void ping(),

  list<double> power(1: list<double> received, 2:double exp) throws (1:InvalidOperation ouch)
  list<double> log(1: list<double> received) throws (1:InvalidOperation ouch)
  list<double> root(1: list<double> received) throws (1:InvalidOperation ouch)
}