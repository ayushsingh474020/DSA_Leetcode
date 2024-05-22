

int findDuplicate(int* nums, int numsSize){
    int max=nums[0];
    int z;
    for(int i=0 ; i<numsSize ; i++){
        if(max<nums[i]){
            max=nums[i];
        }
    }
    int arr[max+1];
    for(int i=0 ; i<max+1 ; i++){
        arr[i]=0;
    }
    for(int i=0 ; i<numsSize ; i++){
        arr[nums[i]]+=1;;
    }
    for(int i=0 ; i<max+1 ; i++){
        if(arr[i]>1){
            z=i;
            break;
        }
    }
    return z;
}