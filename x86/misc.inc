{-----------------------------------------------------------------------------]
  Author: Jarl K. Holta
  License: GNU Lesser GPL (http://www.gnu.org/licenses/lgpl.html)
  
  Misc instructions...
[-----------------------------------------------------------------------------}

// ----------------------------------------------------------------------------
// return
function _ret(): TBytes;
begin
  Result := ToBytes([$C3]);
end;

// ----------------------------------------------------------------------------
// no operation
function _nop(): TBytes;
begin
  Result := ToBytes([$90]);
end;
