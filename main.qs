import Microsoft.Quantum.Convert.*;
import Microsoft.Quantum.Math.*;
operation genbit():Result{
    use q=Qubit();
    H(q);
    let result=M(q);
    Reset(q);
    return result
}
operation gennum(max:Int):Int{
    mutable bits=[];
    let n=BitSizeI(max);
    for i in 1..n{
        set bits+=[genbit()];
    }
    let res=ResultArrayAsInt(bits);
    return res>max?gennum(max)|res;
}
operation Main():Int{
    let limit=100;
    Message($"Absolutely Random Number between 1 to {limit}: ");
    return gennum(limit);
}