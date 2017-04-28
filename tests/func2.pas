program lapefunc;
{$I slackasm/assembler.pas}
{$assertions ON}
{$X+}


function LapeFuncPrologue(var assembler:TSlackASM; argCount:Word): Pointer;
var
  i:Int32;
begin
  with assembler do
  begin
    code += _push(ebp);
    code += _mov(esp, ebp);
    code += _mov(ebp+08, ebx);
    for i:=0 to argCount-1 do
    begin
      code += _mov(ref(ebx), ecx);
      code += _push(ecx);
      if i <> argCount-1 then
        code += _add(imm(4), ebx);
    end;
  end;
end;

function LapeFuncEpilogue(var assembler:TSlackASM; argCount:Int32): Pointer;
begin
  assembler.code += assembler._add(imm(4*argCount), esp);
  assembler.code += assembler._pop(ebp);
  assembler.code += assembler._ret;
end;


function LapeMulAddFunc(): Pointer;
const
  NUM_ARGS = 3;
var
  assembler: TSlackASM;
begin
  assembler := TSlackASM.Create(256);
  LapeFuncPrologue(assembler, NUM_ARGS);

  with assembler do
  begin
    code += _mov (ebp-4,   eax) + _mov(ref(eax), eax);
    code += _mov (ebp-8,   ecx) + _mov(ref(ecx), ecx);
    code += _imul(ecx,     eax);
    code += _mov (ebp-12,  ecx) + _mov(ref(ecx), ecx);
    code += _add (ecx,     eax);

    code += _mov(ebp+12, edx);
    code += _mov(eax, ref(edx));
  end;

  LapeFuncEpilogue(assembler, NUM_ARGS);
  Result := assembler.Finalize();
  assembler.Free(False);
end;


var
  mulAdd: external function(x,y,z:Int32): Int32;
begin
  mulAdd := LapeMulAddFunc();
  WriteLn mulAdd(100, 2, 1000);  //100*2 + 1000
  FreeMethod(@mulAdd);
end.