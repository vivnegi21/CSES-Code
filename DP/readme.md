# 8) Array Description.cpp

   We find the number of ways to fill array using the m numbers   
   `d[i][v]` shows numbers of ways to fill the array upto idx n-1 if nums[i]=v.
   
   Now for prefill the dp (**Base condition**):
     
    when nums[0]==0:    
      We can fill idx=0 with any value [1,m] So we fill the dp[0] with 1   
    when nums[0]!=0:    
      Here first is already filled so only dp[0][nums[0]] should be 1 

  Here 1 indicate the number of ways to form array upto idx=0 ( *i.e* only one element).  

  Now for running the dp    
   n --> 1-n-1  
   m --> 1-100

    for(int i=0;i<n;i++){
     
    }
  Here we have to see if nums[i]==0 or not  
  for nums[i]==0 we can fill all the v value with sum of v-1,v,v+1 

  for nums[i]!=0 only dp[i][nums[i]] can be filled with v,v-1,v+1 value if exist in (i-1) idx


  At last what to return

  last vector in dp mean number of ways to make array upto n-1 idx with m values

  Simply Count them and return sum of last array of dp.

  # Next Question

  

    
    
     
     
     

   
