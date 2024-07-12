function solution(skill, skillTree) {
    let ans = 0;
    const order = {};
    
    for(let i = 0; i < skill.length; i++){
        order[skill[i]] = i+1;
    }
    
    for(let i = 0; i < skillTree.length; i++){
        let cnt = 1;
        let flag = true;
        for(let j = 0; j < skillTree[i].length; j++){
            let c = skillTree[i][j];
            if(order[c]){
                if(order[c] == cnt){
                    cnt++;
                }else{
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            ans++;
        }
    }
    
    
    return ans;
}