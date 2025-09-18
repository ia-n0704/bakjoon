let grade = 3, ban = 3, no = 33, name = "김채원";
console.log(`${grade}${ban}${no} ${name} 입니다.`);

const school = "KDMHS";
console.log(`${school}에 다닙니다.`);

const todos = [
  { id: 1, task: "국어", done: true },
  { id: 2, task: "수학", done: true },
  { id: 3, task: "영어", done: false }
];

const arr_done = todos.filter(todo => todo.done);
console.log(arr_done);

todos.map(todo => todo.done = false);
console.log(todos);

const hello = () => console.log("Hello");
hello();

const hello2 = name => console.log(`Hello, ${name}`);
hello2("디미");

const hello3 = (firstname, lastname) => console.log(`Hello, ${firstname} ${lastname}`);
hello3("디미", "김");

export let Le_sserafim = [
  { name: "김채원", age: 24 },
  { name: "사쿠라", age: 26 },  
  { name: "허윤진", age: 23 },  
  { name: "카즈하", age: 21 }  
];

Le_sserafim.push({ name: "홍은채", age: 18 });
console.log(Le_sserafim);

console.log(Le_sserafim.find(member => member.name === "김채원").name);

Le_sserafim.map(member => member.song = "Hot");
console.log(Le_sserafim);

const result = Le_sserafim.filter(member => member.age >= 19);
console.log(result);

export class Student {
  constructor(id, score) {
    this.id = id;
    this.score = score;
  }
  sum() {
    return this.score.reduce((a, b) => a + b, 0);
  }
  avg() {
    return this.sum() / this.score.length;
  }
  print() {
    console.log(`${this.id}번 학생 총점: ${this.sum()}, 평균: ${this.avg()}`);
  }
}

let s1 = new Student(1, [10, 20, 30]);
let s2 = new Student(2, [50, 60, 70]);
let s3 = new Student(3, [80, 90, 100]);

s1.print();
s2.print();
s3.print();
