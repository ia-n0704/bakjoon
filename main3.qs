import Std.Diagnostics.DumpMachine;
import Microsoft.Quantum.Diagnostics.*;
operation main():(Result,Result)
{
    use (q1,q2)=(Qubit(),Qubit());
    DumpMachine();
    H(q1);
    DumpMachine();
    Z(q1);
    CNOT(q1,q2);
    DumpMachine();
    let (m1,m2)=(M(q1),M(q2));
    Reset(q1);
    Reset(q2);
    return (m1,m2);
}