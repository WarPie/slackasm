//misc.inc
function _ret: TBytes;
function _nop: TBytes;

//flags.inc
function _cmc: TBytes;
function _clc: TBytes;
function _stc: TBytes;
function _cld: TBytes;
function _std: TBytes;
function _cli: TBytes;
function _sti: TBytes;
function _clts: TBytes;
function _lahf: TBytes;
function _sahf: TBytes;

//jumps.inc
function _jmp(dst: TGPRegister): TBytes; overload;
function _jmp(dst: TMemVar): TBytes; overload;
function _jmp(rel8: Int8): TBytes; overload;
function _jmp(rel32: Int32): TBytes; overload;
function _encodeJcc(jcc:Byte; rel: Int32): TBytes;
function _jo(rel: Int32): TBytes; 
function _jno(rel: Int32): TBytes;
function _jb(rel: Int32): TBytes; 
function _jc(rel: Int32): TBytes; 
function _jnae(rel: Int32): TBytes;
function _jae(rel: Int32): TBytes;
function _jnb(rel: Int32): TBytes;
function _jnc(rel: Int32): TBytes;
function _je(rel: Int32): TBytes; 
function _jz(rel: Int32): TBytes; 
function _jne(rel: Int32): TBytes;
function _jnz(rel: Int32): TBytes;
function _jbe(rel: Int32): TBytes;
function _jna(rel: Int32): TBytes;
function _ja(rel: Int32): TBytes; 
function _jnbe(rel: Int32): TBytes;
function _js(rel: Int32): TBytes; 
function _jns(rel: Int32): TBytes;
function _jp(rel: Int32): TBytes; 
function _jpe(rel: Int32): TBytes;
function _jpo(rel: Int32): TBytes;
function _jnp(rel: Int32): TBytes;
function _jl(rel: Int32): TBytes; 
function _jnge(rel: Int32): TBytes;
function _jge(rel: Int32): TBytes;
function _jnl(rel: Int32): TBytes;
function _jle(rel: Int32): TBytes;
function _jng(rel: Int32): TBytes;
function _jg(rel: Int32): TBytes; 
function _jnle(rel: Int32): TBytes;
function _jecxz(rel8: Int8): TBytes;
function _jcxz(rel8: Int8): TBytes;

//general_purpose.inc
function _push(x: TGPRegister): TBytes; overload; 
function _push(x: TMemVar): TBytes; overload; 
function _push(x: TImmediate): TBytes; overload;
function _pop(x: TGPRegister): TBytes; overload;
function _pop(x: TMemVar): TBytes; overload;
function _mov(x,y: TGPRegister): TBytes; overload; 
function _mov(x: TMemVar; y: TGPRegister): TBytes; overload; 
function _mov(x: TGPRegister; y: TMemVar): TBytes; overload; 
function _mov(x: TImmediate; y: TGPRegister): TBytes; overload; 
function _movzx(x,y: TGPRegister): TBytes; overload; 
function _movzx(x: TMemVar; y: TGPRegister): TBytes; overload;
function _movsx(x,y: TGPRegister): TBytes; overload; 
function _movsx(x: TMemVar; y: TGPRegister): TBytes; overload;
function _lea(x: TMemVar; y: TGPRegister): TBytes; overload;
function _inc(x: TGPRegister): TBytes; overload;
function _inc(x: TMemVar): TBytes; overload;
function _dec(x: TGPRegister): TBytes; overload;
function _dec(x: TMemVar): TBytes; overload;
function _cdq(): TBytes;
function _cltq(): TBytes;
function _test(x, y: TGPRegister): TBytes; overload;
function _test(x: TGPRegister; y: TMemVar): TBytes; overload; 
function _test(x: TMemVar; y: TGPRegister): TBytes; overload; 
function _test(x: TImmediate; y: TGPRegister): TBytes; overload; 
function _cmp(x,y: TGPRegister): TBytes; overload;
function _cmp(x: TGPRegister; y: TMemVar): TBytes; overload; 
function _cmp(x: TMemVar; y: TGPRegister): TBytes; overload; 
function _cmp(x: TImmediate; y: TGPRegister): TBytes; overload; 
function _and(x, y: TGPRegister): TBytes; overload;
function _and(x: TGPRegister; y: TMemVar): TBytes; overload; 
function _and(x: TMemVar; y: TGPRegister): TBytes; overload; 
function _and(x: TImmediate; y: TGPRegister): TBytes; overload; 
function _or(x, y: TGPRegister): TBytes; overload;
function _or(x: TGPRegister; y: TMemVar): TBytes; overload;
function _or(x: TMemVar; y: TGPRegister): TBytes; overload;
function _or(x: TImmediate; y: TGPRegister): TBytes; overload; 
function _xor(x, y: TGPRegister): TBytes; overload;
function _xor(x: TGPRegister; y: TMemVar): TBytes; overload;
function _xor(x: TMemVar; y: TGPRegister): TBytes; overload;
function _xor(x: TImmediate; y: TGPRegister): TBytes; overload; 
function _add(x, y: TGPRegister): TBytes; overload;
function _add(x: TGPRegister; y: TMemVar): TBytes; overload; 
function _add(x: TMemVar; y: TGPRegister): TBytes; overload; 
function _add(x: TImmediate; y: TGPRegister): TBytes; overload; 
function _adc(x, y: TGPRegister): TBytes; overload;
function _adc(x: TGPRegister; y: TMemVar): TBytes; overload;
function _adc(x: TMemVar; y: TGPRegister): TBytes; overload;
function _adc(x: TImmediate; y: TGPRegister): TBytes; overload; 
function _sub(x, y: TGPRegister): TBytes; overload;
function _sub(x: TGPRegister; y: TMemVar): TBytes; overload;
function _sub(x: TMemVar; y: TGPRegister): TBytes; overload;
function _sub(x: TImmediate; y: TGPRegister): TBytes; overload; 
function _sbb(x, y: TGPRegister): TBytes; overload;
function _sbb(x: TGPRegister; y: TMemVar): TBytes; overload;
function _sbb(x: TMemVar; y: TGPRegister): TBytes; overload;
function _sbb(x: TImmediate; y: TGPRegister): TBytes; overload; 
function _div(x: TGPRegister): TBytes; overload;
function _div(x: TMemVar): TBytes; overload;
function _idiv(x: TGPRegister): TBytes; overload;
function _idiv(x: TMemVar): TBytes; overload;
function _mul(x: TGPRegister): TBytes; overload;
function _mul(x: TMemVar): TBytes; overload;
function _imul(x: TGPRegister): TBytes; overload;
function _imul(x: TMemVar): TBytes; overload;
function _imul(x,y: TGPRegister): TBytes; overload;
function _imul(x: TMemVar; y: TGPRegister): TBytes; overload;
function _imul(x: TImmediate; y: TGPRegister): TBytes; overload; 
function _sal(x: TGPRegister): TBytes; overload;
function _sal(x: TMemVar): TBytes; overload;
function _sar(x: TGPRegister): TBytes; overload;
function _sar(x: TMemVar): TBytes; overload;
function _shl(x: TGPRegister): TBytes; overload;
function _shl(x: TMemVar): TBytes; overload;
function _shr(x: TGPRegister): TBytes; overload;
function _shr(x: TMemVar): TBytes; overload;
function _rol(x: TGPRegister): TBytes; overload;
function _rol(x: TMemVar): TBytes; overload;
function _ror(x: TGPRegister): TBytes; overload;
function _ror(x: TMemVar): TBytes; overload;
function _setc(opcode:E_SETxx; dst: TGPRegister): TBytes; overload;
function _setc(opcode:E_SETxx; dst: TMemVar): TBytes; overload;

