function solution(n, results) {
    // let mp = Array.from(Array(104),() => Array(104).fill(0));
    let mp = Array.from(Array(104),() => Array(104).fill(Infinity));

    for(let i = 0; i < results.length; i++){
        let win = results[i][0];
        let loose = results[i][1];
        
        mp[win][loose] = 1;
        // mp[loose][win] = 1;
        
    }
    
    for(let k = 1; k <=n; k++){
        for(let i= 1; i <= n; i++){
            for(let j = 1; j<= n; j++){
                if(mp[i][j] > mp[i][k] + mp[k][j]){
                    mp[i][j] = mp[i][k] + mp[k][j]
                }
            }
        }
    }
    
    // console.log(mp);
    const obj = {};
    for(let i = 1; i <= n; i++){
        obj[i] = 0;
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            if(mp[i][j] != Infinity){
                obj[i]++;
                obj[j]++;
            }
        }
    }
    // console.log(obj);
    let cnt = 0;
    for(let key of Object.keys(obj)){
        // console.log("key : ", key);
        if(obj[key] >= n-1){
            cnt++;
        }
    }
    return cnt;
}