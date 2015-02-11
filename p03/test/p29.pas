program p29;
begin
  a:=b+c*d;
  begin a:=b; c:=d end;
  if a<b then a:=b else b:=a;
  while a<b do c:=c+1
end.
