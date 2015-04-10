{------------------------------------------------------------------------------------}
{program p032_000 exercises production #032                                          }
{statement -> IF expression THEN statement ELSE statement                            }
{------------------------------------------------------------------------------------}
{Author: Thomas R. Turner                                                            }
{E-Mail: trturner@uco.edu                                                            }
{Date: January, 2012                                                                 }
{------------------------------------------------------------------------------------}
{Copyright January, 2012 by Thomas R. Turner                                         }
{Do not reproduce without permission from Thomas R. Turner.                          }
{------------------------------------------------------------------------------------}
program p032_000;
  var cash:real;
begin{p032_000}
  writestring('How much cash do you have? ');
  readreal(cash);
  readln;
  if cash<100.0 then
    begin
      writestring('You wicked and slothful person.');
      writeln;
      writestring('I''d never go out with you.');
      writeln
    end
  else
    begin
      writestring('Come on, honey, let''s have a good time tonight!');
      writeln
    end;
  writestring('See you later!');
  writeln
end{p032_000}.
