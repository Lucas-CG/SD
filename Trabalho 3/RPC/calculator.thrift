
namespace cpp oparitmeticas

enum Operation {
  POWER = 1,
  ROOT = 2,
  LOG = 3
}

struct Work{
  1: i32 num,
  2: Operation op,
  3: optional string comment,
}

exception InvalidOperation{
  1:i32 whatOp,
  2:string why
}

service Calculator{
  
  void ping(),

  i32 calculate(1:Work w) throws (1:InvalidOperation ouch)
}