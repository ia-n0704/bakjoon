// 1. 변수

// 변수 선언
// var -> let, const
let a = 10;   // 동적 타이핑
console.log(typeof a);

a = 'hello';
console.log(typeof a);

console.log(a + 'world');
console.log(10 + '20');

// 자료형 확인
console.log(typeof 10);
console.log(typeof 'abc');
console.log(typeof true);
console.log(typeof []);
console.log(typeof {});
console.log(typeof t);

// 값 비교
console.log(10 == '10');  // 값만 비교, 강제 형변환 (문자열->숫자)
console.log(10 === '10'); // 값과 타입까지 비교

// var vs let
// var : 함수 레벨 스코프, 중복 선언 가능 let : 블록 레벨 스코프, 중복 선언 불가
function test() {
  if (true) {
    var value = 0;
    console.log('1:', value);
  }
  console.log('2:', value);   // 함수 전체에서 접근 가능
}
test();

// const : 상수, 블록 레벨 스코프
let b = 1;
const c = 1;
b++;
// c++;

let arr=[1,2,3,4,5]
console.log(arr)
console.log(arr.length)
let idx=0

function add(a,b)
{
    return a+b;
}

console.log(add(2,3))
console.log(add(add(2,3),add(2,3)))

const sub = function(a,b)
{
    return a-b;
}

console.log(typeof(sub))
console.log(sub(30,3))

let result=function(a,b)
{
    return a*b;
}(2,3);

let T={};
console.log(typeof(T))

let person={
    age:100,
    name:"쌤"
};
person.number=3333;
console.log(person)

let person2=person
console.log(person2)

let person3=Object.assign({key:10},person)
console.log(person3)

let person4={...person}
console.log(typeof person4)
console.log(person4)