// 6. 콜백함수 문제
const add = (a, callback) => {
    console.log(a);
    let b = a + 10;
    setTimeout(() => {
        callback(b, mul);
    }, 0);
};

const mul = (a, callback) => {
    console.log(a);
    let b = a * 2;
    setTimeout(() => {
        callback(b, div); 
    }, 0); 
};

const div = (a) => {
    console.log(a);
    let b = a / 5;
    setTimeout(() => {
        console.log(b);
    }, 0);
};

add(10, mul);

// 7. Promise 문제
const add2 = (a) => {
    return new Promise((resolve) => {
        resolve(a + 10);
    });
};

const mul2 = (a) => {
    return new Promise((resolve) => {
        resolve(a * 2);
    });
};

const div2 = (a) => {
    return new Promise((resolve) => {
        resolve(a / 5);
    });
};

add2(10).then(mul2).then(div2).then(result => console.log(result));

// 8. async/await 문제
const calc = async () => {
    let result = await add2(10);
    result = await mul2(result);
    result = await div2(result);
    console.log(result);
};

calc();

// 9. module 문제
import { Le_sserafim, Student } from './assignment1.js';

Le_sserafim.forEach(member => console.log(`Hello, ${member.name} ${member.age}`));

let s1 = new Student(1, [10, 20, 30]);
let s2 = new Student(2, [50, 60, 70]);
let s3 = new Student(3, [80, 90, 100]);

s1.print();
s2.print();
s3.print();

// 10. axios 문제
import axios from 'axios';

var post_url = 'https://jsonplaceholder.typicode.com/posts/';
var user_url = 'https://jsonplaceholder.typicode.com/users/';

const getUserNameByPostId = async (postId) => {
    try {
        const postResponse = await axios.get(`${post_url}${postId}`);
        const userId = postResponse.data.userId;
        const userResponse = await axios.get(`${user_url}${userId}`);
        return userResponse.data.username;
    } catch (error) {
        console.error(error);
    }
};

getUserNameByPostId(1).then(username => console.log(username));
getUserNameByPostId(11).then(username => console.log(username));
