{----------------------------------------------------------------------------}
{Author:     Dr. Sweet T.                                                    }
{Student ID: *00000000                                                       }
{Course:     CMSC 1513 Beginning Programming (Pascal)                        }
{CRN:        10849                                                           }
{Project:    p03                                                             }
{Due:        September 27, 2002                                              }
{Account:    tt000                                                           }
{----------------------------------------------------------------------------}
program p03;
  var
    P:real;              {Principal                                          }
    APR:real;            {Annual Percentage Rate                             }
    S:real;              {Future Value (Sum)                                 }
    i:real;              {Periodic Interest Rate                             }
begin{p03}
  write ('Enter your current balance. ');
  readln(P);
  write ('Enter the annual percentage rate (APR) on your account. ');
  readln(APR);
  write ('After one year your balance will be $');
  i:=APR/100;
  S:=P*(1+i);
  write (S:1:2);
  writeln('.')
  5+5
  1-2
  /
  begin read(x);
  x:=x+2; { This is a one line comment}
  {This is a comment that begins in column 31}


y:=x-3; write(x,y); {This is
                     a multi-line
                     comment
                    } end


end{p03}.