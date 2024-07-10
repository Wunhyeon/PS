function solution(n, money) {
    // dp 배열을 n+1 크기로 초기화하고 dp[0]은 1로 설정
    let dp = Array(n + 1).fill(0);
    dp[0] = 1;

    for (let i = 0; i < money.length; i++) {
        for (let j = money[i]; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - money[i]]) % 1000000007;
        }
    }
    
    return dp[n];
}
