function simulateAsyncTask() {
  console.log("task started");
  setTimeout(() => {
    console.log("task finished");
  }, 1);
}

function simulateMultipleTasks() {
  setTimeout(() => {
    console.log("Task started");
  }, 2);
  for (let i = 1; i <= 3; i++) {
    setTimeout(() => {
      console.log(`Task ${i} finished`);
    }, i * 1000); // Delay increases for each task (1s, 2s, 3s)
  }
}

function fetchDataWithCallback(callback) {
  setTimeout(() => {
    const data = "data fetched";
    console.log("data fetched successfully");
    callback(data);
  }, 2000);
}
function handledata(data) {
  console.log(`data handled successfully ${data}`);
}
simulateAsyncTask();
simulateMultipleTasks();
fetchDataWithCallback(handledata);
