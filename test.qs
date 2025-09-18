import Std.Diagnostics.DumpMachine;
operation main():Result{
    use q=Qubit();
    DumpMachine();
    H(q);
    DumpMachine();
    let result=M(q);
    DumpMachine();
    Reset(q);
    return result
}z