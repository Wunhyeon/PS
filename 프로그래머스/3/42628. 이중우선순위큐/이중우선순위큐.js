function solution(operations) {
    var answer = [];
    const q = [];
    for(let i = 0; i < operations.length; i++){
        let [op,num] = operations[i].split(" ");
        // console.log("op : " , op);
        // console.log("num : ", num);
        if(op == "I"){
            q.push(Number(num));
        }
        if(op == 'D' && q.length){
            if(num == 1){
                q.sort((a,b) => a-b);
                q.pop();
            }else if(num == -1){
                q.sort((a,b) => b-a);
                q.pop();
            }
        }
    }
    if(q.length){
        q.sort((a,b) => a-b);
        answer = [q[q.length-1],q[0]];
    }else{
        answer = [0,0];
    }
    
    
    return answer;
}