bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int count=0;
    if(flowerbedSize==1){
        if(flowerbed[0]==0){
            count=1;
        }
    }
    else if(flowerbedSize==2){
        if(flowerbed[0]==0 && flowerbed[1]==0){
            count=1;
        }
    }
    else{
        if(flowerbed[0]==0 && flowerbed[1]==0){
            flowerbed[0]=1;
            count++;
        }
        if (flowerbed[flowerbedSize-1]==0 && flowerbed[flowerbedSize-2]==0){
            flowerbed[flowerbedSize-1]=1;
            count++;
        }
        for(int i=1 ; i<flowerbedSize-1 ; i++){
            if(flowerbed[i-1]==0 && flowerbed[i+1]==0 && flowerbed[i]==0){
                flowerbed[i]=1;
                count++;
            }
        }
        
    }
    int ans;
    if(count<n){
        ans=0;
    }
    else{
        return 1;
    }
    return ans;

}