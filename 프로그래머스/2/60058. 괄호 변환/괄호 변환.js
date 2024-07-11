function solution(p) {
    
    const check = (s) => {
        let stck = [];
        for(let i = 0; i < s.length; i++){
            if(stck.length == 0 && s[i] == ')'){
                return false;
            }else if(s[i] == '('){
                stck.push(s[i]);
            }else if(s[i] == ')' && stck[stck.length-1] == '('){
                stck.pop();
            }
        }
        
        if(stck.length == 0){
            return true;
        }else{
            return false;
        }
    }
    
    // console.log(check("()(())"))
    
    const go = (w) => {
        if(w == ''){
            return '';
        }
        let first = 0;
        let second = 0;
        let u = '';
        let v = '';
        let flag = true;
        for(let i = 0; i < w.length; i++){
            if(w[i] == '('){
                first++;
            }else{
                second++;
            }
            
            if(flag){
                u += w[i];
            }else{
                v += w[i];
            }
            
            if(i != 0 && first == second){
                flag = false;
            }
        }
        let v2 = go(v);
        if(check(u)){
            return u + v2
        }else{
            let newStr = '(';
            newStr += v2;
            newStr += ')';
            // let newU = u.substr(1,u.length-2);
            let newU = "";
            for(let i = 1; i < u.length-1; i++){
                if(u[i] == '('){
                    newU += ')';
                }else{
                    newU += '(';
                }
            }
            newStr+=newU
            return newStr;
        }
    }
    
    var answer = go(p);
    return answer;
}