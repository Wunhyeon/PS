function solution(expression) {
  var answer = 0;
  let tmp = "";
  let numArr = [];
  let opArrStd = ["+", "-", "*"];
  let opArr = [];
  let opPermu = [];

  for (let i = 0; i < expression.length; i++) {
    if (expression[i] == "+" || expression[i] == "-" || expression[i] == "*") {
      numArr.push(Number(tmp));
      tmp = "";
      opArr.push(expression[i]);
    } else {
      tmp += expression[i];
    }
  }
  numArr.push(Number(tmp));

  //   console.log(numArr);
  //   console.log(opArr);

  const makePermu = (n, r, depth) => {
    if (r == depth) {
      let tmp = [];
      for (let i = 0; i < opArrStd.length; i++) {
        tmp.push(opArrStd[i]);
      }
      opPermu.push(tmp);
    } else {
      for (let i = depth; i < n; i++) {
        [opArrStd[i], opArrStd[depth]] = [opArrStd[depth], opArrStd[i]];
        makePermu(n, r, depth + 1);
        [opArrStd[i], opArrStd[depth]] = [opArrStd[depth], opArrStd[i]];
      }
    }
  };
  makePermu(opArrStd.length, 3, 0);
  // 완전탐색. + > - > *, + > * > -, - > + > *, - > * > +, * > + > -, * > - > +
  const cal = (num1, num2, op) => {
    // console.log("num1 : ", num1, ", num2 : ", num2, ", op : ", op);
    if (op == "+") {
      return num1 + num2;
    } else if (op == "-") {
      return num1 - num2;
    } else if (op == "*") {
      return num1 * num2;
    }
  };

  const cal2 = (numArr2, opArr2, op) => {
    for (let i = 0; i < opArr2.length; i++) {
      let c = opArr2[i];
      if (c == op) {
        let newNum = cal(numArr2[i], numArr2[i + 1], c);
        numArr2[i] = newNum;
        opArr2.splice(i, 1);
        numArr2.splice(i + 1, 1);
        i--;    // 중요
      }
    }
  };

  let mx = 0;

  for (let i = 0; i < opPermu.length; i++) {
    let tmpNumArr = [];
    for (let i = 0; i < numArr.length; i++) {
      tmpNumArr.push(numArr[i]);
    }
    let tmpOpArr = opArr.map((el) => el);

    for (let j = 0; j < opPermu[i].length; j++) {
      let op = opPermu[i][j];
      cal2(tmpNumArr, tmpOpArr, op);
    }

    mx = Math.max(mx, Math.abs(tmpNumArr[0]));
    // console.log(tmpNumArr);
    // console.log("--------------");
  }

  //   console.log(cal(-100, -220, "*"));

  return mx;
}

// console.log(solution("100-200*300-500+20"));
// console.log(solution("50*6-3*2"));
// solution("100-200");
