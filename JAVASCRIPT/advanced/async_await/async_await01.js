function fetchUserData() {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve({ name: "OM", url: "https://google.co.in" });
    }, 3000);
  });
}

async function getUserData() {
  try {
    console.log("Fetching user data...");
    const getdata = await fetchUserData();
    console.log(getdata);
    console.log("User data fetched successfully");
  } catch (error) {
    console.log("Error fetching data", error);
  }
}
getUserData();
