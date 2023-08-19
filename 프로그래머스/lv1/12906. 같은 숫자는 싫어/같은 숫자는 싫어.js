function solution(arr)
{
    var answer = [];
    answer.push(arr[0])
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    var s = new Set()
    for(let i=1;i<arr.length;i++){
        if(answer[answer.length-1]!==arr[i]) answer.push(arr[i])
    }

    return answer;
}