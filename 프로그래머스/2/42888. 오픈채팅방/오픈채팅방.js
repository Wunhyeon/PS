function solution(record) {
    const mp = new Map();
    for(let i = 0; i < record.length; i++){
        let arr = record[i].split(" ");
        // console.log(arr);
        if(arr[0] == 'Enter' || arr[0] == 'Change'){
            mp[arr[1]] = arr[2];
        }
    }
    // console.log(mp);
    var answer = [];
    for(let i = 0; i < record.length; i++){
        let arr = record[i].split(" ");
        if(arr[0] == "Change"){
            continue;
        }
        let newStr = "";
        newStr += mp[arr[1]];
        if(arr[0] == "Enter"){
            newStr+="님이 들어왔습니다.";
        }else{
            newStr+="님이 나갔습니다.";
        }
        answer.push(newStr);
    }
    // console.log(answer);
    return answer;
}