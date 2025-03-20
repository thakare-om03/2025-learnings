console.log("this is the javascript asynchronous behaviour");
for (let index = 0; index < 10; index++) {
    console.log(index);
}
function asynchronous(){
    console.log("This prints after an interval of time");
}
setTimeout(() => {
    asynchronous();
}, 5000);