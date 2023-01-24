// var teachName="LS";




// if(teachName=="LS"){
//     let apples=1;
//     const height="160cm";
//     console.log("I have", apples, "apples");

// }

// const name="LS";
// let profession="programmer";
// var total=14;

// const list=["item 1", 2, "item  2", 3.14];

// const thing=null;//memory with nothing in it

// const notDefined=undefined;

// const getAge=function(){
//     return 32;
// };

// const obj={
//     "name":"Lin Su",
//     "profession":"student"
// // }
// function hello(){
//     return "hello linsu"
// }
// const greet=hello()
// console.log(greet)

// const hlo=()=>{
//     console.log("hello ls")
// }
// hlo()

// const hllo=()=>"hello from one line function"
// hllo()

// const newgreet=(name)=>{
//     console.log(`welcome ${name}`)
// }
// newgreet("sudalin")
// class Person{
//     constructor(name){
//         this.name=name 
//     }
//     greeting(){
//         console.log(`Hello from ${this.name}`)
//     }
//     setName(name){
//         this.name=name
//     }
// }

// const LS=new Person("lin su")

// LS.greeting()
// LS.setName("Da Lin")
// LS.greeting()

// fetch('https://swapi.dev/api/people/1/')
//     .then(response=>response.json())
//     .then(data=>{
//         console.log(data)
//     })
const name=document.getElementById("name");
const height=document.getElementById("height");
const eyecolor=document.getElementById("eyecolor");
const birthyear=document.getElementById("birthyear");

const bttn=document.querySelector(".getRandomCharacter");
    bttn.addEventListener('click',(e)=>{
    e.preventDefault()
    name.innerHTML='<em>Loading...</e>';
    height.innerHTML='<em>Loading...</e>';
    eyecolor.innerHTML='<em>Loading...</e>';
    birthyear.innerHTML='<em>Loading...</e>';

const randNum=Math.ceil(Math.random()*83);
fetch(`http://swapi.dev/api/people/${randNum}`)
    .then(response=>response.json())
    .then(charactor=>{
        console.log(charactor)
        name.innerHTML=charactor['name'];
        height.innerHTML=charactor['height'];
        eyecolor.innerHTML=charactor['eye_color'];
        birthyear.innerHTML=charactor['birth_year']
    })
})

$(document).ready(function(){
    console.log("jQuery is loaded")
})