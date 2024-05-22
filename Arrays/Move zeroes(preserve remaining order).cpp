void moveZeroes(int* nums, int numsSize){
    int pos=0;
    int countzero=0;
    for(int i=0 ; i<numsSize ; i++){
        if(nums[i]==0){
            countzero++;
        }
    }
    for(int i=0 ; i<numsSize ; i++){
        if(nums[i]!=0){
            nums[pos]=nums[i];
            pos++;
        }
    }
    int j=0;
    while(countzero>0){
        nums[numsSize-1-j]=0;
        countzero--;
        j++;
    }
    

}