function solution(users, emoticons) {
    // 이모티콘 플러스 서비스 가입을 시키는 가장 낮은 할인율
    
    const saleRate = [0.9,0.8,0.7,0.6];
    const saleArr = [];
    const go = (tmpArr) => {
        if(tmpArr.length == emoticons.length){
            saleArr.push([...tmpArr]);
            return;
        }
        
        for(let i = 0; i < saleRate.length; i++){
            tmpArr.push(saleRate[i]);
            go(tmpArr);
            tmpArr.pop();
        }
    }
    
    go([]);
    
    // console.log(saleArr);   
    let ans = [0,0];
    
    for(let i = 0; i < saleArr.length; i++){
        const tmpArr = saleArr[i];
        let totalPrice = 0;
        let subscriber = 0;
        for(let j = 0; j < users.length; j++){
            const able = 1 - (users[j][0]/100);
            const limit = users[j][1];
            
            let buy = 0;
            for(let k = 0; k < tmpArr.length; k++){
                if(tmpArr[k] <= able){
                    buy+= (emoticons[k] * tmpArr[k]);
                }
                if(buy >= limit){
                    buy = 0;
                    subscriber++;
                    break;
                }
            }
            totalPrice+=buy;
        }
        if(subscriber > ans[0]){
            ans = [subscriber,totalPrice];
        }else if(subscriber == ans[0] && totalPrice > ans[1]){
            ans = [subscriber,totalPrice];
        }
    }
    return ans;
}