import axios from 'axios'

const url='https://jsonplaceholder.typicode.com/users';

const getUser=async()=>{
    try{
        const response = await axios.get(url);
        console.log(response)
        const result=response.data;
    
        result.forEach(element=>{
            console.log(`${element.id}:${element.name}`);
        });
    } catch(err) {
        console.error(err);
    }
}

getUser();