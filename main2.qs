import Std.Math.ArcCos;
import QasmStd.Convert.BoolAsBigInt;
import Std.Diagnostics.DumpMachine;
import Microsoft.Quantum.Diagnostics.*;
import Microsoft.Quantum.Math.*;
import Microsoft.Quantum.Convert.*;
import Microsoft.Quantum.Arrays.*;

operation main():Int{
    use q=Qubit[5];
    ApplyToEach(H,q);
    DumpMachine();
    let result=ForEach(M,q);
    DumpMachine();
    ResetAll(q);
    Message($"{result}");
    return BoolArrayAsInt(ResultArrayAsBoolArray(result));
}