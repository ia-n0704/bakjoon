#include <bits/stdc++.h>
using namespace std;

//지각생이 없는 디미고 2-4반은 어떠신가요?

vector<pair<int,int>> dimi_student;
pair<int,int> dimi_teacher;
int dimi_student_number;
int dimi_late_student;
int main()
{
    scanf("%d",&dimi_student_number);
    for(int i=1;i<=dimi_student_number+1;i++)
    {
        int dimi_hour,dimi_minute;
        string dimi_string;
        scanf("%d:%d ",&dimi_hour,&dimi_minute);
        cin>>dimi_string;
        if(dimi_string=="student")
            dimi_student.push_back({dimi_hour,dimi_minute});
        else
            dimi_teacher={dimi_hour,dimi_minute};
    }
    pair<int,int> dimi_late;
    scanf("%d:%d",&dimi_late.first,&dimi_late.second);
    for(int i=0;i<dimi_student.size();i++)
    {
        if(dimi_student[i]>=max(dimi_late,dimi_teacher))
            dimi_late_student++;
    }
    printf("%d",dimi_late_student);
}