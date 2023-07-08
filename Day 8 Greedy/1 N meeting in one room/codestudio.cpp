#include <bits/stdc++.h> 
static bool cmp(pair<int,pair<int,int>>a , pair<int,pair<int,int>>b)
{
    if(a.first==b.first)
    {
        //when two meet have same end time
        return a.second.second < b.second.second;
    }
    return a.first<b.first;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {

    vector<int>answer;//stores meeting number
    if(start.size()==1)
    {
        answer.push_back(1);
        return answer;
    }
    vector<pair<int,pair<int,int>>>meetList;
    // <endTime,<startTime,meetNo> >
    for(int i=0;i<start.size();i++)
    {
        // pair<int,int>p2=make_pair(start[i],i+1);
        // pair<int,pair<int,int>>p1=make_pair(end[i],p2);
        meetList.push_back( {end[i], {start[i],i+1} } );
    }


    sort(meetList.begin(),meetList.end(),cmp);
    answer.push_back(meetList[0].second.second);
    int limit=meetList[0].first;

    for(int i=1;i<start.size();i++)
    {
        int startTime=meetList[i].second.first;
        if(startTime > limit)
        {
            //valid meet to be started
            int meetNo=meetList[i].second.second;
            answer.push_back(meetNo);
            int currentMeetEnd=meetList[i].first;
            limit=currentMeetEnd;
        }
    }
    
    
    
    return answer;
}