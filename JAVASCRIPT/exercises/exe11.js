// Task 1
function fetchUser() {
  return new Promise((resolve) =>
    setTimeout(() => resolve("User fetched"), 1000)
  );
}

function fetchPosts() {
  return new Promise((resolve) =>
    setTimeout(() => resolve("Posts fetched"), 1000)
  );
}

async function fetchAllData() {
  try {
    const [user, posts] = await Promise.all([fetchUser(), fetchPosts()]);
    console.log(user);
    console.log(posts);
  } catch (error) {
    console.log("Error occurred:", error);
  }
}

fetchAllData();

// Task 2
function fetchSuccess() {
  return new Promise((resolve) =>
    setTimeout(() => resolve("Success resolved"), 1000)
  );
}

function fetchFailure() {
  return new Promise((_, reject) =>
    setTimeout(() => reject("Failure rejected"), 1000)
  );
}

async function handlePromises() {
  try {
    const results = await Promise.all([fetchSuccess(), fetchFailure()]);
    console.log(results);
  } catch (error) {
    console.log("Error:", error);
  }
}

handlePromises();

// Task 3
function fetchWithTimeout(promise, timeout) {
  const timeoutPromise = new Promise((_, reject) =>
    setTimeout(() => reject("Timeout exceeded"), timeout)
  );
  return Promise.race([promise, timeoutPromise]);
}

function fetchData() {
  return new Promise((resolve) =>
    setTimeout(() => resolve("Data fetched"), 3000)
  );
}

fetchWithTimeout(fetchData(), 2000).then(console.log).catch(console.error);
fetchWithTimeout(fetchData(), 4000).then(console.log).catch(console.error);
