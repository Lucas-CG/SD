namespace cpp mutualexclusion

exception InvalidOperation{
  1:i32 whatOp,
  2:string why
}


service MutualExclusion{
  
  void request(),

  void release()
  
}