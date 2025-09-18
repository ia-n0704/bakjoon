/*class Animal
{
    constructor(name)
    {
        this.name=name;
    }
    say()
    {
        console.log(`${this.name}이 말을 한다.`);
    }
}

const a=new Animal('동물');
a.say();

class Dog extends Animal{
    say() {
        console.log(`${this.name}가 멍멍한다`);
    }
}

class Cat extends Animal{
    say() {
        console.log(`${this.name}가 야옹한다`);
    }
}

const animals=[new Dog('멍멍이'), new Cat('야옹이')]
animals.forEach(animal=>animal.say())


function test() {
    setTimeout(() => console.log("하나"),1000);
    setTimeout(() => console.log("두이"),999);
    setTimeout(() => console.log("서이"),998);
}

test();

function test2() {
  setTimeout(() => {
    console.log("하나2");
    setTimeout(() => {
      console.log("둘2");
      setTimeout(() => {
        console.log("셋2");
      }, 998);
    }, 999);
  }, 1000);
}
test2();

const promise=new Promise((resolve,regect) => {
    const result=true;
    if(result)
        resolve("작업 성공");
    else
        reject("작업 실패");
})

promise
.then((result)=>console.log(result));

const promise2 = (param) => {
    return new Promise((resolve, reject) => {
      if (param) {
        resolve("작업 성공2");
      } else {
        reject("작업 실패2");
      }
    })
  }
  
promise2(false)
.then((result) => console.log(result),
    (err) => console.error(err));

promise2(false)
.then((result) => console.log(result))
.catch((err) => console.error(err));

const promise3 = (taskname, timeout) => {
return new Promise((resolve, reject) => {
    setTimeout(() => {
    console.log(taskname);
    resolve();
    }, timeout);
});
}

promise3("하나", 500)
.then(() => promise3("둘", 300))
.then(() => promise3("셋", 100))
.then(() => console.log("끝"));

Promise.all([promise3("하나2",500),promise3("둘2",300),promise3("셋2",100)]).then(()=>console.log("끝2"))*/



/*const users = [
    { id: 3301, name: "홍길동" },
    { id: 3302, name: "홍길서" },
    { id: 3303, name: "홍길남" },
  ];
  
const getUsers = () => {
setTimeout(() => {
    console.log("작업 중");
    return users;
}, 1000);
}

const test = () => {
try {
    console.log("작업 시작");
    const result = getUsers();
    console.log("작업 완료");
    console.log(result);
    } catch(err) {
        console.error(err);
    }
}
const getUsers2 = () => {
return new Promise((resolve, reject) => {
    setTimeout(() => {
    console.log("작업 중");
    resolve(users);
    }, 1000);
});
}

const test2 = async() => {
try {
    console.log("작업 시작");
    const result = await getUsers2();
    console.log("작업 완료");
    console.log(result);
} catch(err) {
    console.error(err);
}
}

test2();

const hello = async() => {
return "hello";
}

hello().then(result => console.log(result));

const promise = (taskname, timeout) => {
return new Promise((resolve, reject) => {
    setTimeout(() => {
    resolve(taskname + " 완료");
    }, timeout);
});
}

const test3 = async() => {

let result = await promise("하나", 500);
console.log(result);

result = await promise("둘", 300);
console.log(result);

result = await promise("셋", 100);
console.log(result);
}

test3();

const users = [
    { id: 3301, name: "홍길동" },
    { id: 3302, name: "홍길서" },
    { id: 3303, name: "홍길남" },
];

const getUsers = () => {
    setTimeout(() => {
        console.log("작업 중");
        return users;
    }, 1000);
}

const test = () => {
    try {
        console.log("작업 시작");
        const result = getUsers();
        console.log("작업 완료");
        console.log(result);
    } catch(err) {
        console.error(err);
    }
}

const getUsers2 = () => {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            console.log("작업 중");
            resolve(users);
        }, 1000);
    });
}

const hello = async() => {
    return "hello";
}

hello().then(result => console.log(result));*/

const promise = (taskname, timeout) => {
return new Promise((resolve, reject) => {
    setTimeout(() => {
    resolve(taskname + " 완료");
    }, timeout);
});
}
const test3 = async() => {
    let result = await promise("하나", 500);
    console.log(result);

    result = await promise("둘", 300);
    console.log(result);

    result = await promise("셋", 100);
    console.log(result);
}
test3();
