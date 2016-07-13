namespace cpp mutualexclusion

exception InvalidOperation{
  1:i32 whatOp,
  2:string why
}


service MutualExclusion{
  
  void request(1: i32 procID),

  void release(1: i32 procID)
  
}