function fetchData() {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      let success = true;
      if (success) {
        resolve("Data fetched successfully");
      } else {
        reject("Data fetch rejected");
      }
    }, 3000);
  });
}

fetchData()
.then((data)=>{
    console.log(data)
})
.catch((value)=>{
    console.log(value)
})
