function getPostData() {
  return new Promise((resolve) => {
    setTimeout(() => {
        resolve("Post data fetched");
    }, 3000); 
  });
}
function getCommentData() {
  return new Promise((resolve) => {
    setTimeout(() => {
        resolve("Comment data fetched");
    }, 4000); 
  });
}

async function fetchData() {
    try {
        console.log("Fetching data")
        const [PostData, CommentData] = await Promise.all([getPostData(), getCommentData()])
        console.log(PostData)
        console.log(CommentData)
        console.log("Fetch complete")
    } catch (error) {
        console.log("Error fetching data", error)
    }
}
fetchData()