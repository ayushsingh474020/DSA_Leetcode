int removeDuplicates(int* nums, int numsSize){
    int max;
    if(nums[0]<0){
        if(-nums[0]>nums[numsSize-1]){
            max=-nums[0];
        }
        else{
            max=nums[numsSize-1];
        }
    }
    else{
        max=nums[numsSize-1];
    }
    int anspos[max+1];
    int ansneg[max+1];
    for(int i=0 ; i<max+1 ; i++){
        anspos[i]=0;
        ansneg[i]=0;
    }
    for(int i=0 ; i<numsSize ; i++){
        if(nums[i]>=0){
            anspos[nums[i]]++;
        }
        else{
            ansneg[-nums[i]]++;
        }
    }
    int pos=0;
    int count=0;
    for(int i=0 ; i<max+1 ; i++){
        if(ansneg[i]>0){
            count++;
        }
    }
    
    for(int i=0 ; i<max+1 ; i++){
        if(anspos[i]>0){
            count++;
        }
    }
    for(int i=max ; i>=0 ; i--){
        if(ansneg[i]>0){
            nums[pos]=-i;
            pos++;
        }
    }
    for(int i=0 ; i<max+1 ; i++){
        if(anspos[i]>0){
            nums[pos]=i;
            pos++;
        }
    }
    return count;

}