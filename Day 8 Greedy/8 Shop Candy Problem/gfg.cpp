        sort(candies,candies+N);
        int available=N-1;
        int buy=0;
        int cost=0,freeCandies=K;
        for( ; buy<=available;buy++)
        {
            cost+=candies[buy];
            while(freeCandies>0 && available>=buy)
            {
                available--;
                freeCandies--;
            }
            freeCandies=K;
        }
        return cost;