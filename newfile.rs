fn main()
{
    let mut cnt: i32=0;
    loop
    {
        if cnt==10
        {
            break;
        }
        println!("{:?} loop",cnt);
        cnt+=1;
    }
}