//FPU.inc
function _fld(src: TFPURegister): TBytes; overload; 
function _fld(src: TMemVar): TBytes; overload;
function _fild(src: TMemVar): TBytes; overload;
function _fst(dst: TFPURegister): TBytes; overload; 
function _fst(dst: TMemVar): TBytes; overload;
function _fist(dst: TMemVar): TBytes;
function _fstp(dst: TFPURegister): TBytes; overload; 
function _fstp(dst: TMemVar): TBytes; overload;
function _fistp(dst: TMemVar): TBytes;
function _fisttp(dst: TMemVar): TBytes;
function _ffree(reg: TFPURegister): TBytes; 
function _faddp(dst: TFPURegister=st1): TBytes; overload; 
function _fadd(src, dst: TFPURegister): TBytes; overload; 
function _fadd(mem: TMemVar): TBytes; overload;
function _fiadd(mem: TMemVar): TBytes; 
function _fsubp(dst: TFPURegister=st1): TBytes; overload; 
function _fsub(src, dst: TFPURegister): TBytes; overload; 
function _fsub(mem: TMemVar): TBytes; overload;
function _fisub(mem: TMemVar): TBytes; 
function _fsubrp(dst: TFPURegister=st1): TBytes; overload; 
function _fsubr(src, dst: TFPURegister): TBytes; overload; 
function _fsubr(mem: TMemVar): TBytes; overload;
function _fisubr(mem: TMemVar): TBytes; 
function _fmulp(dst: TFPURegister=st1): TBytes; overload; 
function _fmul(src, dst: TFPURegister): TBytes; overload; 
function _fmul(mem: TMemVar): TBytes; overload;
function _fimul(mem: TMemVar): TBytes; 
function _fdivp(dst: TFPURegister=st1): TBytes; overload; 
function _fdiv(src, dst: TFPURegister): TBytes; overload; 
function _fdiv(mem: TMemVar): TBytes; overload;
function _fidiv(mem: TMemVar): TBytes; 
function _fdivrp(dst: TFPURegister=st1): TBytes; overload; 
function _fdivr(src, dst: TFPURegister): TBytes; overload; 
function _fdivr(mem: TMemVar): TBytes; overload;
function _fidivr(mem: TMemVar): TBytes; 
function _ftst(): TBytes; 
function _fxam(): TBytes; 
function _fabs(): TBytes;
function _frndint(): TBytes;
function _fsqrt(): TBytes;
function _fcos(): TBytes;
function _fsin(): TBytes;
function _fsincos(): TBytes;
function _fptan(): TBytes;
function _fpatan(): TBytes;
function _fprem(): TBytes;
function _fprem1(): TBytes;
function _fscale(): TBytes;
function _fxtract(): TBytes;
function _fyl2x(): TBytes;
function _fyl2xp1(): TBytes;