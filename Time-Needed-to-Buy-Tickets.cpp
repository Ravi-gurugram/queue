class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time=0;

for(int i=0;i<tickets.size();i++){
    if(i<k)
       time+= min(tickets[i],tickets[k]) ;
    else if(i==k)
        time+=tickets[k] ;
    else{
        time+=min(tickets[k]-1,tickets[i]) ;
    }
}
return time ;

    }
};