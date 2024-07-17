function solution(user_id, banned_id) {
    
    const combi = [];
    
    // 모든 조합 생성 함수
    const makeCombi = (start, limit, v) => {
        if (v.length == limit) {
            combi.push([...v]);
        } else {
            for (let i = start + 1; i < user_id.length; i++) {
                v.push(user_id[i]);
                makeCombi(i, limit, v);
                v.pop();
            }
        }
    }
    
    let permu = [];
    
    // 모든 순열 생성 함수
    const makePermu = (n, r, depth, arr) => {
        if (depth == r) {
            permu.push([...arr]);
        }
        for (let i = depth; i < n; i++) {
            [arr[i], arr[depth]] = [arr[depth], arr[i]];
            makePermu(n, r, depth + 1, arr);
            [arr[i], arr[depth]] = [arr[depth], arr[i]];
        }
    }
    
    // banned_id와 user_id의 매칭 함수
    const compare = (banned, user) => {
        if (banned.length != user.length) {
            return false;
        }
        for (let i = 0; i < banned.length; i++) {
            if (banned[i] == '*') {
                continue;
            }
            if (banned[i] != user[i]) {
                return false;
            }
        }
        return true;
    }
    
    makeCombi(-1, banned_id.length, []);
    let cnt = 0;
    
    for (let i = 0; i < combi.length; i++) {
        let comb = combi[i];
        
        permu = [];
        makePermu(comb.length, comb.length, 0, comb);
        
        for (let j = 0; j < permu.length; j++) {
            let tmp = 0;
            const perm = permu[j];
            const pass = new Array(banned_id.length).fill(false);
            let flag = false;
            
            for (let k = 0; k < perm.length; k++) {
                let word = perm[k];
                for (let l = 0; l < banned_id.length; l++) {
                    if (pass[l]) {
                        continue;
                    }
                    let result = compare(banned_id[l], word);
                    if (result) {
                        pass[l] = true;
                        tmp++;
                        break;
                    }
                }
            }
            
            if (tmp == banned_id.length) {
                flag = true;
                cnt++;
            }
            if (flag) {
                break;
            }
        }
    }
    
    return cnt;
}
