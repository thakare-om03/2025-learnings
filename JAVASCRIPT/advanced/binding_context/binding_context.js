const person = {
    name : "Om",
    greet(){
        console.log(`Hi, my name is ${this.name}`)
    }
}

person.greet()

const greetFunction = person.greet
greetFunction()

const bindedGreet = person.greet.bind({name:"Messi"})
bindedGreet()